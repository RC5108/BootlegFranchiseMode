#ifndef DEFENSEMAN_HPP
#define DEFENSEMAN_HPP

#include "player.hpp"

class Defenseman : public Player {
public:
    Defenseman(string n, int spd, int num, int ovr);
    Defenseman(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp);
    Defenseman();

    void displayStats() const override;
    void saveToFile(ofstream& outFile) const;
    string getType() const { return "Defenseman"; }

    void incrementGoals(int numGoals) {
        goals += numGoals;
        points += numGoals;
    }
    void incrementAssists(int numAssists) {
        assists += numAssists;
        points += numAssists;
    }
    void incrementGP() {
        gamesPlayed += 1;
    }
    void incrementPoints() {
        points = goals + assists;
    }
    void incrementHits(int numHits) {
        hits += numHits;
    }
    void incrementPIM(int numPIM) {
        pim += numPIM;
    }
};

#endif // DEFENSEMAN_HPP
