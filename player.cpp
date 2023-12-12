#include "player.hpp"

// Constructors
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
void Player::displayStats() const {
    cout << "Player: #" << number << " " << name << ", Overall: " << overall << "Speed: " << speed << " : " << endl;
}

void Player::saveToFile(std::ofstream& outFile) const {
    outFile << name << ",#" << number << "," << speed << "," << overall << "," << gamesPlayed << ", "
        << goals << "," << assists << "," << points << "," << pim << "," << hits << " ";
}
