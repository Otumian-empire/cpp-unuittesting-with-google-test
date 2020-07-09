#include <gtest/gtest.h>
#include "mathsy.hpp"

TEST(CalcTest, Add)
{
    ASSERT_EQ(2, add(1,1));
    ASSERT_EQ(8, add(4,4));
    ASSERT_EQ(21, add(15,6));
}

TEST(CalcTest, Sub)
{
    ASSERT_EQ(5, sub(2,-3));
    ASSERT_EQ(9, sub(6,-3));
    ASSERT_EQ(5, sub(2,-3));
}
    
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
