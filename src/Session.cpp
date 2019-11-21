#include "../include/Session.h"
#include "../include/json.hpp"
#include <fstream>
#include "vector"
#include "../include/Watchable.h"
//Read Json file
using namespace std;
using json=nlohmann::json;

Session::Session(const std::string &configFilePath) {

    int id = 0;
    std::ifstream i(configFilePath);
    json j;
    i >> j;
    for (auto item = j["movies"].begin(); item != j["movies"].end(); item++) {
        json movie = item.value();
        int length = movie["length"];
        string name = movie["name"];
        vector<std::string> tags = movie["tags"];
        Watchable *w = new Movie(id, name, length, tags);
        id++;
        content.push_back(w);

    }
    for (auto item1 = j["tv_series"].begin(); item1 != j["tv_series"].end(); item1++) {
        json episodes = item1.value();
        for (auto item2 = episodes["seasons"].begin(); item2 != episodes["seasons"].end(); item2++) {
            int mSeasonCounter = 1;
            json season = item2.value();
            string name = episodes["name"];
            int length = episodes["episode_length"];
            vector<std::string> tags = episodes["tags"];
            for (int i = 1; i <= item2[mSeasonCounter]; i++) {
                Watchable *episode = new Episode(id, name, length, mSeasonCounter, i, tags);
                id++;
                content.push_back(episode);


            }
            mSeasonCounter++;
        }
    }
}

Session::~Session() {

}

//
//BaseAction *Temp = new Action


