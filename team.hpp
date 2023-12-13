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


//Struct used to help sort standings
struct TeamData {
    string name;
    int wins;
    int losses;
    int ties;
    int points;

    TeamData(const string& name, int wins, int losses, int ties)
        : name(name), wins(wins), losses(losses), ties(ties) {
        points = wins * 2 + ties;
    }
};


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
    string teamName;
    int gamesSimulated = 0;
    int wins = 0;
    int losses = 0;
    int ties = 0;
    // 2 points for a win
    // 1 point for a tie
    // 0 points for a loss
    int points = 0;

public:
    Team(const string& name, Forward f[], Defenseman d[], Goalie g);
    Team(const string& name);
    Team();

    void displayTeam();
    void saveToFile(std::ofstream& outFile) const;
    void initializePlayers();
    void addPlayer(Player& player);
    void viewUpcomingGames(int numOfGames);
    void setName(const string& name) { teamName = name; }
    // Simulate the next game on the schedule
    void simulateNextGame();
    // Get how many goals are scored in a game
    int getGameGoals();
    //

    string getName() const { return teamName; }
    int getWins() const { return wins; }
    int getLosses() const { return losses; }
    int getTies() const { return ties; }
    int getPoints() const { return points; }
    void updatePlayerStats(int teamGoalsScored, int teamGoalsAgainst);
    void loadFromFile(const string& filename);
    vector<Player> getPlayers() const {
        return players;
    }
    void writePlayerStatsToFile(const string filename);

    void recordWin(){
        wins += 1;
        points += 2;
    }
    void recordTie() {
        ties += 1;
        points += 1;
    }
    void recordLoss() {
        losses += 1;
    }

    void displayStandings(const Team& userTeam, const Team& redTeam, const Team& blueTeam, const Team& greenTeam);
};

#endif // TEAM_HPP
