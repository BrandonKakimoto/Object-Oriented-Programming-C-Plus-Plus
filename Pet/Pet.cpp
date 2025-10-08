#include "Pet.h"

Pet::Pet()
    : name("unknown"), age(0), owner("no one"), isHouseTrained(false) {
    }

Pet::Pet(string name, int age, string owner, bool isHouseTrained)
    : name(name), age(age), owner(owner), isHouseTrained(isHouseTrained) {
    }

string Pet::getName() {return name; }
int Pet::getAge() {return age;}
string Pet::getOwner() {return owner;}
bool Pet::getIsHouseTrained() {return isHouseTrained;}

void Pet::updateName(string name) {this->name=name;}
void Pet::updateAge() {this->age++;}
void Pet::updateOwner(string adopter) {this->owner=adopter;}
void Pet::setHouseTrained() {this->isHouseTrained = true;}



