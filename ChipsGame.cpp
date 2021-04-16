//Chips Game
//By: Andrew Hayden
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>
#include <fstream>

using namespace std;

struct Player{
    string Name;
    int Wins = 0;
};

// Prototypes
Player GetPlayer(Player[], bool);
int AskMove(bool, int, Player[]);
int CalcMaxChips(int);
void GetUserNames(Player[]);
void WriteResultsToFile(string, int);
void AddWins(Player players[], bool player1Turn);

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;
const int MAX_PLAYERS = 2;

int main(){

    char playAgain = 'n';
    Player players[2];
    bool player1Turn = true;
    bool gameOver = false;
    int chipsInPile = 0;
    int chipsTaken = 0;
    int numMoves = 0; // not sure if the number of moves should include both players moves or just one players moves? Assuming both.

    // Get the players names
    GetUserNames(players);

    srand(time(0));

    // Play again loop
    do{
        chipsInPile = (rand() % MAX_CHIPS) + 1;
        cout << "This round will start with " << chipsInPile << " chips in the pile \n";
        gameOver = false;
        numMoves = 0;
        while(!gameOver){
            // Get how many chips the player has taken
            chipsTaken = AskMove(player1Turn, chipsInPile, players);
            numMoves += 1;
            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " left in the pile\n";

            // Check if the win conditions are met
            if(chipsInPile == 0){
                gameOver = true;
            }
            player1Turn = !player1Turn; // flip whos turn it is
        }
        
        // Congratulate the winner
        cout << "Congrats " << GetPlayer(players, player1Turn).Name << " on winning!\n";
        // Save the results to a file
        WriteResultsToFile(GetPlayer(players, player1Turn).Name, numMoves);
        // record number of wins for this session
        AddWins(players, player1Turn);

        cout << "Do you want to play again?Yes(y), No(n)\n";
        cin >> playAgain;
    }while (tolower(playAgain) == 'y');
    
    cout << "Session results: \n";
    cout << players[0].Name << " won " << players[0].Wins << " games\n";
    cout << players[1].Name << " won " << players[1].Wins << " games\n";

    return 0;
}

Player GetPlayer(Player players[], bool playerTurn){
    Player player;
    if(playerTurn)
        player = players[0];
    else
        player = players[1];
    return player;
}

int AskMove(bool player1Turn, int chipsInPile, Player players[]){
    int chipsTaken = 0;
    int maxChips = CalcMaxChips(chipsInPile);
    do{
        cout << GetPlayer(players, player1Turn).Name << " how many chips would you like?\n";
        cout << "You can take up to ";
        if(maxChips == 0)
            cout << "1\n";
        else
            cout << maxChips << endl;
        if(GetPlayer(players, player1Turn).Name == "AI"){
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

void GetUserNames(Player players[]){
    cout << "Enter player 1 name\n";
    cin >> players[0].Name;

    cout << "Enter player 2 name (If you wish to play against the computer enter the name AI)\n";
    cin >> players[1].Name;
}

void WriteResultsToFile(string winnerName, int numberOfMoves){
    ofstream outputFile;
    outputFile.open("ChipsGameResults.csv", ios::app);
    // This is how i think the challenge will be anwered but i'd prefer to enter the results in a csv format
    // outputFile << winnerName << " won in " << numberOfMoves << " moves\n";
    outputFile << winnerName << ',' << numberOfMoves << endl;
    outputFile.close();
}

void AddWins(Player players[], bool player1Turn){
    if(player1Turn)
        players[0].Wins++;
    else
        players[1].Wins++;
}