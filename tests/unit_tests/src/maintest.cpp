#include "impl.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

TEST( Convertor, LowerBounds )
{
   EXPECT_EQ( convertTo5PointGrade( 0 ), 1 );
   EXPECT_EQ( convertTo5PointGrade( 1 ), 1 );

   EXPECT_EQ( convertTo5PointGrade( 30 ), 2 );
   EXPECT_EQ( convertTo5PointGrade( 31 ), 2 );

   EXPECT_EQ( convertTo5PointGrade( 50 ), 3 );
   EXPECT_EQ( convertTo5PointGrade( 51 ), 3 );

   EXPECT_EQ( convertTo5PointGrade( 70 ), 4 );
   EXPECT_EQ( convertTo5PointGrade( 71 ), 4 );

   EXPECT_EQ( convertTo5PointGrade( 90 ), 5 );
   EXPECT_EQ( convertTo5PointGrade( 91 ), 5 );
}

TEST( Convertor, UpperBounds )
{
   EXPECT_EQ( convertTo5PointGrade( 28 ), 1 );
   EXPECT_EQ( convertTo5PointGrade( 29 ), 1 );

   EXPECT_EQ( convertTo5PointGrade( 48 ), 2 );
   EXPECT_EQ( convertTo5PointGrade( 49 ), 2 );

   EXPECT_EQ( convertTo5PointGrade( 68 ), 3 );
   EXPECT_EQ( convertTo5PointGrade( 69 ), 3 );

   EXPECT_EQ( convertTo5PointGrade( 88 ), 4 );
   EXPECT_EQ( convertTo5PointGrade( 89 ), 4 );

   EXPECT_EQ( convertTo5PointGrade( 99 ), 5 );
   EXPECT_EQ( convertTo5PointGrade( 100 ), 5 );
}

TEST( Convertor, MiddleValue )
{
   EXPECT_EQ( convertTo5PointGrade( 16 ), 1 );
   EXPECT_EQ( convertTo5PointGrade( 41 ), 2 );
   EXPECT_EQ( convertTo5PointGrade( 62 ), 3 );
   EXPECT_EQ( convertTo5PointGrade( 79 ), 4 );
   EXPECT_EQ( convertTo5PointGrade( 93 ), 5 );
}

TEST( Convertor, Beyond100 )
{
   EXPECT_EQ( convertTo5PointGrade( 101 ), 5 );
   EXPECT_EQ( convertTo5PointGrade( 150 ), 5 );
   EXPECT_EQ( convertTo5PointGrade( 200 ), 5 );
   EXPECT_EQ( convertTo5PointGrade( 255 ), 5 );
}
