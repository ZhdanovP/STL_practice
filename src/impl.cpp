#include "impl.h"

BeerBrand BeerOrganizer::next()
{
    return static_cast<BeerBrand>(static_cast<int>(current) + 1);
}

BeerBrand BeerOrganizer::operator()()
{
    current = next();

    if (current == BeerBrand::Max)
    {
        current = BeerBrand::None;
        current = next();
    }
    return current;
}



