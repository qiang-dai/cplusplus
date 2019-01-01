#include <thread>

class thread_guard
{
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
        t(t_)
    {}
    ~thread_guard()
    {
        if(t.joinable())    //一个线程只能被join一次
        {
            t.join();      //放在析构函数里自动做
        }
    }
    thread_guard(thread_guard const&)=delete;    //不需要拷贝构造
    thread_guard& operator=(thread_guard const&)=delete; //不需要赋值
};

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{}


void f()
{
    int some_local_state;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);    //封装thread 对象

    do_something_in_current_thread();
}

int main111()
{
    f();
}
