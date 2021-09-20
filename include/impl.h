#pragma once
#include <vector>
#include <string>
#include <stdexcept>
 
template<class Container, class Song_t>
class StaticPlaylist
{
public:
    /** @todo Member traits */
   using value_type      = typename Container::value_type;
   using reference       = typename Container::reference;
   using const_reference = typename Container::const_reference;
   using iterator        = typename Container::iterator;
   using const_iterator  = typename Container::const_iterator;
   using difference_type = typename Container::difference_type;
   using size_type       = typename Container::size_type;

    /** @todo Iterators */
   StaticPlaylist::const_iterator begin() const;
   StaticPlaylist::const_iterator end() const;

    StaticPlaylist() = default;

    /** @todo Constructor from any reversible sequence container */
   template <class T>
   StaticPlaylist( const T& container );

    /** @todo Assignment from any reversible sequence container */
   template <class T>
   StaticPlaylist& operator=( const T& container );

    /** @todo Add track from initializer */
    template<class... Args>
    const Song_t& play(Args&&... songData);

    /** @todo Add track */
    const Song_t& play(const Song_t& song);

    /** @todo Get first track in playlist stack */
    const Song_t& current() const;

    /** @todo Skip to the next track in playlist, remove current */
    void switchNext();

    /** @todo Amount of tracks in playlist */
    size_type count() const;

    /** @todo Checks if playlist has any playable tracks */
    bool hasTracks() const;

private:
    Container m_tracklist;
};

template<class Container, class Song_t>
typename StaticPlaylist<Container, Song_t>::const_iterator StaticPlaylist<Container, Song_t>::begin() const
{
    return m_tracklist.begin();
}

template<class Container, class Song_t>
typename StaticPlaylist<Container, Song_t>::const_iterator StaticPlaylist<Container, Song_t>::end() const
{
    return m_tracklist.end();
}

template<class Container, class Song_t>
template <class T>
StaticPlaylist<Container, Song_t>::StaticPlaylist( const T& container ) : m_tracklist( container.rbegin(), container.rend() )
{
    
}


template<class Container, class Song_t>
template <class T>
StaticPlaylist<Container, Song_t>& StaticPlaylist<Container, Song_t>::operator=( const T& container )
{
    m_tracklist.clear();
    m_tracklist.assign( container.rbegin(), container.rend() );
    return *this;
}

template<class Container, class Song_t>
template<class... Args>
const Song_t& StaticPlaylist<Container, Song_t>::play(Args&&... songData)
{
    m_tracklist.emplace_back( songData... );
    return m_tracklist.back();
}

template<class Container, class Song_t>
const Song_t& StaticPlaylist<Container, Song_t>::play(const Song_t& song)
{
    m_tracklist.emplace_back(song);
    return m_tracklist.back();
}
    

template<class Container, class Song_t>
const Song_t& StaticPlaylist<Container, Song_t>::current() const
{
    return m_tracklist.back();
}

template<class Container, class Song_t>
void StaticPlaylist<Container, Song_t>::switchNext()
{
    if ( m_tracklist.empty() )
    {
        throw std::out_of_range("");
    }
    return m_tracklist.pop_back();
}

template<class Container, class Song_t>
typename StaticPlaylist<Container, Song_t>::size_type StaticPlaylist<Container, Song_t>::count() const
{
    return m_tracklist.size();
}

template<class Container, class Song_t>
bool StaticPlaylist<Container, Song_t>::hasTracks() const
{
    return !m_tracklist.empty();
}