#pragma once
#include "bar_serving.h"
#include <functional>

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
   BeerOrganizer() 
      : mState(BeerBrand::None) 
   {}

   BeerBrand operator()()
   {            
      switch (mState)
      {
      case BeerBrand::None:
         mState = BeerBrand::HoeGaarden;
         break;
      case BeerBrand::HoeGaarden:
         mState = BeerBrand::Corona;
         break;
      case BeerBrand::Corona:
         mState = BeerBrand::Carlsberg;
         break;
      case BeerBrand::Carlsberg:
         mState = BeerBrand::Bud;
         break;
      case BeerBrand::Bud:
         mState = BeerBrand::ZlataPraha;
         break;
      case BeerBrand::ZlataPraha:
         mState = BeerBrand::Leffe;
         break;
      case BeerBrand::Leffe:
         mState = BeerBrand::HoeGaarden;
         break;
      default:
         mState = BeerBrand::None;
      }

      return mState;
   }

   BeerBrand mState;
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer(const BeerBrand beer)
{
   return beer == BeerBrand::Corona || beer == BeerBrand::HoeGaarden;
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = [](const BeerBrand brand1, const BeerBrand brand2)
{
   return getBeerCountry(brand1) == getBeerCountry(brand2);
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
    static Cocktail mix(AlcoholDrink alcogol, NonAlcoholDrink nAlcogol)
    {
       Cocktail result = Cocktail::Oops;
       switch (alcogol)
       {
       case AlcoholDrink::Gin:
          if (nAlcogol == NonAlcoholDrink::LimeJuice)
          {
             result = Cocktail::Gimlet;
          }
          else if (nAlcogol == NonAlcoholDrink::GrapefruitJuice)
          {
             result = Cocktail::Greyhount;
          }
          break;
       case AlcoholDrink::Whiskey:
          if (nAlcogol == NonAlcoholDrink::SevenUp)
          {
             result = Cocktail::SevenPlusSeven;
          }
          break;
       default:
          break;
       }
       return result;
    }
};

std::function<Cocktail(AlcoholDrink, NonAlcoholDrink)> mixer = &MixingPolicy::mix;
