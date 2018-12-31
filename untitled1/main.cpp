#include "stdlib.h"
#include "stdio.h"
#include "string"
#include "iostream"

using namespace std;

void code()
{
    struct TRef
    {
        char& r;
        char c;
    };

    printf("sizeof(TRef) = %d\n", sizeof(TRef));
}
int main1() {
    code();
    return 0;
}

//当操作数是结构类型时，sizeof是其成员类型的总字节数，包括补充字节在内。
struct TRef
{
    char& r;
};

int calc(char a[10])
{
    printf("with a[10], sizeof(a) = %d\n",sizeof(a));
    return 0;
}

char foo()
{
    printf("foo() has been called.\n");
    return 'a';
}

void foo2() { }


struct S1
{
    char c;
    int i;
};
struct S2
{;
    int i;
    char c;
};

struct S3
{
    char c1;
    S1 s;
    char c2;
};

class A
{
public:
    int b;
    float c;
    char d;
};

class A2
{
public:
    static int a;
    int b;
    float c;
    char d;
};

//http://www.blogjava.net/majianan/archive/2006/08/20/64664.html
int main00(int argc, char* argv[])
{
    //sizeof操作符以字节形式给出了其操作数的存储大小。
    char c = 'c';
    char& rc = c;
    TRef ref = { c };
    //sizeof操作符应用在引用类型上的时候，返回的是包含被引用对象所需的内存长度（即被引用对象的大小）。
    TRef *p = &ref;

    printf("sizeof(c) = %d\n", sizeof(c));
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(char16_t) = %d\n", sizeof(char16_t));
    printf("sizeof(char32_t) = %d\n", sizeof(char32_t));
    printf("sizeof(char&) = %d\n", sizeof(char&));  // ==> sizeof(char)
    printf("sizeof(rc) = %d\n", sizeof(rc));

    printf("sizeof(TRef) = %d\n", sizeof(TRef));    // 注意这里!
    printf("sizeof(ref) = %d\n", sizeof(ref));      // 注意这里!
    printf("sizeof(ref.r) = %d\n", sizeof(ref.r));
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("sizeof(TRef&) = %d\n", sizeof(TRef &));

    printf("sizeof(void*) = %d\n", sizeof(void*));
    char a[10] = {"hellow"};
    printf("out calc %d\n", sizeof(a)); // ok. 输出10
    calc(a);

    size_t sz = sizeof( foo() );   // foo() 的返回值类型为char，所以sz = sizeof(char)，
    // 但函数foo()并不会被调用
    printf("sizeof( foo() ) = %d\n", sz);

    //sizeof( foo );     // error
    //sizeof( foo2() );  // error
    struct S
    {
        unsigned int f1 : 1;
        unsigned int f2 : 5;
        unsigned int f3 : 12;
    };
    //sizeof( S.f1 );   // error

    int n;
    n = 10;        // n动态赋值
    char ary[n];   // C99也支持数组的动态定义
    printf("%d\n", sizeof(ary)); // ok. 输出10


    char* pc = "abc";
    int* pi;
    string* ps;
    char** ppc = &pc;
    void (*pf)(); // 函数指针
    cout << sizeof( pc ) << endl; // 结果为4
    cout << sizeof( pi ) << endl; // 结果为4
    cout << sizeof( ps ) << endl; // 结果为4
    cout << sizeof( ppc) << endl; // 结果为4
    cout << sizeof( pf ) << endl; // 结果为4

    char a1[] = "abc";
    int a2[3];
    cout << "sizeof a1 " << sizeof( a1 ) << endl; // 结果为4，字符 末尾还存在一个NULL终止符
    cout << "sizeof a2 " << sizeof( a2 ) << endl; // 结果为3*4=12（依赖于int）

    string st1("blog.sina.com.cn");
    string st2("majianan");
    string st3;
    string *ps2 = &st1;
    cout << "st1: " << sizeof(st1) << endl;
    cout << "st2: " << sizeof(st2) << endl;
    cout << "st3: " << sizeof(st3) << endl;
    cout << "ps: " << sizeof(ps) << endl;
    cout << "*ps2: " << sizeof(*ps2) << endl;

    cout << "short:\t" << sizeof(short) << endl;
    cout << "short*:\t" << sizeof(short*) << endl;
    cout << "short&:\t" << sizeof(short&) << endl;
    cout << "short[4]:\t" << sizeof(short[4]) << endl;
    cout << "int&:\t" << sizeof(int&) << endl;

    cout << "sizeof S1 " << sizeof(S1) << endl;
    cout << "sizeof S2 " << sizeof(S2) << endl;
    size_t pos = offsetof(S2, c);// pos等于4
    cout << "S2 pos= " << pos << endl;
    pos = offsetof(S1, c);// pos等于4
    cout << "S1 pos= " << pos << endl;

    cout << "sizeof S3= " << sizeof(S3) << endl;

    cout << "sizeof A=  " << sizeof(A) << endl;
    cout << "sizeof A2= " << sizeof(A2) << endl;

    cout << a1 << ", " << ppc << endl;

    return 0;
}