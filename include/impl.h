#pragma once
#include "bar_serving.h"
#include <functional>

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
    int idx {static_cast<int>(BeerBrand::HoeGaarden)};
    int idx_max {static_cast<int>(BeerBrand::Max)};
    BeerBrand operator()()
    {
        if (idx == idx_max)
        {
            idx = static_cast<int>(BeerBrand::HoeGaarden);
        }
        return static_cast<BeerBrand>(idx++);
    }
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer(BeerBrand brand)
{
    return brand == BeerBrand::Corona
        || brand == BeerBrand::HoeGaarden;
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = [](BeerBrand lhs, BeerBrand rhs)
{
    return getBeerCountry(lhs) == getBeerCountry(rhs);
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
    static Cocktail mix(AlcoholDrink alcohol, NonAlcoholDrink non_alcohol)
    {
        switch (alcohol)
        {
            case AlcoholDrink::Gin:
            {
                switch (non_alcohol)
                {
                    case NonAlcoholDrink::LimeJuice:
                    {
                        return Cocktail::Gimlet;
                    }
                    case NonAlcoholDrink::GrapefruitJuice:
                    {
                        return Cocktail::Greyhount;
                    }
                    default:
                    {
                        return Cocktail::Oops;
                    }
                }
            }
            case AlcoholDrink::Whiskey:
            {
                if (non_alcohol == NonAlcoholDrink::SevenUp)
                {
                    return Cocktail::SevenPlusSeven;
                }
                else
                {
                    return Cocktail::Oops;
                }
            }
            default:
            {
                return Cocktail::Oops;
            }
        }
    }
};

std::function<Cocktail(AlcoholDrink, NonAlcoholDrink)> mixer {&MixingPolicy::mix};
