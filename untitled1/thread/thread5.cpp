//
// Created by xinmei365 on 2019/1/16.
//

#include <iostream>
#include <atomic>
#include <vector>
#include <thread>
#include <sstream>
using namespace std;

std::atomic<bool> read_flag(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count1m(int i)
{
    while (!read_flag)
    {
        cout <<  this_thread::get_id() << endl;
    }
    for (int i=0; i<1000000; i++);
    if (!winner.test_and_set())
        std::cout << this_thread::get_id() << " winner: " << i << std::endl;
}

int mainthread5()
{
    std::vector<std::thread> ths;
    for (int i=0; i<10; i++)
        ths.push_back(std::thread(count1m, i));
    read_flag = true;
    for (int i=0; i<10; i++)
        ths[i].join();
    return 0;
}