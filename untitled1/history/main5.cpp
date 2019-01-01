#include <stdio.h>
#include <cstdlib>
#include "../Child.h"
#include <stdio.h>
#include <pthread.h>
#include <boost/scoped_ptr.hpp>
#include "boost/scoped_array.hpp"
#include "boost/scoped_ptr.hpp"

int main51(int argc, char *argv[]) {
    int first = 0;
    int *p0 = (int *) malloc(1024);
    int *p1 = (int *) malloc(1024 * 1024);
    int *p2 = (int *) malloc(512 * 1024 * 1024);
    int *p3 = (int *) malloc(1024 * 1024 * 1024);
    //printf("main  =%p \nprintf=%p\n", main, printf);
    printf("malloc=%p\n", malloc);
    printf("first =%p\n", &first);
    printf("p0    =%p\np1    =%p\np2    =%p\np3    =%p\n", p0, p1, p2, p3);
    //getchar();
    return 0;
}


pthread_mutex_t mutext2;
//int arr[] = new int[5]{0};
int **arr = new int*[10];
int pos = 0;

int fib(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return fib(n-1) + fib(n-2);
}
void *thread_proc(void *param) {
    pthread_mutex_lock(&mutext2);
    int first = 0;
    int *p0 = (int*)malloc(1024);
    int *p1 = (int*)malloc(1024 * 1024);
    arr[pos++] = &first;

    printf("(0x%x): first=%p\n", pthread_self(), &first);
    printf("(0x%x): p0   =%p\n", pthread_self(), p0);
    printf("(0x%x): p1   =%p\n\n", pthread_self(), p1);
    pthread_mutex_unlock(&mutext2);

//    for(int i = 0; i< 10000; i++)
//    {
//        Child *c = new Child();
//        c->parent_;
//    }

//    fib(20);
    return 0;
}

#define N 5

int main52(int argc, char *argv[]) {
    int first = 0;
    int i = 0;
    void *ret = NULL;
    pthread_t tid[N] = {0};
    printf("in main, first    =%p\n", &first);
    for (i = 0; i < N; i++) {
        pthread_create(tid + i, NULL, thread_proc, NULL);
        sleep(1);
    }
    for (i = 0; i < N; i++) {
        pthread_join(tid[i], &ret);
    }

    for(int i = 0; i < N - 1; i++) {
        printf("diff of first: %d\n", arr[i] - arr[i+1]);
    }
    return 0;
}

int main55() {
    boost::scoped_array<int> pia(new int[10]);
    boost::scoped_array<int> pia2(new int[10]());
    //int *pia = new int[10];
    //int *pia2= new int[10]();
//    string *psa = new string[10];
//    string *psa2= new string[10]{};

    //char *cp = new char[0];
    boost::scoped_ptr<char> cp(new char[0]);
    //delete []pia;

    const char *pc = "a very long literal string";
    //boost::scoped_ptr<char> pc(new "a very long literal string");
    const size_t len = strlen(pc) + 1;
    for(size_t ix = 0; ix != 1000000; ++ix) {
        char *pc2 = new char[len];
        strncpy(pc2, pc, len);
        delete pc2;
    }

    int b = 3;
    int c = 4;
    int const *p = &b;
    //boost::scoped_ptr<int> p3(&b);
    //*p = 5;
    int * const p2 = &b;
    //p2 = &c;
    const int *const (*f())[];
    //++(b++);
    ++(++b);
    (++b)++;
    //b++++;
    //++b++;
    ((++b)++)+c;

    int a[2][3];

    boost::scoped_array<string> psa(new string[10]);
    boost::scoped_array<string> psa2(new string[10]());
    boost::scoped_array<string> psa22(new string[10]{"abc"});
    boost::scoped_ptr<string> psa3(new string("hello world"));

}
int get_array() {
    //a -> a[0]  &a[0]
    //a === (*p)[3]
    char **p1;
    char *p2[2];
    char (*p22)[2];
    //p22 = p2;
    char p3[2][3];
    char (*p4)[3];

    //p1 = p3;
}

