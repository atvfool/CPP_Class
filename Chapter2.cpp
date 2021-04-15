//Chips Game
//By: Andrew Hayden
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;
const int MAX_PLAYERS = 2;

int main(){

    bool playersTurn = true;
    bool gameOver = false;
    int chipsInPile = 0;
    int chipTaken = 0;
    string playerName[2];
    int maxChipsToTake = 0;

    cout << "Enter player 1 name\n";
    cin >> playerName[0];

    cout << "Enter player 2 name\n";
    cin >> playerName[1];

    srand(time(0));

    chipsInPile = (rand() % MAX_CHIPS) + 1;
    cout << "This round will start with " << chipsInPile << " chips in the pile \n";

    maxChipsToTake = (chipsInPile * MAX_TURN);
    cout << "You can only take " << maxChipsToTake << endl;

    int randomChipsTaken = (rand() % maxChipsToTake) + 1;
    cout << "Chips Taken: " << randomChipsTaken << endl;

    return 0;
}