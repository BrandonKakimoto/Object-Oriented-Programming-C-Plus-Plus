#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

class Game {
    private:
        //Store players as RPG pointers
        std::vector<RPG*> players;

        // Keeps track of which player indices are still alive
        std::set<int> live_players;
    
    public:
        // Constructor and Destructor
        Game();
        ~Game();

        void generatePlayers(int n);
        int selectPlayer();
        void endRound(RPG* winner, RPG* loser, int loserIndex);
        void battleRound();
        void gameLoop();
        void printFinalResults();
};

#endif