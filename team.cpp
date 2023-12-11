#include "team.hpp"
#include "randomname.hpp"
// Constructor that builds the users team 
Team::Team(Forward f[], Defenseman d[], Goalie g) {
    schedule.generateSchedule();
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
    schedule.generateSchedule();
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

void Team::saveToFile(std::ofstream& outFile) const {
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

void Team::viewUpcomingGames(int numOfGames) {
    schedule.printUpcomingGames(numOfGames);
}

void Team::simulateNextGame() {
    int userScore = getGameGoals();
    int oppScore = getGameGoals();

    if (userScore > oppScore) {
        cout << "You won the game! Score: " << userScore << "-" << oppScore << endl;
        // Update stats for win
        updatePlayerStats(userScore);
        schedule.markGameAsPlayed();
        schedule.removeNextGame();
    }
    else if (userScore < oppScore) {
        cout << "You lost the game. Score: " << userScore << "-" << oppScore << endl;
        // Update stats for loss
        updatePlayerStats(userScore);
        schedule.markGameAsPlayed();
        schedule.removeNextGame();
    }
    else {
        cout << "The game was a draw. Score: " << userScore << "-" << oppScore << endl;
        // Update stats for draw
        updatePlayerStats(userScore);
        schedule.markGameAsPlayed();
        schedule.removeNextGame();
    }
    
}

//pre: function to get the number of goals scored in a game
//post: return the number of goals scored by one team
int Team::getGameGoals() {
    int gameGoals = rand() % 100;
    int teamScore;

    if (gameGoals < 10) {
        teamScore = 1;
    }
    else if (gameGoals >= 10 && gameGoals < 20) {
        teamScore = 2;
    }
    else if (gameGoals >= 20 && gameGoals < 35) {
        teamScore = 3;
    }
    else if (gameGoals >= 35 && gameGoals < 50) {
        teamScore = 4;
    }
    else if (gameGoals >= 50 && gameGoals < 65) {
        teamScore = 5;
    }
    else if (gameGoals >= 65 && gameGoals < 75) {
        teamScore = 6;
    }
    else if (gameGoals >= 75 && gameGoals < 80) {
        teamScore = 7;
    }
    else if (gameGoals >= 80 && gameGoals < 85) {
        teamScore = 8;
    }
    else {
        teamScore = 0;
    }

    return teamScore;
}


//pre: function that is called after a game with the amount of goals the team scored
//post: updated player stats incl: goals, assists, gamesplayed after the game
void Team::updatePlayerStats(int teamGoalsScored) {

    int goalsDistributed = 0;

    // Distribute goals among players
    while (goalsDistributed < teamGoalsScored) {
        // 65% chance of a forward scoring
        if ((rand() % 100) < 65) {
            int randForward = rand() % NUM_FORWARDS;
            forwards[randForward].incrementGoals(1);
        }
        else {
            int randDefenseman = rand() % NUM_DEFENSEMAN;
            defensemen[randDefenseman].incrementGoals(1);
        }
        goalsDistributed++;
    }

    // Randomly assign assists
    for (int i = 0; i < teamGoalsScored; i++) {
        int randAssists = rand() % 3;
        for (int j = 0; j < randAssists; j++) {
            if ((rand() % 100) < 55) { // 55% chance to assign assist to a forward
                int randForward = rand() % NUM_FORWARDS;
                forwards[randForward].incrementAssists(1);
            }
            else {
                int randDefenseman = rand() % NUM_DEFENSEMAN;
                defensemen[randDefenseman].incrementAssists(1);
            }
        }
    }
  
    goalie.displayStats();
}