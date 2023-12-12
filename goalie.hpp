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
    //Getters
    double getSaveP() const { return savePercentage; }
    double getGoalsAgainst() const { return goalsAgainst; }
    double getGoalsAgainstAverage() const { return goalsAgainstAverage; }
    int getSaves() const { return saves; }
    int getWins() const { return wins; }
    int getLosses() const { return losses; }
    int getTies() const { return ties; }
    string getType() const { return "Goalie"; }

    void incrementGP() {
        gamesPlayed += 1;
    }

    void incrementSaves(int s) {
        saves += s;
    }

    void incrementgoalsAgainst(double goals) {
        goalsAgainst += goals;
        updateGAA();
    }

    void updateGAA() {
        if (gamesPlayed > 0) {
            // GP * 60 because there's 60 minutes in a game
            goalsAgainstAverage = goalsAgainst / (gamesPlayed*60);
        }
    }

    void updateSavePercentage() {
        double totalShots = goalsAgainst + saves;
        savePercentage = saves / totalShots;
    }

    void recordWin() {
        wins += 1;
    }

    void recordLoss() {
        losses += 1;
    }

    void recordTie() {
        ties += 1;
    }

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
