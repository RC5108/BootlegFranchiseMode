#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

// Node structure
struct GameNode {
    string opponent;
    string date;
    GameNode* next;

    GameNode(string opp, string dt, GameNode* nextNode = nullptr) {
        opponent = opp;
        date = dt;
        next = nextNode;
    }
};

// Linked list class representing a team's season schedule
class Schedule {
protected:
    GameNode* head;
    time_t seasonStartDate;

    string formatDate(time_t date);
    string getNextGameDate(int gameNumber);

public:
    Schedule(time_t startDate) : head(nullptr), seasonStartDate(startDate) {}
    Schedule() : head(nullptr), seasonStartDate(time(0)) {}
    ~Schedule() {
        while (head != nullptr) {
            GameNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addGame(string opponent, int gameNumber);
    void generateSchedule();
    void printSchedule();
    void printUpcomingGames(int numOfGames);
};


#endif // SCHEDULE_HPP