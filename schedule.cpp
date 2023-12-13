#include "schedule.hpp"

//pre: Formats a given date into a string
//post: Returns a formatted date string in "YYYY-MM-DD" format
string Schedule::formatDate(time_t date) {
    struct tm dt;
    char formattedDate[80];
    localtime_s(&dt, &date);
    strftime(formattedDate, sizeof(formattedDate), "%Y-%m-%d", &dt);
    return string(formattedDate);
}

//pre: Calculates the date of a game based on its number in the schedule
//post: Returns the date of the specified game
string Schedule::getNextGameDate(int gameNum) {
    // Assuming each game is 7 days apart
    time_t gameDate = seasonStartDate + (gameNum * 7 * 24 * 60 * 60);
    return formatDate(gameDate);
}

//pre: Adds a game to the schedule
//post: Creates a new game node and adds it to the head of the linked list
void Schedule::addGame(string opp, int gameNum) {
    string date = getNextGameDate(gameNum);
    GameNode* newNode = new GameNode(opp, date);
    newNode->next = head;
    head = newNode;
}

//pre: Generates the entire schedule for a season
//post: Populates the schedule with games against specified opponents
void Schedule::generateSchedule() {
    string opponents[3] = { "Blue Team", "Red Team", "Green Team" };
    for (int i = 19; i >= 0; i--) {
        addGame(opponents[i % 3], i);
    }
}

//pre: Prints the entire schedule
//post: Outputs all games in the schedule to the console
void Schedule::printSchedule() {
    GameNode* current = head;
    while (current != nullptr) {
        cout << "Game on " << current->date << " against " << current->opponent << endl;
        current = current->next;
    }
}

//pre: Prints a specified number of upcoming games
//post: Outputs the next few games in the schedule to the console
void Schedule::printUpcomingGames(int numOfGames) {
    GameNode* current = head;
    int count = 0;
    while (current != nullptr && count < numOfGames) {
        cout << "Upcoming Game: " << current->date << " against " << current->opponent << endl;
        current = current->next;
        count++;
    }
}

//pre: Marks the next game as played
//post: Sets the 'played' flag of the next game node to true
void Schedule::markGameAsPlayed() {
    if (head != nullptr && !head->played) {
        head->played = true;
    }
}

//pre: Removes the next game from the schedule
//post: Deletes the head node of the schedule, advancing the schedule to the next game
void Schedule::removeNextGame() {
    if (head != nullptr) {
        GameNode* temp = head;
        head = head->next;
        delete temp;
    }
}