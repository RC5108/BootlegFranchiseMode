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

const int NUM_FORWARDS = 6;
const int NUM_DEFENSEMAN = 4;
const int NUM_GOALIES = 1;
class Team {
protected:
    Forward forwards[NUM_FORWARDS];
    Defenseman defensemen[NUM_DEFENSEMAN];
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
    // Simulate the next game on the schedule
    void simulateNextGame();
    // Get how many goals are scored in a game
    int getGameGoals();
    //
    void updatePlayerStats(int teamGoalsScored, int teamGoalsAgainst);
    vector<Player> getPlayers() const {
        return players;
    }
    void writePlayerStatsToFile(const string filename);
};

#endif // TEAM_HPP
