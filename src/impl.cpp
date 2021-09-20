#include "impl.h"

#include <algorithm> // std::find
#include <stack>
#include <string>
#include <vector>

const std::vector<std::pair<char, char>> brackets{ { '(', ')' }, { '[', ']' }, { '{', '}' } };

static bool isOpenBracket( const char symbol );
static bool isCloseBracket( const char symbol );
static bool isPairedBrackets( std::pair<char, char> bracketPair );

bool isValid( const std::string& source )
{
   std::stack<char> stack;

   for ( const char& symbol : source )
   {
      if ( isOpenBracket( symbol ) )
      {
         stack.push( symbol );
         continue;
      }

      if ( isCloseBracket( symbol ) )
      {
         if ( stack.empty() ) // no bracket to pair with
         {
            return false;
         }

         if ( isPairedBrackets( { stack.top(), symbol } ) )
         {
            stack.pop();
         }
         else
         {
            return false;
         }
      }
   }

   return stack.empty();
}

static bool isOpenBracket( const char symbol )
{
   for ( const auto& [first, second] : brackets )
   {
      if ( symbol == first )
      {
         return true;
      }
   }

   return false;
}

static bool isCloseBracket( const char symbol )
{
   for ( const auto& [first, second] : brackets )
   {
      if ( symbol == second )
      {
         return true;
      }
   }

   return false;
}

static bool isPairedBrackets( std::pair<char, char> bracketPair )
{
   if ( std::find( brackets.begin(), brackets.end(), bracketPair ) != brackets.end() )
   {
      return true;
   }

   return false;
}
