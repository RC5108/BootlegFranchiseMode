#include "player.hpp"

// Constructors
//pre: Constructs a player with basic details
//post: Initializes a player with name, speed, number, overall rating, and position
Player::Player(string n, int spd, int num, int ovr, string pos) {
    name = n;
    speed = spd;
    number = num;
    overall = ovr;
    goals = 0;
    assists = 0;
    points = goals + assists;
    pim = 0;
    hits = 0;
    gamesPlayed = 0;
    position = pos;
}

//pre: Constructs a player with detailed statistics
//post: Initializes a player with comprehensive stats including goals, assists, etc.
Player::Player(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp, string pos) {
    name = n;
    speed = spd;
    number = num;
    overall = ovr;
    goals = g;
    assists = a;
    points = goals + assists;
    pim = pim;
    hits = h;
    gamesPlayed = gp;
    position = pos;
}

//pre: Constructs a player with a specific position and random name
//post: Initializes a player with default stats and a position
Player::Player(string pos) {
    name = RandomName::getRandomName();
    speed = 60;
    overall = 65;
    goals = 0;
    assists = 0;
    points = goals + assists;
    pim = 0;
    hits = 0;
    position = pos;
    gamesPlayed = 0;
}

//pre: Default constructor
//post: Initializes a default player with random name and basic stats
Player::Player() {
    name = RandomName::getRandomName();
    speed = 60;
    overall = 65;
    goals = 0;
    assists = 0;
    points = goals + assists;
    pim = 0;
    hits = 0;
    gamesPlayed = 0;
}

//pre: Displays the player's stats
//post: Outputs the player's statistics to the console
void Player::displayStats() const {
    cout << "Player: #" << number << " " << name << ", Overall: " << overall << "Speed: " << speed << " : " << endl;
}

//pre: Accepts a reference to an output file stream
//post: Saves the player's stats to the given file
void Player::saveToFile(std::ofstream& outFile) const {
    outFile << name << ",#" << number << "," << speed << "," << overall << "," << gamesPlayed << ", "
        << goals << "," << assists << "," << points << "," << pim << "," << hits << " ";
}
