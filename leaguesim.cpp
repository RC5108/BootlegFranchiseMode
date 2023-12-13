#include "leaguesim.hpp"

// pre: A function to simulate games for non-user teams (red, blue, and green teams)
// post: Updates the win, loss, and tie records of each of the non-user teams based on simulated game outcomes
void LeagueSim::simulateOtherTeamGames(Team& redTeam, Team& blueTeam, Team& greenTeam) {
    GameResult redResult = simulateGameOutcome();
    GameResult blueResult = simulateGameOutcome();
    GameResult greenResult = simulateGameOutcome();

    // Update stats based on game outcomes
    if (redResult == WIN) {
        redTeam.recordWin();
    }
    else if (redResult == LOSS) {
        redTeam.recordLoss();
    }
    else {
        redTeam.recordTie();
    }
    if (blueResult == WIN) {
        blueTeam.recordWin();
    }
    else if (blueResult == LOSS) {
        blueTeam.recordLoss();
    }
    else {
        blueTeam.recordTie();
    }
    if (greenResult == WIN) {
        greenTeam.recordWin();
    }
    else if (greenResult == LOSS) {
        greenTeam.recordLoss();
    }
    else {
        greenTeam.recordTie();
    }
}