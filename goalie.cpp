#include "goalie.hpp"

Goalie::Goalie(string n, int spd, int num, int ovr ,int s, double svp, double ga, int w, int l, int t)
    : Player(n, spd, num, ovr, "Goalie"), saves(s), savePercentage(svp), goalsAgainst(ga),
    wins(w), losses(l), ties(t), gamesPlayed(wins+losses+ties), goalsAgainstAverage(goalsAgainst/gamesPlayed){}
Goalie::Goalie() : Player("Goalie"), saves(0), savePercentage(0), goalsAgainst(0), wins(0), losses(0), ties(0), gamesPlayed(0), goalsAgainstAverage(0) {}

void Goalie::displayStats() const{
    Player::displayStats();
    cout << "Record: " << wins << "-" << losses << "-" << ties << endl;
    cout << "Save Percent: " << savePercentage << "%" << endl;
    cout << "Goals Against Average: " << goalsAgainstAverage << endl;
    cout << "Saves: " << saves << endl;
}

void Goalie::saveToFile(ofstream& outFile) const{
    outFile << "Goalie ";
    Player::saveToFile(outFile);
    outFile << "," << wins << "," << losses << "," << ties << "," << goalsAgainstAverage << "," << savePercentage << "," << saves
        << "," << gamesPlayed << "," << goalsAgainst << endl;
}

