//
// Created by xinmei365 on 2019/1/2.
//

//#include "googletest/googletest/include/gtest/gtest-typed-test.h"
//#include "googletest/googletest/include/gtest/gtest.h"

#include "gtest/gtest.h"
//int gtest_add(int a, int b)
//{
//    return a+b;
//}
//
//TEST(test1, c1)
//{
//    EXPECT_EQ(3, gtest_add(1, 2));
//}
//GTEST_API_ int main(int argc, char ** argv)
//{
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
#include <iostream>
using namespace std;

int &put(int n);
int vals[10];
int error=-1;
//int mainm2()
//{
//    put(0)=10; //以put(0)函数值作为左值，等价于vals[0]=10;
//    put(9)=20; //以put(9)函数值作为左值，等价于vals[9]=20;
//    cout<<vals[0];
//    cout<<vals[9];
//
//    return 0;
//}

int fn1()
{
    printf( "next.n" );
    return 0;
}
int fn2()
{
    printf( "executed " );
    return 0;
}
int fn3()
{
    printf( "is " );
    return 0;
}
int fn4()
{
    printf( "This " );
    return 0;
}
int mainm3( void )
{
    string str("zhanglin");
    printf( "This is executed first.n" );

    return 0;
}



