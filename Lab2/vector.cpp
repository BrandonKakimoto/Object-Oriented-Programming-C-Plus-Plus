#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 */

void printMemVec(vector<int> v[]){
    printf("Vector - Each int is worth %lu bytes\n", vec.size());
}

/**
 * @brief increments all of the elements in v by 10
 * 
 * @param v - address to a vector of integers
 */
void incVecBy10(vector<int>& vec){

}

int main() {
    // create a constant integer called SIZE that is of value 5
    const int SIZE = 5;
    // create a vector of integers called vec that can hold up to 5 elements
    vector<int> vec(5);

    // use a for loop to populate vec with the values 100 to 104
    for(int i = 0; i<5;i++) {
        vec[i]=i+100;
    }

    printf("Before Increment--------------\n");
    //call printMemVec(...) on vec

    //call incBy10(...) on vec


    printf("After Increment---------------\n");
    //call printMemVec(...) on vec again to view the changes


    // remove last element of vec

    printf("After Pop------------------\n");
    //call printMemVec(...) on vec again to view the changes


    // append 101 and 102 at the end of vec

    printf("After Push-----------------\n");
    //call printMemVec(...) on vec again to view the changes

    return 0;

}