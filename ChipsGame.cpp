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

    char playAgain = 'n';
    string playerName[2];
    bool player1Turn = true;
    bool gameOver = false;
    int chipsInPile = 0;
    int chipsTaken = 0;
    int maxChipsToTake = 0;

    // Get the players names
    cout << "Enter player 1 name\n";
    cin >> playerName[0];

    cout << "Enter player 2 name\n";
    cin >> playerName[1];

    srand(time(0));

    // Play again loop
    do{
        chipsInPile = (rand() % MAX_CHIPS) + 1;
        cout << "This round will start with " << chipsInPile << " chips in the pile \n";
        gameOver = false;
        while(!gameOver){
            maxChipsToTake = (chipsInPile * MAX_TURN); // get the number of chips that can be taken this round
            
            do{
                if(player1Turn){
                    cout << playerName[0] << " how many chips would you like?\n";
                }else{
                    cout << playerName[1] << " how many chips would you like?\n";
                }
                cout << "You can take up to ";
                if(maxChipsToTake == 0)
                    cout << "1\n";
                else
                    cout << maxChipsToTake << endl;
                cin >> chipsTaken;
            }while(chipsTaken > maxChipsToTake && chipsInPile > 1);

            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " left in the pile\n";

            // Check if the win conditions are met
            if(chipsInPile == 0){
                gameOver = true;
            }else{
                player1Turn = !player1Turn; // flip whos turn it is when game isn't over
            }
            
        }
        if(player1Turn)
            cout << "Congrats " << playerName[1] << " on winning!\n";
        else
            cout << "Congrats " << playerName[0] << " on winning!\n";

        cout << "Do you want to play again?Yes(y), No(n)\n";
        cin >> playAgain;
    }while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}