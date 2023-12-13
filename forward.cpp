#include "forward.hpp"

//pre: Constructs a forward player with name, speed, number, and overall rating
//post: Initializes a forward player with basic details
Forward::Forward(string n, int spd, int num, int ovr) : Player(n, spd, num, ovr, "Forward") {}

//pre: Constructs a forward player with detailed statistics
//post: Initializes a forward player with comprehensive stats
Forward::Forward(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp) :
    Player(n, spd, num, ovr, g, a, pim, h, gp, "Forward") {};

//pre: Default constructor
//post: Initializes a default forward player
Forward::Forward() : Player("Forward") {};

//pre: Displays the stats of a forward player
//post: Outputs the forward player's statistics to the console
void Forward::displayStats() const {
    Player::displayStats();
    cout << "Goals : " << goals << ", Assists: " << assists << ", Points: " << points;
    cout << ", PIM: " << pim << ", Hits : " << hits << endl;
}

//pre: Accepts a reference to an output file stream
//post: Saves the forward player's stats to the given file
void Forward::saveToFile(ofstream& outFile) const {
    outFile << "Forward ";
    Player::saveToFile(outFile);

}