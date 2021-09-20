#pragma once
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <stdexcept>

template<class Container, class Song_t>
class StaticPlaylist
{
public:
    /** @todo Member traits */
    using value_type = Song_t;
    using reference = Song_t &;
    using const_reference = const Song_t &;

    /** @todo Iterators */
    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;

    using difference_type = typename Container::difference_type;
    using size_type = typename Container::size_type;

    StaticPlaylist() = default;

    /** @todo Constructor from any reversible sequence container */
    StaticPlaylist(const std::vector<Song_t> &container)
        : m_tracklist(container.rbegin(), container.rend())
    {}
    StaticPlaylist(const std::deque<Song_t> &container)
        : m_tracklist(container.rbegin(), container.rend())
    {}
    StaticPlaylist(const std::list<Song_t> &container)
        : m_tracklist(container.rbegin(), container.rend())
    {}

    /** @todo Assignment from any reversible sequence container */
    StaticPlaylist & operator=(const std::vector<Song_t> &container)
    {
        m_tracklist = Container(container.rbegin(), container.rend());
        return *this;
    }
    StaticPlaylist & operator=(const std::deque<Song_t> &container)
    {
        m_tracklist = Container(container.rbegin(), container.rend());
        return *this;
    }
    StaticPlaylist & operator=(const std::list<Song_t> &container)
    {
        m_tracklist = Container(container.rbegin(), container.rend());
        return *this;
    }

    const_iterator begin() const
    {
        return m_tracklist.begin();
    }

    const_iterator end() const
    {
        return m_tracklist.end();
    }

    iterator begin()
    {
        return m_tracklist.begin();
    }

    iterator end()
    {
        return m_tracklist.end();
    }

    /** @todo Add track from initializer */
    template<class... Args>
    const Song_t& play(Args&&... songData)
    {
        return play(std::forward<Args>(songData)...);
    }

    /** @todo Add track */
    const Song_t& play(const Song_t& song)
    {
        return *m_tracklist.insert(m_tracklist.end(), song);
    }

    /** @todo Get first track in playlist stack */
    const Song_t& current() const
    {
        if (m_tracklist.empty()) {
            throw std::out_of_range("Container is empty");
        }
        return m_tracklist.back();
    }

    /** @todo Skip to the next track in playlist, remove current */
    void switchNext()
    {
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

private:
    Container m_tracklist;
};
