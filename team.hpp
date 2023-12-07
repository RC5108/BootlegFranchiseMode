#ifndef TEAM_HPP
#define TEAM_HPP

#include "forward.hpp"
#include "defenseman.hpp"
#include "goalie.hpp"
#include "schedule.hpp"
#include <set>
#include <vector>
#include <memory>
#include "randomname.hpp"

class Team {
protected:
    Forward forwards[6];
    Defenseman defensemen[4];
    Goalie goalie;
    vector<Player> players;
    std::set<int> existingNumber;
    Schedule schedule;

public:
    Team(Forward f[], Defenseman d[], Goalie g);
    Team();

    void displayTeam();
    void saveToFile(std::ofstream& outFile) const;
    void initializePlayers();
    void addPlayer(Player& player);
    void viewUpcomingGames(int numOfGames);
    vector<Player> getPlayers() const {
        return players;
    }

};

#endif // TEAM_HPP
