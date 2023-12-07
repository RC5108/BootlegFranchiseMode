#include "defenseman.hpp"

Defenseman::Defenseman(string n, int spd, int num, int ovr) : Player(n, spd, num, ovr, "Defenseman") {}
Defenseman::Defenseman(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp) :
    Player(n, spd, num, ovr, g, a, pim, h, gp, "Defenseman") {};
Defenseman::Defenseman() : Player("Defenseman") {};

void Defenseman::displayStats() const{
    Player::displayStats();
    cout << "Goals : " << goals << ", Assists: " << assists << ", Points: " << points;
    cout << "PIM: " << pim << ", Hits : " << hits << endl;
}

// Modify saveToFile from Player class to write 'Defenseman' before 
// players of the defenseman type
void Defenseman::saveToFile(ofstream& outFile) const {
    outFile << "Defenseman ";
    Player::saveToFile(outFile);
}

string Defenseman::getStats() const {
    // Similar implementation as in Forward
    stringstream ss;
    ss << Player::getStats() << ", Goals: " << goals << ", Assists: " << assists
        << ", Points: " << points << ", PIM: " << pim << ", Hits: " << hits;
    return ss.str();
}