#include "../include/User.h"
#include <vector>
#include <string>
#include "../include/Watchable.h"
#include <unordered_set>
#include <unordered_map>




User::User(const std::string &name): name(name) {}


std::vector<Watchable*> User::get_history() const {
    return history;
}


std::string User::getName() const {
    return  name;
}

Watchable* User::getRecommendation(Session &s) {
    return
}