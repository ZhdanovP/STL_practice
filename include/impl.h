#pragma once
#include <iterator>
#include <utility>

template <class Container>
struct accumulator
{
public:
   // I cheated and read about std::back_insert_iterator
   // https://en.cppreference.com/w/cpp/iterator/back_insert_iterator

   /** @todo Iterator traits*/
   using iterator_category = std::output_iterator_tag;
   using value_type        = void;
   using pointer           = void;
   using reference         = void;
   using difference_type   = void;

   /** @todo Constructor with container*/
   accumulator( Container& container ) : m_container{ container }
   {
   }

   /** @todo Copy assignment operator*/
   // assigning from other container with the SAME items:
   // for example from vector<value> to deque<value>
   template <class OtherContainer>
   accumulator& operator=( const OtherContainer& other )
   {
      m_container.insert( std::end( m_container ), std::begin( other ), std::end( other ) );
      return *this;
   }

   /** @todo Move assignment operator*/
   template <class OtherContainer>
   accumulator& operator=( OtherContainer&& other )
   {
      m_container.insert( std::end( m_container ), std::make_move_iterator( std::begin( other ) ),
                          std::make_move_iterator( std::end( other ) ) );
      return *this;
   }

   /** @todo Iterator operations */
   // @returns *this to work in pair with operator=
   // *it = value;
   accumulator& operator*()
   {
      return *this;
   }

   accumulator& operator++()
   {
      return *this;
   }

   accumulator& operator++( int )
   {
      return *this;
   }

private:
   Container& m_container;
};

/**
 *  @todo Implement accumulator object creator
 */
template <class Container>
accumulator<Container> make_accumulator( Container& container )
{
   return accumulator<Container>( container );
}
