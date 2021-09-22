#pragma once
#include <vector>
#include <string>
#include <stdexcept>

template<class Container, class Song_t>
class StaticPlaylist
{
public:
    /** @todo Member traits */
    using size_type = typename Container::size_type;
    using value_type = typename Container::value_type;
    using difference_type = typename Container::difference_type;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;

    /** @todo Iterators */
    // STL_practice/tests/unit_tests/src/maintest.cpp:80:9: error: static assertion failed: Iterator must be only const
    iterator begin()
    {
       return m_tracklist.begin();
    }

    // STL_practice/tests/unit_tests/src/maintest.cpp:80:9: error: static assertion failed: Iterator must be only const
    iterator end()
    {
       return m_tracklist.end();
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
    template <typename ReversibleSequenceContainer>
    StaticPlaylist(const ReversibleSequenceContainer& r)
        : m_tracklist(r.rbegin(), r.rend()) { }

    /** @todo Assignment from any reversible sequence container */
    template <typename ReversibleSequenceContainer>
    StaticPlaylist& operator=(const ReversibleSequenceContainer& r) {
        m_tracklist.clear();
        for (auto it = r.rbegin(); it != r.rend(); ++it) {
            m_tracklist.push_back(*it);
        }
    }


    /** @todo Add track from initializer */
    template<class... Args>
    const Song_t& play(Args&&... songData)
    {
        m_tracklist.emplace_back(songData...);
        return current();
    }

    /** @todo Add track */
    const Song_t& play(const Song_t& song)
    {
        m_tracklist.push_back(song);
        return current();
    }

    /** @todo Get first track in playlist stack */
    const Song_t& current() const
    {
        return m_tracklist.back();
    }

    /** @todo Skip to the next track in playlist, remove current */
    void switchNext()
    {
       if (!hasTracks())
       {
            throw std::out_of_range("No tracks to switch");
       }
       m_tracklist.erase(std::prev(m_tracklist.cend()));
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
