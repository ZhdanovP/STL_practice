#pragma once
#include <stdexcept>

template <class Container, class Song_t>
class StaticPlaylist
{
public:
   // static_assert(/* Container has rbegin() */, "Container needs to be reversible!");

   /** @todo Member traits */
   using value_type      = typename Container::value_type;
   using reference       = typename Container::reference;
   using const_reference = typename Container::const_reference;
   using size_type       = typename Container::size_type;

   /** @todo Iterators */
   using iterator        = typename Container::iterator;
   using const_iterator  = typename Container::const_iterator;
   using difference_type = typename Container::difference_type;

   StaticPlaylist() = default;

   /** @todo Constructor from any reversible sequence container */
   template <class OtherContainer>
   StaticPlaylist( const OtherContainer& other ) : m_tracklist{ other.rbegin(), other.rend() }
   {
   }

   /** @todo Assignment from any reversible sequence container */
   template <class OtherContainer>
   StaticPlaylist& operator=( const OtherContainer& other )
   {
      m_tracklist.assign( other.rbegin(), other.rend() );
      return *this;
   }

   /** @todo Add track from initializer */
   template <class... Args>
   const Song_t& play( Args&&... songData )
   {
      m_tracklist.emplace_back( songData... );
      return m_tracklist.back();
   }

   /** @todo Add track */
   const Song_t& play( const Song_t& song )
   {
      m_tracklist.push_back( song );
      return m_tracklist.back();
   }

   /** @todo Get first track in playlist stack */
   const Song_t& current() const
   {
      if ( m_tracklist.empty() )
      {
         throw std::out_of_range( "No current track! No tracks in playlist!" );
      }

      return m_tracklist.back();
   }

   /** @todo Skip to the next track in playlist, remove current */
   void switchNext()
   {
      if ( m_tracklist.empty() )
      {
         throw std::out_of_range( "Cant switch! No tracks in playlist!" );
      }

      m_tracklist.pop_back();
   }

   /** @todo Amount of tracks in playlist */
   size_type count() const
   {
      return m_tracklist.size();
   }

   /** @todo Checks if playlist has any playable tracks */
   bool hasTracks() const
   {
      return !m_tracklist.empty();
   }

   /** Required for range-based loop **/
   StaticPlaylist::const_iterator begin() const
   {
      return m_tracklist.begin();
   }

   StaticPlaylist::const_iterator end() const
   {
      return m_tracklist.end();
   }

private:
   Container m_tracklist;
};
