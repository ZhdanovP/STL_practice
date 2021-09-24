#include "maintest.h"

using namespace ::testing;

const std::map<int, std::pair<int, int>> rules_test = {
   {1, {0 , 29} },
   {2, {30, 49} },
   {3, {50, 69} },
   {4, {70, 89} },
   {5, {90, 101} }
};



TEST(Convertor, Mark_1)
{
   auto it = rules_test.find(1);
   for (int i = it->second.first; i <= it->second.second; ++i)
   {
      std::stringstream cin;
      cin << i;
      EXPECT_TRUE(Convertor(cin.str()) == "1");
   }
}
TEST(Convertor, Mark_2)
{
   auto it = rules_test.find(2);
   for (int i = it->second.first; i <= it->second.second; ++i)
   {
      std::stringstream cin;
      cin << i;
      EXPECT_TRUE(Convertor(cin.str()) == "2");
   }
}
TEST(Convertor, Mark_3)
{
   auto it = rules_test.find(3);
   for (int i = it->second.first; i <= it->second.second; ++i)
   {
      std::stringstream cin;
      cin << i;
      EXPECT_TRUE(Convertor(cin.str()) == "3");
   }
}
TEST(Convertor, Mark_4)
{
   auto it = rules_test.find(4);
   for (int i = it->second.first; i <= it->second.second; ++i)
   {
      std::stringstream cin;
      cin << i;
      EXPECT_TRUE(Convertor(cin.str()) == "4");
   }
}
TEST(Convertor, Mark_5)
{
   auto it = rules_test.find(5);
   for (int i = it->second.first; i <= it->second.second; ++i)
   {
      std::stringstream cin;
      cin << i;
      EXPECT_TRUE(Convertor(cin.str()) == "5");
   }
}

