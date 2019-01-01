//
// Created by xinmei365 on 2019/1/1.
//

#include "iostream"
#include "thread"

std::thread::id main_thread_id = std::this_thread::get_id();

void hello()
{
    std::cout << "Hello Concurrent World\n" << std::endl;
    if (main_thread_id == std::this_thread::get_id())
    {
        std::cout << "This is main thread.\n" << std::endl;
    } else {
        std::cout << "This is not the main thread.\n" << std::endl;
    }
}

void pause_thread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n" << std::endl;
}

int mainth41()
{
    std::cout << []()->int {int  z = 3+5; return z + 2;} << " over lambda" << std::endl;
    std::thread t(hello);
    std::cout << t.hardware_concurrency() << std::endl;
    std::cout << "native_handle " << t.native_handle() << std::endl;
    t.join();
    std::thread a(hello);
    a.detach();
    std::thread threads[5];

    std::cout << "spawning 5 threads..." << std::endl;
    for (int i = 0; i < 5; i++)
    {
        threads[i] = std::thread(pause_thread, i+1);
    }
    std::cout << "Done spawning threads. Now waiting for them to join:\n" << std::endl;
    for(auto &thread : threads)
    {
        thread.join();
    }
    std::cout << "All threads joined!\n" << std::endl;
}