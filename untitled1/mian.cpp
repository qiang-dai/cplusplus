//
// Created by xinmei365 on 2019/1/2.
//

//#include "googletest/googletest/include/gtest/gtest-typed-test.h"
//#include "googletest/googletest/include/gtest/gtest.h"

#include "gtest/gtest.h"
int gtest_add(int a, int b)
{
    return a+b;
}

TEST(test1, c1)
{
    EXPECT_EQ(3, gtest_add(1, 2));
}
GTEST_API_ int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
