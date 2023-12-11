#ifndef GOALIE_HPP
#define GOALIE_HPP

#include "player.hpp"
using namespace std;

class Goalie : public Player {
public:
    Goalie(string n, int spd, int num, int ovr, int s, double sp, double ga, int w, int l, int t);
    Goalie();

    void displayStats() const override;
    void saveToFile(ofstream& outFile) const;
    double getSaveP() const { return savePercentage; }
    double getGoalsAgainst() const { return goalsAgainst; }
    double getGoalsAgainstAverage() const { return goalsAgainstAverage; }
    int getSaves() const { return saves; }
    int getWins() const { return wins; }
    int getLosses() const { return losses; }
    int getTies() const { return ties; }
    string getType() const { return "Goalie"; }


protected:
    int saves;
    double savePercentage;
    double goalsAgainst;
    double goalsAgainstAverage;
    int wins;
    int losses;
    int ties;
    int gamesPlayed;
};

#endif // GOALIE_HPP
