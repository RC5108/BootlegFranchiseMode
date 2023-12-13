#ifndef LEAGUESIM_HPP
#define LEAGUESIM_HPP

#include "team.hpp"
using namespace std;

class LeagueSim {
public:
    enum GameResult { WIN, LOSS, TIE };
    GameResult simulateGameOutcome() {
        int result = rand() % 3; // Randomly generates a number between 0 and 2
        return static_cast<GameResult>(result);
    }

    void simulateRound(Team& userTeam, Team& redTeam, Team& blueTeam, Team& greenTeam) {
        userTeam.simulateNextGame();
        simulateOtherTeamGames(redTeam, blueTeam, greenTeam);
    }
    void simulateOtherTeamGames(Team& redTeam, Team& blueTeam, Team& greenTeam);
    
};


#endif // LEAGUESIM_HPP