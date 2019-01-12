#include <iostream>
#include "../headers/board.h"
#include "../headers/cards.h"

using namespace std;

//create 2 boards.
//board is hidden from the user and auxBoard is shown to the user, "hiding" the main board
char board[4][4];
char auxBoard[4][4];
//Extern the array cards from "cards.cpp"
extern char cards[16];


//Populate the main board with the cards
void populateBoard(){
    int countCards = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i][j] = cards[countCards];
            countCards++; 
        }
    }
   
}

//Populate auxBoard with "#" in order to "hide" the cards in the main board
void populateAuxBoard(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            auxBoard[i][j] = '#';
        }
    }
}

//Print the board
void printBoard(){
    cout << "\t\t\t\t  0 1 2 3" << endl;
    cout << "\t\t\t\t  - - - -" << endl; 
    for(int i = 0; i < 4; i++){
        cout << "\t\t\t\t";
        cout << i << "|";
        for(int j = 0; j < 4; j++){
            cout << auxBoard[i][j] << " ";
        }
        cout << '\n';
    }
}