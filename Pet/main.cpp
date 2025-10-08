#include "Pet.h"
#include <iostream>
using namespace std;

void getInfo(Pet pet) {
    cout << "Name: " << pet.getName() << " | Age: " << pet.getAge() << " | Owner: " << pet.getOwner() << " | House Trained: " << pet.getIsHouseTrained() << "\n";
}

int main() {
    Pet dog = Pet();
    Pet cat = Pet("Momo", 5, "Brandon", false);

    getInfo(dog);
    getInfo(cat);

    cat.updateName("Mochi");
    cat.updateAge();
    cat.updateOwner("Mihir");
    cat.setHouseTrained();
    
    getInfo(cat);
}