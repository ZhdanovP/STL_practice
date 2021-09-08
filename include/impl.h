#pragma once
#include "bar_serving.h"
#include <functional>
#include <vector>

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
    BeerOrganizer()
        : _next(0)
        , _brands({
            BeerBrand::HoeGaarden,
            BeerBrand::Corona,
            
            BeerBrand::Carlsberg,
            BeerBrand::Bud,
            BeerBrand::ZlataPraha,
            BeerBrand::Leffe})
    {
    }

    BeerBrand operator()()
    {
        if (_next >= _brands.size())
            _next = 0;
        return _brands[_next++];
    }

private:
    size_t _next;
    std::vector<BeerBrand> _brands;
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer(const BeerBrand brand)
{
    return (BeerBrand::Corona == brand || BeerBrand::HoeGaarden == brand);
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = [](const BeerBrand brand1, const BeerBrand brand2)
{
    return (getBeerCountry(brand1) == getBeerCountry(brand2));
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
    static Cocktail mix(const AlcoholDrink alcohol, const NonAlcoholDrink nonAlcohol)
    {
        Cocktail coctail = Cocktail::Oops;

        if (AlcoholDrink::Gin == alcohol && NonAlcoholDrink::LimeJuice == nonAlcohol)
            coctail = Cocktail::Gimlet;
        else if (AlcoholDrink::Gin == alcohol && NonAlcoholDrink::GrapefruitJuice == nonAlcohol)
            coctail = Cocktail::Greyhount;
        else if (AlcoholDrink::Whiskey == alcohol && NonAlcoholDrink::SevenUp == nonAlcohol)
            coctail = Cocktail::SevenPlusSeven;

        return coctail;
    }
};

std::function<Cocktail(const AlcoholDrink, const NonAlcoholDrink)> mixer {&MixingPolicy::mix};
