// main.cpp
#include <iostream>
#include <cstdio>
#include "RPG.h"
using namespace std;

int main() {
    RPG p1 = RPG("Wiz", 0, 0.2, 60.0, 1);
    RPG p2 = RPG();

    // Print stats for p1
    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n",
           p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());

    // Print stats for p2
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n",
           p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    // CALL setHitsTaken(new_hit) on p1 and p2
    p1.setHitsTaken(3); 
    p2.setHitsTaken(1); 

    cout << p1.getName() << " Hits Taken: " << p1.getHitsTaken() << "\n";
    cout << p2.getName() <<  " Hits Taken: " << p2.getHitsTaken() << "\n";
    cout << "\n0 is dead, 1 is alive\n";
    
    // CALL isAlive() on both p1 and p2
    cout << p1.getName() << ": " << p1.isAlive() << " " << p2.getName() << ": " << p2.isAlive() << "\n";

    return 0;
}
