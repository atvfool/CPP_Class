//Chips Game
//By: Andrew Hayden
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

// Prototypes
string GetPlayerName(string[], bool);
int AskMove(bool, int, string[]);
int CalcMaxChips(int);
void GetUserNames(string[]);

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

    // Get the players names
    GetUserNames(playerName);

    srand(time(0));

    // Play again loop
    do{
        chipsInPile = (rand() % MAX_CHIPS) + 1;
        cout << "This round will start with " << chipsInPile << " chips in the pile \n";
        gameOver = false;
        while(!gameOver){
            // Get how many chips the player has taken
            chipsTaken = AskMove(player1Turn, chipsInPile, playerName);
            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " left in the pile\n";

            // Check if the win conditions are met
            if(chipsInPile == 0){
                gameOver = true;
            }else{
                player1Turn = !player1Turn; // flip whos turn it is when game isn't over
            }   
        }
        
        cout << "Congrats " << GetPlayerName(playerName, !player1Turn) << " on winning!\n";

        cout << "Do you want to play again?Yes(y), No(n)\n";
        cin >> playAgain;
    }while (tolower(playAgain) == 'y');
    
    return 0;
}

string GetPlayerName(string names[], bool playerTurn){
    string name;
    
    if(playerTurn)
        name = names[0];
    else
        name = names[1];
    
    return name;
}

int AskMove(bool player1Turn, int chipsInPile, string names[]){
    int chipsTaken = 0;
    int maxChips = CalcMaxChips(chipsInPile);
    do{
        cout << GetPlayerName(names, player1Turn) << " how many chips would you like?\n";
        cout << "You can take up to ";
        if(maxChips == 0)
            cout << "1\n";
        else
            cout << maxChips << endl;
        if(GetPlayerName(names, player1Turn) == "AI"){
            if(maxChips == 0)
                chipsTaken = 1;
            else
                chipsTaken = (rand() % maxChips) + 1;
        }else{
            cin >> chipsTaken;
        }
    }while(chipsTaken > maxChips && chipsInPile > 1);
    return chipsTaken;
}

int CalcMaxChips(int chipsInPile){
    int maxChips = chipsInPile * MAX_TURN;
    return maxChips;
}

void GetUserNames(string players[]){
    cout << "Enter player 1 name\n";
    cin >> players[0];

    cout << "Enter player 2 name (If you wish to play against the computer enter the name AI)\n";
    cin >> players[1];
}