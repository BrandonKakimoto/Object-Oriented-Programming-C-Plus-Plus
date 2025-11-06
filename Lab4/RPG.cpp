#include "RPG.h"
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

RPG:: RPG()
    :name("NPC"), hits_taken(0), luck(0.1), exp(50.0), level(1) {
    }
RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
    :name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {
    }


void RPG::setHitsTaken(int new_hits) {hits_taken = new_hits;}
bool RPG::isAlive() const {return hits_taken < MAX_HITS_TAKEN;}

string RPG::getName() const {return name;}
int RPG::getHitsTaken() const {return hits_taken;}
float RPG::getLuck() const {return luck;}
float RPG::getExp() const {return exp;}
int RPG::getLevel() const {return level;}

/*********************EXTENDED FUNCTION *****************/
/**
 * @brief updates name
 * 
 * @param name
 */

void RPG::setName(string name) {
    this->name = name;
    }

    /**
     * @brief increase RPG's experience by 50
     *        After updating, if RPG's experience is >= 100.0, increase RPG's level by 1, reset
     *        their experience to 0, and increase their luck by 0.1
     */

void RPG::updateExpLevel() {
    exp += 50;
    if (exp >= 100.0) {
        exp = 0.0;
        level += 1;
        luck += 0.1;
    }
}

/**
 * @brief Hits or misses the opponent at random. Luck is a form of defense. The higher the 
 * opponent's luck, the more likely the attack will miss. If the attack is a hit, opponent's
 * hits taken should increment by 1. Add last couple of lines to complete.
 * 
 * @param opponent: RPG *
 */

void RPG::attack (RPG * opponent) {
    random_device rd;
    mt19937 gen(rd()); // seed with randon
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    // Create a bool called hit
    // hit is true if random_num > HIT_FACTOR * opponent's luck
    bool hit = (random_num > HIT_FACTOR * opponent->getLuck());

    // if hit is true, call updateHitsTaken() to increase opponent's hits_taken
    if (hit) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }
}


    /**
     * @brief Prints in the format:
     * "Name: NPC_X     Hits Taken: X   Luck: 0.X00000  Exp: X0.000000  Level: X    Status: Alive or Dead" 
     */

    void RPG::printStats() const{
        cout << fixed << setprecision(6);
        cout << "Name: " << name 
                << "   Hits Taken: " << hits_taken 
                << "   Luck: " << luck 
                << "   Exp: " << exp
                << "   Level: " << level
                << "   Status: ";
        if (isAlive()) {
            cout << "Alive";
        }
        else {
            cout << "Dead";
        }
        cout << endl;    
        }       

/**
 * @brief Destroy the RPG::RPG object
 * Already completed
 */
// Destructor
RPG::~RPG() {
}



