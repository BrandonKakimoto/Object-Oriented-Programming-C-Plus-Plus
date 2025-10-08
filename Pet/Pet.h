#ifndef Pet_h
#define Pet_h
#include <iostream>
using namespace std;

class Pet {
    private:
        string name;
        int age;
        string owner;
        bool isHouseTrained;

    public:
        // Constructors
        Pet();
        Pet(string name, int age, string owner, bool isHouseTrained);

        // Accessors
        string getName();
        int getAge();
        string getOwner();
        bool getIsHouseTrained();

        // Mutators
        void updateName(string name);
        void updateAge();
        void updateOwner(string adopter);
        void setHouseTrained();

};
#endif