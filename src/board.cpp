#include <iostream>
#include "../headers/board.h"
#include "../headers/cards.h"

using namespace std;

char board[4][4];
char auxBoard[4][4];
extern char cards[16];



void populateBoard(){
    int countCards = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[i][j] = cards[countCards];
            countCards++; 
        }
    }
   
}

void populateAuxBoard(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            auxBoard[i][j] = '#';
        }
    }
}

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