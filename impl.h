#pragma once
#include "bar_serving.h"
#include <functional>

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
public:
    BeerBrand operator()();
private:
    BeerBrand next();
    BeerBrand current = BeerBrand::None;
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer(BeerBrand brand)
{
    switch (brand) {
    case BeerBrand::Corona:
    case BeerBrand::HoeGaarden:
        return true;
    default:
        return false;
    }
    return false;
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = [](BeerBrand l, BeerBrand r)
{
    return getBeerCountry(l) == getBeerCountry(r);
};

struct MixingPolicy
{
    /**
     * @todo Implement static transformator function
     * @return crafted cocktail
     *
     * @note Cookbook:
     * Gin + Lime juice = Gimlet;
     * Gin + Grapefruit juice = Greyhount;
     * Whiskey + SevenUp = SevenPlusSeven;
     * Others + Others = Oops;
     */
    static Cocktail mix(AlcoholDrink alcoholDrink, NonAlcoholDrink nonAlcoholDrink)
    {
        if (alcoholDrink == AlcoholDrink::Gin &&
            nonAlcoholDrink == NonAlcoholDrink::LimeJuice)
        {
            return Cocktail::Gimlet;
        }

        if (alcoholDrink == AlcoholDrink::Gin &&
            nonAlcoholDrink == NonAlcoholDrink::GrapefruitJuice)
        {
            return Cocktail::Greyhount;
        }

        if (alcoholDrink == AlcoholDrink::Whiskey &&
            nonAlcoholDrink == NonAlcoholDrink::SevenUp)
        {
            return Cocktail::SevenPlusSeven;
        }

        return Cocktail::Oops;
    }
};

std::function<Cocktail(AlcoholDrink, NonAlcoholDrink)> mixer {&MixingPolicy::mix};
