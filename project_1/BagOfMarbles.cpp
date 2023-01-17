#include <iostream>
using namespace std;

class Marble {          // Defining the class
public:                 // Access specifier 
                        // Declaring the two attributes of the marble
    int num;            // Declaring number attribute
    char color;         // Declaring color attribute

};




int main() {
    Marble marbles[10];         // I'm trying to create a set of 10 marbles
                                // and append them to an array. 
    for(int i=0; i < 10; i++) { // for loop to loop through 10 times(each marble)
        int num = 1;            // Declaring int and setting it to one
        num+=1;                 // Adding 1 each time for a unique number per marble
        
        marbles[i] = Marble();
        cout << marbles << "\n";

    }

}