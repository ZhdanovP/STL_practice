#include "maintest.h"
#include "impl.h"

using namespace ::testing;

/**
 You must implement a conversion from 100-point grade system to 5-point system.

 Example: 0-29 – 1;  30-49 – 2;
        50-69 – 3; 70-89 – 4;
        90+ - 5;
 */

TEST(Convertor, convertGrade)
{
    EXPECT_EQ(convertGrade(0), 1);
    EXPECT_EQ(convertGrade(29), 1);

    EXPECT_EQ(convertGrade(30), 2);
    EXPECT_EQ(convertGrade(49), 2);

    EXPECT_EQ(convertGrade(50), 3);
    EXPECT_EQ(convertGrade(69), 3);

    EXPECT_EQ(convertGrade(70), 4);
    EXPECT_EQ(convertGrade(89), 4);

    EXPECT_EQ(convertGrade(90), 5);
    EXPECT_EQ(convertGrade(91), 5);
    EXPECT_EQ(convertGrade(99), 5);

    EXPECT_EQ(convertGrade(100), 5);
    EXPECT_EQ(convertGrade(200), 5);
    EXPECT_EQ(convertGrade(300), 5);
}
