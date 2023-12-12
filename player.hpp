#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <random>
#include <sstream>
#include <string>
#include "randomname.hpp"

using namespace std;

static set<int> existingPlayerNumbers;

class Player {
protected:
    string name;
    string position;
    int speed;
    int number;
    int overall;
    int goals;
    int assists;
    int points;
    int pim;
    int hits;
    int gamesPlayed;

public:

    Player(string n, int spd, int num, int ovr, int g, int a, int pim, int h, int gp, string pos);
    Player(string n, int spd, int num, int ovr, string pos);
    Player(string pos);
    Player();


    virtual void displayStats() const;
    virtual void saveToFile(ofstream& outFile) const;
    void setNumber(int num) {
        number = num;
    }
    int getNumber() const { return number; }

    // Gettors
    string getName() const { return name; }
    string getPosition() const { return position; }
    int getGoals() const { return goals; }
    int getAssists() const { return assists; }
    int getPoints() const { return points; }
    int getPIM() const { return pim; }
    int getHits() const { return hits; }
    int getGames() const { return gamesPlayed; }
    virtual string getStats() const {
        stringstream ss;
        ss << "Name: " << name << ", Overall: " << overall << ", Number: " << number
            << ", Speed: " << speed << ", Games Played: " << gamesPlayed;
        return ss.str();
    }
    virtual string getType() { return "Player "; }



};

#endif // PLAYER_HPP
