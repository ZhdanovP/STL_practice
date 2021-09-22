#include "impl.h"
#include <vector>
#include <stack>

const std::vector<std::pair<char, char>> brackets {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}
};

enum SymbolType {
    STOpen,
    STClose,
    STRegular
};

SymbolType getType( const char a, char &checkTop )
{
    for(auto pair : brackets)
    {
        if( pair.first == a)
        {
            return STOpen;
        }
        else if( pair.second == a)
        {
            checkTop = pair.first;
            return STClose;
        }
    }
    return STRegular;
}

bool isValid(const std::string& source)
{
    std::stack<char> buffer;
    
    for(char c : source )
    {
        char checkTop;
        switch ( getType( c, checkTop ) )
        {
            case STOpen: 
                buffer.push( c );
            break;
            case STClose:
                if( !buffer.empty() && checkTop == buffer.top() )
                {
                    buffer.pop();
                }
                else
                {
                    return false;
                }
            break;
            default:
            break;
        }
    }
    
    return buffer.empty();
}