#include "maintest.h"

using namespace ::testing;

TEST(Convertor, GetOneMin)
{
    auto converted = convert(0);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 1);
}

TEST(Convertor, GetOneMax)
{
    auto converted = convert(29);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 1);
}

TEST(Convertor, GetTwoMin)
{
    auto converted = convert(30);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 2);
}

TEST(Convertor, GetTwoMax)
{
    auto converted = convert(49);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 2);
}

TEST(Convertor, GetThreeMin)
{
    auto converted = convert(50);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 3);
}

TEST(Convertor, GetThreeMax)
{
    auto converted = convert(69);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 3);
}

TEST(Convertor, GetFourMin)
{
    auto converted = convert(70);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 4);
}

TEST(Convertor, GetFourMax)
{
    auto converted = convert(89);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 4);
}

TEST(Convertor, GetFiveMin)
{
    auto converted = convert(90);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 5);
}

TEST(Convertor, GetFiveMax)
{
    auto converted = convert(100);
    ASSERT_TRUE(converted.first);
    EXPECT_EQ(converted.second, 5);
}

TEST(Convertor, Overload)
{
    auto converted = convert(150);
    ASSERT_FALSE(converted.first);
    EXPECT_EQ(converted.second, 0);
}
