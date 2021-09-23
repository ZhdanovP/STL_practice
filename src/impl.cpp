#include "impl.h"
#include <vector>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

bool isValid(const std::string& source)
{
   std::stack<char> stack;

   std::for_each(source.begin(), source.end(), [&stack](const char& ch)
      {
         auto it_pair = std::find_if(brackets.begin(), brackets.end(), [ch](const std::pair<char, char>& pair)
            {
               return pair.first == ch || pair.second == ch;
            });

         if (it_pair != brackets.end())
         {
            if (ch == it_pair->first) //open bracket
            {
               stack.push(ch);
            }
            else if (!stack.empty() && stack.top() == it_pair->first) // close bracket
            {
               stack.pop();
            }
            else
            {
               stack.push(ch); //to make error at end
            }
         }
      });
   return stack.empty();
}
