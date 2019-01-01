//
// Created by xinmei365 on 2019/1/1.
//
#include "iostream"
#include "pthread.h"
#include "unistd.h"
#include "cstdlib"
using namespace std;

#define NUM_THREADS 5

struct thread_data
{
    int thread_id;
    char *message;
};

void* say_hello(void* threadid)
{
    int tid = *((int*)threadid);
    cout << "Hello world: " <<  tid << endl;
    //return 0;
    pthread_exit(NULL);
}
void *print_hello(void *threadarg)
{
    sleep(1);
    struct thread_data *my_data;
    my_data = (struct thread_data*)threadarg;
    cout << "Thread ID:" << my_data->thread_id << endl;
    cout << "Message:  " << my_data->message << endl;

    pthread_exit(NULL);
}
int mainth1()
{
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; ++i)
    {
        indexes[i] = i;
        td[i].thread_id = i;
        td[i].message = (char*)"This is a message of i";
        //int ret = pthread_create(&tids[i], NULL, say_hello, (void*)&(indexes[i]));
        int ret = pthread_create(&tids[i], NULL, print_hello, (void*)&(td[i]));
        if (ret != 0)
        {
            cout << "pthread_create failed: " << ret << endl;
            exit(-1);
        }
    }

    pthread_exit(NULL);
}


