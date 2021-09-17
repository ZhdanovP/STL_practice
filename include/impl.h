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
    using size_type       = typename Container::size_type;

    /** @todo Iterators */
    using iterator        = typename Container::iterator;
    using const_iterator  = typename Container::const_iterator;
    using difference_type = typename Container::difference_type;

    StaticPlaylist() = default;

    /** @todo Constructor from any reversible sequence container */
    template<typename OtherContainer>
    StaticPlaylist(const OtherContainer& other):m_tracklist{std::rbegin(other), std::rend(other)}{}

    /** @todo Assignment from any reversible sequence container */
    template<typename OtherContainer>
    StaticPlaylist& operator= (const OtherContainer& other){
        m_tracklist.clear();
        m_tracklist.assign(std::rbegin(other), std::rend(other));
        return *this;
    }

    /** @todo Add track from initializer */
    template<class... Args>
    const Song_t& play(Args&&... songData){
        m_tracklist.emplace_back(songData...);
        return m_tracklist.back();
    }

    /** @todo Add track */
    const Song_t& play(const Song_t& song){
        m_tracklist.push_back(song);
        return m_tracklist.back();
    }

    /** @todo Get first track in playlist stack */
    const Song_t& current() const{
        if(m_tracklist.empty()){
            throw std::out_of_range("Tracklist is empty!");
        }
        return m_tracklist.back();
    }

    /** @todo Skip to the next track in playlist, remove current */
    void switchNext(){
        if(m_tracklist.empty()){
            throw std::out_of_range("Tracklist is empty!");
        }
        m_tracklist.pop_back();
    }

    /** @todo Amount of tracks in playlist */
    size_type count() const{
        return m_tracklist.size();
    }

    /** @todo Checks if playlist has any playable tracks */
    bool hasTracks() const{
        return !m_tracklist.empty();
    }

    const_iterator begin()const {
        m_tracklist.begin();
    }

    const_iterator end()const {
        m_tracklist.end();
    }

private:
    Container m_tracklist;
};
