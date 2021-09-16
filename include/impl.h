#pragma once
#include <vector>
#include <string>
#include <stdexcept>

template<class Container, class Song_t>
class StaticPlaylist
{
public:
   /** @todo Member traits */
   using value_type = typename Container::value_type;
   using size_type = typename Container::size_type;
   using reference = value_type&;
   using const_reference = const value_type&;

   /** @todo Iterators */
   using iterator = typename Container::iterator;
   using const_iterator = typename Container::const_iterator;
   using difference_type = typename Container::difference_type;

   const_iterator begin()
   {
      return m_tracklist.cbegin();
   }

   const_iterator end()
   {
      return m_tracklist.cend();
   }

   const_iterator cbegin()
   {
      return m_tracklist.cbegin();
   }

   const_iterator cend()
   {
      return m_tracklist.cend();
   }

   StaticPlaylist() = default;

   /** @todo Constructor from any reversible sequence container */
   template <typename T>
   StaticPlaylist(const T& t)
      : m_tracklist(t.rbegin(), t.rend())
   {
   }

   /** @todo Assignment from any reversible sequence container */
   StaticPlaylist(const StaticPlaylist& list)
      : m_tracklist(std::rbegin(list), std::rend(list))
   {
   }

   /** @todo Add track from initializer */
   template<class... Args>
   const Song_t& play(Args&&... songData)
   {
      m_tracklist.emplace_back(songData...);
      return m_tracklist.back();
   }

   /** @todo Add track */
   const Song_t& play(const Song_t& song)
   {
      m_tracklist.emplace_back(song);
      return m_tracklist.back();
   }


    /** @todo Get first track in playlist stack */
   const Song_t& current() const
   {
      if (m_tracklist.empty())
      {
         throw std::out_of_range("oops!");
      }
      return m_tracklist.back();
   }

    /** @todo Skip to the next track in playlist, remove current */
   void switchNext()
   {
      if (count() > 0)
      {
         m_tracklist.resize(count() - 1);
      }
      else
      {
         throw std::out_of_range("oops!");
      }
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

private:
    Container m_tracklist;
};
