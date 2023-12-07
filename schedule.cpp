#include "schedule.hpp"


string Schedule::formatDate(time_t date) {
    struct tm dt;
    char formattedDate[80];
    localtime_s(&dt, &date);
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", &dt);
    return string(formattedDate);
}

string Schedule::getNextGameDate(int gameNum) {
    // Assuming each game is 7 days apart
    time_t gameDate = seasonStartDate + (gameNum * 7 * 24 * 60 * 60);
    return formatDate(gameDate);
}

void Schedule::addGame(string opp, int gameNum) {
    string date = getNextGameDate(gameNum);
    GameNode* newNode = new GameNode(opp, date);
    newNode->next = head;
    head = newNode;
}

void Schedule::generateSchedule() {
    string opponents[3] = { "Blue Team", "Red Team", "Green Team" };
    for (int i = 19; i >= 0; i--) {
        addGame(opponents[i % 3], i);
    }
}

void Schedule::printSchedule() {
    GameNode* current = head;
    while (current != nullptr) {
        cout << "Game on " << current->date << " against " << current->opponent << endl;
        current = current->next;
    }
}

void Schedule::printUpcomingGames(int numOfGames) {
    GameNode* current = head;
    int count = 0;
    while (current != nullptr && count < numOfGames) {
        cout << "Upcoming Game: " << current->date << " against " << current->opponent << endl;
        current = current->next;
        count++;
    }
}