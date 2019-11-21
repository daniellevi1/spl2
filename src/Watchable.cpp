//
// Created by idosht@wincs.cs.bgu.ac.il on 20/11/2019.
//

#include "../include/Watchable.h"
//Constructor
Watchable::Watchable(long id, int length, const std::vector<std::string>& tags):id(id),length(length),
                                                                                tags(tags){
};
//Destructor
Watchable::~Watchable() {}

Watchable* Watchable::getNextWatchable(Session &) const {

}
std::string Watchable::toString() const {
}

//Movie Constructor
Movie::Movie(long id, const std::string &name, int length, const std::vector<std::string> &tags):
        Watchable(id,length,tags),name(name) {

}

std::string Movie::toString() const {
    return name;
}
Watchable* Movie::getNextWatchable(Session &) const {}

//Episode Constructor
Episode::Episode(long id, const std::string &seriesName, int length, int season, int episode,
                 const std::vector<std::string> &tags) : Watchable(id,length,tags),seriesName(seriesName) ,season(season),episode(episode){

}
std::string Episode::toString() const {
    return (seriesName + "S" + std::to_string(season)  + "E"+ std::to_string(episode)) ;
}
Watchable* Episode::getNextWatchable(Session &) const {}