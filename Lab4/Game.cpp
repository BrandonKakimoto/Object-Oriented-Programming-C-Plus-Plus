//Game.cpp
#include "Game.h"
#include <iostream>
#include <random>
using namespace std;

Game::Game(){
}

/**
 * @brief Creates up to n RPG pointers and updates names with ordering.
 * Populates live_players from 0 to n - 1 as all players are alive initially
 * 
 * @param n : number of players
 * 
 */

void Game::generatePlayers(int n) {
    for (int i = 0; i < n; i++) {
        players.push_back(new RPG());

        // rename players
        string new_name = "NPC_"+to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

/**
 * @brief Randomly selects a player (via index) from the set of
 * alive players, live_players
 * 
 * @return int: index for vector, players
 */

int Game::selectPlayer() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);

    // Pick random index
    int randomIndex = dist(gen);

    // Advance iterator to that index
    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);

    int selectedIndex = *it;
    return selectedIndex;
}


/**
 * @brief Resets winner's hits_taken to 0.
 * Removes the loser from the live_players.
 * Calls updateExpLevel() for the winner
 * Prints the structure "NPC_X won against NPC_Y"
 * 
 * @param winner : pointer to RPG winner
 * @param loser : pointer to RPG winner
 * @param loserIndex : int index of loser, so that it can be removed from live_players
 * 
 */

void Game::endRound(RPG *winner, RPG *loser, int loserIndex) {
    winner->setHitsTaken(0);
    winner->updateExpLevel();
    live_players.erase(loserIndex);
    cout << winner->getName() << " won against " << loser->getName() << endl;
}


/**
 * @brief calls selectPlayer() twice to get 2 players at random. If the players
 * are redundant make a recursive call to battleRound() and return.
 * Run a round of hits across player1 and player2 until only 1 is alive.
 * Call endRound() to highlight who won and update stats
 * 
 */

void Game::battleRound() {
    // Call selectPlayer twice and assign the values to playerIndex1 and playerIndex2
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();

    // If playerIndex1 and playerIndex2 are the same, call battleRound() again and
    // return within the if-statement
    if (playerIndex1 == playerIndex2) {
        battleRound();
        return;
    }

    // Create two RPG * called player1 and player 2 using players[playerIndex...]
    RPG* player1 = players[playerIndex1];
    RPG* player2 = players[playerIndex2];


    // While both players are alive call player1->attack(player2) and vice versa
    while (player1->isAlive() && player2->isAlive()) {
        player1->attack(player2);
        if (!player2->isAlive()) break;

    }
    // Outside of the while loop, identify which player is alive
    // And Call endRound with for the correct respective players.
    if (player1->isAlive() && !player2->isAlive()) {
        endRound(player1, player2, playerIndex2);
    } 
    else if (!player1->isAlive() && player2->isAlive()) {
        endRound(player2, player1, playerIndex1);
    }
    

 }

 /**
  * @brief Runs battleRound() until there is only 1 player alive. 
  * Remember that endRound() shrinks the size of live_players
  * 
  */

void Game::gameLoop() {
    while(live_players.size() > 1) {
        battleRound();
    }

}

/**
 * @brief Calls printStats on all the players
 * 
 */

void Game::printFinalResults() {
    for(int i = 0; i < players.size(); i++) {
        players[i]->printStats();
    }
}

/**
 * @brief Destroy the Game::Game object
 * 
 */
Game::~Game() {
}
    
