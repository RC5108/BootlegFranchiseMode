#include "team.hpp"
#include "randomname.hpp"
// Constructor that builds the users team 
Team::Team(const string& name, Forward f[], Defenseman d[], Goalie g) {
    schedule.generateSchedule();
    teamName = name;
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

    gamesSimulated = 0;
}


Team::Team(const string& name) {
    schedule.generateSchedule();
    teamName = name;
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

    gamesSimulated = 0;
}

Team::Team() {
    schedule.generateSchedule();
    teamName = "User Team";
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

    gamesSimulated = 0;
}

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
    int playerNumber = player.getNumber();
    if (existingNumber.find(playerNumber) == existingNumber.end()) {
        // Player number does not exist, generate a new unique number
        playerNumber = RandomName::generateUniqueNumber(existingNumber);
        player.setNumber(playerNumber);
    }
    // The number already exists or is newly generated, add it to the set
    existingNumber.insert(playerNumber);
    players.push_back(player);
}

void Team::viewUpcomingGames(int numOfGames) {
    schedule.printUpcomingGames(numOfGames);
}

//pre: will simulate the next game on the schedule
//post: will dislplay the score of the game and update neccessary stats/records
void Team::simulateNextGame() {
    if (gamesSimulated >= 20) {
        cout << "Season complete. View Standings to see results." << endl;
        return;
    }

    int userScore = getGameGoals();
    int oppScore = getGameGoals();

    if (userScore > oppScore) {
        cout << "You won the game! Score: " << userScore << "-" << oppScore << endl;
        // Update stats for win
        updatePlayerStats(userScore, oppScore);
        schedule.markGameAsPlayed();
        schedule.removeNextGame();
        goalie.recordWin();
        recordWin();
    }
    else if (userScore < oppScore) {
        cout << "You lost the game. Score: " << userScore << "-" << oppScore << endl;
        // Update stats for loss
        updatePlayerStats(userScore, oppScore);
        schedule.markGameAsPlayed();
        schedule.removeNextGame();
        goalie.recordLoss();
        recordLoss();
    }
    else {
        cout << "The game was a draw. Score: " << userScore << "-" << oppScore << endl;
        // Update stats for draw
        updatePlayerStats(userScore, oppScore);
        schedule.markGameAsPlayed();
        schedule.removeNextGame();
        goalie.recordTie();
        recordTie();
    }
    gamesSimulated++;
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
void Team::updatePlayerStats(int teamGoalsScored, int teamGoalsAgainst) {

    int goalsDistributed = 0;

    for (Forward& forward : forwards) {
        forward.incrementGP();
    }
    for (Defenseman& defenseman : defensemen) {
        defenseman.incrementGP();
    }
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

    //random number of saves 
    int randShots = rand() % 50 + teamGoalsAgainst;

    goalie.incrementgoalsAgainst(teamGoalsAgainst);
    goalie.incrementSaves(randShots - teamGoalsAgainst);
    goalie.incrementGP();
    goalie.updateSavePercentage();
    goalie.updateGAA();


}

void Team::writePlayerStatsToFile(const string filename) {
    ofstream outFile(filename, std::ios::out); // Open in overwrite mode

    if (!outFile.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    // Write stats for forwards
    for (const auto& forward : forwards) {
        forward.saveToFile(outFile);
    }

    // Write stats for defensemen
    for (const auto& defenseman : defensemen) {
        defenseman.saveToFile(outFile);
    }

    // Write stats for goalie
    goalie.saveToFile(outFile);

    outFile.close();

}

void Team::displayStandings(const Team& userTeam, const Team& redTeam, const Team& blueTeam, const Team& greenTeam) {
    cout << "Standings: " << endl;
    vector<TeamData> teams = {
        {userTeam.getName(), userTeam.getWins(), userTeam.getLosses(), userTeam.getTies()},
        {"Red Team", redTeam.getWins(), redTeam.getLosses(), redTeam.getTies()},
        {"Blue Team", blueTeam.getWins(), blueTeam.getLosses(), blueTeam.getTies()},
        {"Green Team", greenTeam.getWins(), greenTeam.getLosses(), greenTeam.getTies()}
    };

    sort(teams.begin(), teams.end(), [](const TeamData& a, const TeamData& b) {
        return a.points > b.points; // sort in descending order of points
        });

    for (const auto& team : teams) {
        cout << team.name << " - Wins: " << team.wins << ", Losses: " << team.losses << ", Ties: " << team.ties << ", Points: " << team.points << endl;
    }

    if (userTeam.getWins() + userTeam.getLosses() + userTeam.getTies() == 20) {
        // Check if user's team has the best record
        if (!teams.empty() && teams.front().name == userTeam.getName()) {
            cout << "----------------------------------------------------------------" << endl;
            cout << "|Congratulations! You finished the season with the best record!|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
        else {
            cout << "Season over. Better luck next time!" << endl;
        }
    }
}



//FIXME: Function does not seem to populate team with loaded data
// Program loaded players from file perfectly fine before implementation of this function
// 
//pre: take in a file containing a team
//post: load data from file to re-use same team
void Team::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }
    else {
        cout << "Successfully opened file: " << filename << endl;
    }

    // Reset current team data
    players.clear();
    wins = 0;
    losses = 0;
    ties = 0;
    points = 0;

    // Read data and construct players
    string line;
    while (getline(inFile, line)) {
        cout << "Reading line: " << line << endl;
        istringstream iss(line);
        string token;
        vector<string> tokens;

        while (getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Parse and create player objects
        if (!tokens.empty()) {
            cout << "Processing tokens" << endl;
            string playerType = tokens[0];
            string name = tokens[1];
            int number = stoi(tokens[2]);
            int speed = stoi(tokens[3]);
            int overall = stoi(tokens[4]);

            if (playerType == "Forward" || playerType == "Defenseman") {
                int gamesPlayed = stoi(tokens[5]);
                int goals = stoi(tokens[6]);
                int assists = stoi(tokens[7]);
                int points = stoi(tokens[8]);
                int pim = stoi(tokens[9]);
                int hits = stoi(tokens[10]);

                if (playerType == "Forward") {
                    int count = 1;
                    Forward f(name, speed, number, overall, goals, assists, pim, hits, gamesPlayed);
                    addPlayer(f);
                    cout << "forward" << count << "added" << endl;
                    count++;
                }
                else {
                    int count = 1;
                    Defenseman d(name, speed, number, overall, goals, assists, pim, hits, gamesPlayed);
                    addPlayer(d);
                    cout << "forward" << count << "added" << endl; 
                    count++;
                }
            }
            else if (playerType == "Goalie") {
                int saves = stoi(tokens[5]);
                double savePercentage = stod(tokens[6]);
                double goalsAgainst = stod(tokens[7]);
                int wins = stoi(tokens[8]);
                int losses = stoi(tokens[9]);
                int ties = stoi(tokens[10]);

                Goalie g(name, speed, number, overall, saves, savePercentage, goalsAgainst, wins, losses, ties);
                addPlayer(g);
                cout << "goalie added" << endl;
            }
        }
        else {
            cout << "No tokens found in line" << endl;
        }
    }
    inFile.close();
}

