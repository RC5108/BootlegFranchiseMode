#ifndef FORWARD_HPP
#define FORWARD_HPP

#include "player.hpp"

class Forward : public Player {
public:
    Forward(string n, int spd, int num, int ovr);
    Forward(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp);
    Forward();

    void displayStats() const override;
    void saveToFile(ofstream& outFile) const;
    string getStats() const override {
        stringstream ss;
        ss << Player::getStats() << ", Goals: " << goals << ", Assists: " << assists
            << ", Points: " << points << ", PIM: " << pim << ", Hits: " << hits;
        return ss.str();
    }
    string getType() const { return "Forward"; }

    void incrementGoals(int numGoals) {
        goals += numGoals;
    }
    void incrementAssists(int numAssists) {
        assists += numAssists;
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

#endif // FORWARD_HPP

