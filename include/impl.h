#pragma once
#include "bar_serving.h"
#include <functional>

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
    BeerBrand operator()() {
        switch(brand) {
        case BeerBrand::HoeGaarden:
            brand = BeerBrand::Corona;
            return BeerBrand::Corona;
        case BeerBrand::Corona:
            brand = BeerBrand::Carlsberg;
            return BeerBrand::Carlsberg;
        case BeerBrand::Carlsberg:
            brand = BeerBrand::Bud;
            return BeerBrand::Bud;
        case BeerBrand::Bud:
            brand = BeerBrand::ZlataPraha;
            return BeerBrand::ZlataPraha;
        case BeerBrand::ZlataPraha:
            brand = BeerBrand::Leffe;
            return BeerBrand::Leffe;
        case BeerBrand::Leffe:
            brand = BeerBrand::HoeGaarden;
            return BeerBrand::HoeGaarden;
        default:
            brand = BeerBrand::HoeGaarden;
            return BeerBrand::HoeGaarden;
        }
    }
    private:
        BeerBrand brand = BeerBrand::None;
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer(const BeerBrand brand)
{
    if(brand == BeerBrand::Corona || brand == BeerBrand::HoeGaarden) {
        return true;
    } else {
        return false;
    }
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = [](const BeerBrand a, const BeerBrand b)
{
    Country a_country = getBeerCountry(a);
    Country b_country = getBeerCountry(b);

    if(a_country == b_country) {
        return true;
    } else {
        return false;
    }
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
    static Cocktail mix(AlcoholDrink alcohol, NonAlcoholDrink non)
    {
        if (alcohol == AlcoholDrink::Gin && non == NonAlcoholDrink::LimeJuice) {
            return Cocktail::Gimlet;
        } else if(alcohol == AlcoholDrink::Gin && non == NonAlcoholDrink::GrapefruitJuice) {
            return Cocktail::Greyhount;
        } else if(alcohol == AlcoholDrink::Whiskey && non == NonAlcoholDrink::SevenUp) {
            return Cocktail::SevenPlusSeven;
        } else {
            return Cocktail::Oops;
        }
    }
};

std::function<Cocktail(AlcoholDrink, NonAlcoholDrink)> mixer {&MixingPolicy::mix};
