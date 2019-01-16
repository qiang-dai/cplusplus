//
// Created by xinmei365 on 2019/1/16.
//

#ifndef UNTITLED1_THREADTOOL_H
#define UNTITLED1_THREADTOOL_H


#include "vector"
#include "queue"
#include "thread"
#include "atomic"
#include "condition_variable"
#include "future"
#include "functional"
#include "stdexcept"

#define MAX_THREAD_NUM 256
using namespace std;
class ThreadPool
{
    using Task = function<void()>;
    vector<thread> pool;
    queue<Task> tasks;
    mutex m_lock;
    condition_variable cv_task;
    atomic<bool> stoped;
    atomic<int> idlThrNum;

public:
    inline ThreadPool(unsigned short size = 4) : stoped{false}
    {
        idlThrNum = size < 1 ? 1 : size;
        for(size = 0; size < idlThrNum; ++size)
        {
            pool.emplace_back(
                    [this]
                    {
                        while(!this->stoped)
                        {
                            function<void()> task;
                            {
                                unique_lock<mutex> lock{this->m_lock};
                                this->cv_task.wait(lock,
                                        [this]
                                        {
                                            return this->stoped.load() || !this->tasks.empty();
                                        }
                                        );
                                if (this->stoped && this->tasks.empty())
                                {
                                    return;
                                }
                                task = std::move(this->tasks.front());
                                this->tasks.pop();
                            }
                            idlThrNum--;
                            task();
                            idlThrNum++;
                        }
                    });
        }
    }
    inline ~ThreadPool()
    {
        stoped.store(true);
        cv_task.notify_all();
        for(thread& th : pool)
        {
            if (th.joinable())
            {
                th.join();
            }
        }
    }

public:
    template <class F, class ...Args>
            auto commit(F&& f, Args&&... args) -> future<decltype(f(args...))>
    {
        if (stoped.load())
        {
            throw runtime_error("commit on ThreadPool is stopped.");
        }
        using RetType = decltype(f(args...));
        auto task = std::make_shared<packaged_task<RetType()> >(
                bind(forward<F>(f), forward<Args>(args)...)
                );
        future<RetType> future = task->get_future();
        {
            lock_guard<mutex> lock{m_lock};
            tasks.emplace(
                    [task]()
                    {
                        (*task)();
                    }
                    );
        }
        cv_task.notify_one();

        return future;
    }
    int idlCount() {return idlThrNum; }
};

#endif //UNTITLED1_THREADTOOL_H
