#include "maintest.h"

using namespace ::testing;

TEST(GradeAdaptor, GranparentsAreVeryProud)
{
    EXPECT_EQ(::adaptNewGradesToGrandparents(90), 5);
    EXPECT_EQ(::adaptNewGradesToGrandparents(92), 5);
    EXPECT_EQ(::adaptNewGradesToGrandparents(100), 5);
}

TEST(GradeAdaptor, GranparentsAreHappy)
{
    EXPECT_EQ(::adaptNewGradesToGrandparents(70), 4);
    EXPECT_EQ(::adaptNewGradesToGrandparents(81), 4);
    EXPECT_EQ(::adaptNewGradesToGrandparents(89), 4);
}

TEST(GradeAdaptor, GranparentsAreNotSoHappy)
{
    EXPECT_EQ(::adaptNewGradesToGrandparents(50), 3);
    EXPECT_EQ(::adaptNewGradesToGrandparents(58), 3);
    EXPECT_EQ(::adaptNewGradesToGrandparents(69), 3);
}

TEST(GradeAdaptor, GranparentsAreNotHappy)
{
    EXPECT_EQ(::adaptNewGradesToGrandparents(30), 2);
    EXPECT_EQ(::adaptNewGradesToGrandparents(40), 2);
    EXPECT_EQ(::adaptNewGradesToGrandparents(49), 2);
}

TEST(GradeAdaptor, GranparentsAreAngry)
{
    EXPECT_EQ(::adaptNewGradesToGrandparents(0), 1);
    EXPECT_EQ(::adaptNewGradesToGrandparents(5), 1);
    EXPECT_EQ(::adaptNewGradesToGrandparents(29), 1);
}

TEST(GradeAdaptor, GranparentsAreConfused)
{
    EXPECT_EQ(::adaptNewGradesToGrandparents(-1), 0);
    EXPECT_EQ(::adaptNewGradesToGrandparents(101), 0);
    EXPECT_EQ(::adaptNewGradesToGrandparents(-8), 0);
    EXPECT_EQ(::adaptNewGradesToGrandparents(201), 0);
}
