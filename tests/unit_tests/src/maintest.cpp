#include "maintest.h"

using namespace ::testing;

TEST(Convertor, Edge)
{
    EXPECT_EQ(::convert100pointTo5(1), 1);
    EXPECT_EQ(::convert100pointTo5(29), 1);

    EXPECT_EQ(::convert100pointTo5(30), 2);
    EXPECT_EQ(::convert100pointTo5(49), 2);

    EXPECT_EQ(::convert100pointTo5(50), 3);
    EXPECT_EQ(::convert100pointTo5(69), 3);

    EXPECT_EQ(::convert100pointTo5(70), 4);
    EXPECT_EQ(::convert100pointTo5(89), 4);

    EXPECT_EQ(::convert100pointTo5(90), 5);
    EXPECT_EQ(::convert100pointTo5(100), 5);    
}

TEST(Convertor, Incorrect)
{
    EXPECT_EQ(::convert100pointTo5(-10), 0);
    EXPECT_EQ(::convert100pointTo5(110), 0);
}
/*
TEST(Convertor, AllValues)
{
    for (int i = 1; i<=29; i++)
        EXPECT_EQ(::convert100pointTo5(i), 1);
    for (int i = 30; i<=49; i++)
        EXPECT_EQ(::convert100pointTo5(i), 2);
    for (int i = 50; i=69; i++)
        EXPECT_EQ(::convert100pointTo5(i), 3);
    for (int i = 70; i<=89; i++)
        EXPECT_EQ(::convert100pointTo5(i), 4);
    for (int i = 90; i<=100; i++)
        EXPECT_EQ(::convert100pointTo5(i), 5);              
}*/
