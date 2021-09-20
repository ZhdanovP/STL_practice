#include "impl.h"

#include <algorithm> // std::find
#include <stack>
#include <string>
#include <vector>

const std::vector<std::pair<char, char>> brackets{ { '(', ')' }, { '[', ']' }, { '{', '}' } };

static bool isOpeningBracket( const char symbol );
static bool isClosingBracket( const char symbol );
static bool isPairedBrackets( const std::pair<char, char> bracketPair );

bool isValid( const std::string& source )
{
   std::stack<char> buffer;

   for ( const char& symbol : source )
   {
      if ( isOpeningBracket( symbol ) )
      {
         buffer.push( symbol );
         continue;
      }

      if ( isClosingBracket( symbol ) )
      {
         if ( buffer.empty() ) // no bracket to pair with
         {
            return false;
         }

         if ( isPairedBrackets( { buffer.top(), symbol } ) )
         {
            buffer.pop();
         }
         else
         {
            return false;
         }
      }
   }

   return buffer.empty();
}

static bool isOpeningBracket( const char symbol )
{
   for ( const auto& [opening, closing] : brackets )
   {
      if ( symbol == opening )
      {
         return true;
      }
   }

   return false;
}

static bool isClosingBracket( const char symbol )
{
   for ( const auto& [opening, closing] : brackets )
   {
      if ( symbol == closing )
      {
         return true;
      }
   }

   return false;
}

static bool isPairedBrackets( const std::pair<char, char> bracketPair )
{
   if ( std::find( brackets.begin(), brackets.end(), bracketPair ) != brackets.end() )
   {
      return true;
   }

   return false;
}
