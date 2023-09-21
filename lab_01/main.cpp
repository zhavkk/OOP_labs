#include <iostream>
#include <gtest/gtest.h>
#include "func.h"
TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(func("1fds412fds2gsd")=="1 412 2 ");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(func("")=="");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(func("1234124fdsfdsfsd")=="1234124 ");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(func("d11zz21")=="11 21 ");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(func("d12zz52d52")=="12 52 52 ");
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(func("7qweRTUFFGi12b4")=="7 12 4 ");
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(func("~!!~!~!~!!!~!~!@#$%^&*()_-=~!~!~!~!")=="");
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(func("~!!~!~!~!!!~!~!@1#$2%^3&*()_-=~!~!~!~!0")=="1 2 3 0 ");
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
