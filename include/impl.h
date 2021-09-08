#pragma once
#include "bar_serving.h"
#include <functional>
#include <map>

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
private:
    uint8_t curBrand = 0;
public:
    BeerBrand operator()()
    {
        if (static_cast<uint8_t>(BeerBrand::Max) == ++curBrand)
        {
            curBrand = static_cast<uint8_t>(BeerBrand::None)+1;
        }

        return static_cast<BeerBrand>(curBrand);
    }
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer(const BeerBrand& brand)
{
    return ((brand==BeerBrand::Corona) || (brand==BeerBrand::HoeGaarden));
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = [](const BeerBrand& lhs, const BeerBrand& rhs)
{
    return getBeerCountry(lhs) == getBeerCountry(rhs);
};

static std::map<std::pair<AlcoholDrink, NonAlcoholDrink>, Cocktail> cookbook =
{
    {{AlcoholDrink::Gin, NonAlcoholDrink::LimeJuice}, Cocktail::Gimlet},
    {{AlcoholDrink::Gin, NonAlcoholDrink::GrapefruitJuice}, Cocktail::Greyhount},
    {{AlcoholDrink::Whiskey, NonAlcoholDrink::SevenUp}, Cocktail::SevenPlusSeven}
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

    static Cocktail mix(const AlcoholDrink& alcohol, const NonAlcoholDrink& nonAlcohol)
    {
        if(auto recipe = cookbook.find(std::make_pair(alcohol, nonAlcohol)); recipe != cookbook.end()){
            return recipe->second;
        }
        return Cocktail::Oops;
    }
};

std::function<Cocktail(const AlcoholDrink&, const NonAlcoholDrink&)> mixer {&MixingPolicy::mix};
