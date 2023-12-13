#include "forward.hpp"

Forward::Forward(string n, int spd, int num, int ovr) : Player(n, spd, num, ovr, "Forward") {}
Forward::Forward(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp) :
    Player(n, spd, num, ovr, g, a, pim, h, gp, "Forward") {};
Forward::Forward() : Player("Forward") {};


void Forward::displayStats() const {
    Player::displayStats();
    cout << "Goals : " << goals << ", Assists: " << assists << ", Points: " << points;
    cout << ", PIM: " << pim << ", Hits : " << hits << endl;
}

void Forward::saveToFile(ofstream& outFile) const {
    outFile << "Forward ";
    Player::saveToFile(outFile);

}