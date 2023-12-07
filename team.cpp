#include "team.hpp"
#include "randomname.hpp"
// Constructor that builds the users team 
Team::Team(Forward f[], Defenseman d[], Goalie g) {
    for (int i = 0; i < 6; ++i) {
        forwards[i] = f[i];
        players.push_back(forwards[i]);
        existingNumber.insert(forwards[i].getNumber());
    }
    for (int i = 0; i < 4; ++i) {
        defensemen[i] = d[i];
        players.push_back(defensemen[i]);
        existingNumber.insert(defensemen[i].getNumber());
    }
    goalie = g;
    players.push_back(goalie);
    existingNumber.insert(goalie.getNumber());
}


Team::Team() {
    for (int i = 0; i < 6; ++i) {
        Forward forward; 
        forward.setNumber(RandomName::generateUniqueNumber(existingNumber));
        existingNumber.insert(forward.getNumber());
        forwards[i] = forward;
        players.push_back(forward);
    }
    for (int i = 0; i < 4; ++i) {
        Defenseman defenseman; 
        defenseman.setNumber(RandomName::generateUniqueNumber(existingNumber));
        existingNumber.insert(defenseman.getNumber());
        defensemen[i] = defenseman;
        players.push_back(defenseman);
    }
    Goalie newGoalie; 
    newGoalie.setNumber(RandomName::generateUniqueNumber(existingNumber));
    existingNumber.insert(newGoalie.getNumber());
    goalie = newGoalie;
    players.push_back(goalie);
}


// Function that prints the user's players to the screen
void Team::displayTeam() {
    cout << "Forwards:" << endl;
    for (auto& forward : forwards) {
        forward.displayStats();
    }
    cout << "Defensemen:" << endl;
    for (auto& defenseman : defensemen) {
        defenseman.displayStats();
    }
    cout << "Goalie:" << endl;
    goalie.displayStats();
}

void Team::saveToFile(std::ofstream& outFile) const{
    for (auto& forward : forwards) {
        forward.saveToFile(outFile);
    }
    for (auto& defensemen : defensemen) {
        defensemen.saveToFile(outFile);
    }

    goalie.saveToFile(outFile);
}

void Team::initializePlayers() {
    for (Player& player : players) {
        int uniqueNumber = RandomName::generateUniqueNumber(existingNumber);
        player.setNumber(uniqueNumber);
        existingNumber.insert(uniqueNumber);
    }
}

void Team::addPlayer(Player& player) {
    int uniqueNumber = RandomName::generateUniqueNumber(existingNumber);
    player.setNumber(uniqueNumber);
    existingNumber.insert(uniqueNumber);
    players.push_back(player);
}
