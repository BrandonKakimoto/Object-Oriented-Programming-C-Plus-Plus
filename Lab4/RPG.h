#ifndef RPG_H
#define RPG_H
#include <iostream>
#include <string>
using namespace std;

//global variables
const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

class RPG {
    private:
        // Private Variables
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;

    public:
        // Constructors
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);

        // Destructor
        ~RPG();

        // Mutators
        bool isAlive() const;
        void setHitsTaken(int new_hits);
        void setName(string name);
        void updateExpLevel();
        void attack(RPG* opponent);

        // Accessors
        string getName() const;
        int getHitsTaken() const;
        float getLuck() const;
        float getExp() const;
        int getLevel() const;

        // Print stats
        void printStats() const;

};

#endif