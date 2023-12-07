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
};

#endif // FORWARD_HPP

