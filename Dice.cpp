// Dice Roller

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(){
    srand(time(0));

    int numOfSide = 0;

    do{
        cout << "Enter a number of sides on the dice:\n";
        cin >> numOfSide;
    }while(numOfSide == 0);

    int roll = (rand() % numOfSide) + 1;

    cout << "The " << numOfSide << " sided die rolled a " << roll << endl;

    return 0;
}