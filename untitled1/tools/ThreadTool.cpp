//
// Created by xinmei365 on 2019/1/16.
//

#include "ThreadTool.h"

#include "iostream"

void fun1(int slp)
{
    printf(" hello, fun1! %d\n", std::this_thread::get_id());
    if (slp > 0)
    {
        printf(" ===========fun1 sleep %d =========== %d\n", slp, this_thread::get_id());
        this_thread::sleep_for(chrono::milliseconds(slp));
    }
}

struct gfun
{
    int operator() (int n)
    {
        printf("%d hello, gfun ! %d\n", n, this_thread::get_id());
        return 42;
    }
};

class A
{
public:
    static int Afun(int n = 0)
    {
        cout << n << " hello, Afun ! " << this_thread::get_id() << std::endl;
        return n;
    }

    static string Bfun(int n, string str, char c)
    {
        cout << n << " hello, Bfun ! " << str.c_str() << " " << (int)c << " " << this_thread::get_id() << endl;
        return str;
    }
};

int mainxxx()
{
    try
    {
        ThreadPool executor{50};
        A a;
        future<void> ff = executor.commit(fun1, 0);
        future<int> fg = executor.commit(gfun{}, 0);
        future<int> gg = executor.commit(a.Afun, 9999);
        future<string> gh = executor.commit(A::Bfun, 9998, "multi args", 123);
        future<string> fh = executor.commit([]()->string{
            cout << "hello, fh ! " << this_thread::get_id() << endl;
            return "hello, fh ret!";
        });
        cout << "=============sleep==============" << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::microseconds(900));

        for(int i = 0; i < 50; i++)
        {
            executor.commit(fun1, i*100);
        }

        cout << "===============commit all =============== " << this_thread::get_id()
        << "idl size = " << executor.idlCount() << endl;

        cout << "===============sleep  ====================" << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::seconds(3));

        ff.get();
        cout << fg.get() << " " << fh.get().c_str() << " " << this_thread::get_id() << endl;

        cout << "====================sleep =============== " << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::seconds(3));

        cout << "=================fun1,55 ================ " << this_thread::get_id() << endl;
        executor.commit(fun1, 55).get();

        cout << "end..." << this_thread::get_id() << endl;

        ThreadPool pool(4);
        vector<future<int> > results;
        for (int i = 0; i < 8; ++i) {
            results.emplace_back(
                    pool.commit([i] {
                        cout << " hello " << i << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        cout << " world" << i << endl;
                        return i*i;
                    })
                    );
        }
        cout << "==========commit all2 ========= " << this_thread::get_id() << endl;
        for (auto && result : results)
        {
            cout << result.get() << ' ';
        }
        cout << endl;
        return 0;
    }
    catch(exception e)
    {
        cout << " some unhappy happend... " << this_thread::get_id() << e.what() << endl;
    }
}