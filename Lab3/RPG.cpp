// RPG.cpp
#include "RPG.h"

// Default constructor
RPG::RPG()
    : name("NPC"), hits_taken(0), luck(0.1), exp(50.0), level(1) {}

// Overloaded constructor
RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
    : name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {}

// Mutators
void RPG::setHitsTaken(int new_hits) {
    hits_taken = new_hits;
}

bool RPG::isAlive() const {
    // A player is alive as long as they have not been hit MAX_HITS_TAKEN times
    return hits_taken < MAX_HITS_TAKEN;
}

// Accessors
string RPG::getName() const { return name; }
int    RPG::getHitsTaken() const { return hits_taken; }
float  RPG::getLuck() const { return luck; }
float  RPG::getExp() const { return exp; }
int    RPG::getLevel() const { return level; }
