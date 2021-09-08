#pragma once
#include <cstdint>  // uint32_t
#include <functional>
#include <map>
#include <utility>  // std::pair
#include "bar_serving.h"

/**
 * @todo Implement functor-generator that will return next beer brand (cyclic)
 * @example HoeGaarden -> Corona -> Carlsberg -> Bud -> ZlataPraha -> Leffe -> HoeGaarden...
 */
struct BeerOrganizer
{
public:
   BeerBrand operator()()
   {
      m_currentBrand = static_cast<BeerBrand>( static_cast<uint32_t>( m_currentBrand ) + 1 );

      if ( m_currentBrand == BeerBrand::Max )
      {
         m_currentBrand = static_cast<BeerBrand>( static_cast<uint32_t>( BeerBrand::None ) + 1 );
      }

      return m_currentBrand;
   }

private:
   // always guaranteed that at least None and Max exist
   BeerBrand m_currentBrand{ BeerBrand::None };
};

/**
 * @todo Implement unary predicate function that will determine if beer is expensive
 * @return true in case if beer is expensive, false if not
 *
 * @note Only Corona and HoeGaarden are expensive
 */
bool isExpensiveBeer( const BeerBrand beer )
{
   if ( beer == BeerBrand::Corona || beer == BeerBrand::HoeGaarden )
   {
      return true;
   }

   return false;
}

/**
 * @todo Implement lambda beer country equality comparator
 * @return true if beer county is the same, false otherwise
 */
auto sameCountry = []( const BeerBrand lhs, const BeerBrand rhs ) {
   return getBeerCountry( lhs ) == getBeerCountry( rhs );
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

   static const std::map<std::pair<AlcoholDrink, NonAlcoholDrink>, Cocktail> cookbook;

   static Cocktail mix( const AlcoholDrink alcohol, const NonAlcoholDrink nonAlcohol )
   {
      std::pair<AlcoholDrink, NonAlcoholDrink> recipe{ alcohol, nonAlcohol };
      if ( cookbook.count( recipe ) == 0 )
      {
         return Cocktail::Oops;
      }

      return cookbook.at( recipe );
   }
};

const std::map<std::pair<AlcoholDrink, NonAlcoholDrink>, Cocktail> MixingPolicy::cookbook = {
    { { AlcoholDrink::Gin, NonAlcoholDrink::LimeJuice }, Cocktail::Gimlet },
    { { AlcoholDrink::Gin, NonAlcoholDrink::GrapefruitJuice }, Cocktail::Greyhount },
    { { AlcoholDrink::Whiskey, NonAlcoholDrink::SevenUp }, Cocktail::SevenPlusSeven } };

std::function<Cocktail( const AlcoholDrink, const NonAlcoholDrink )> mixer{ &MixingPolicy::mix };
