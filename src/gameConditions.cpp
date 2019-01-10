#include "../headers/gameConditions.h"
#include "../headers/board.h"
#include "../headers/cards.h"
#include <time.h>
#include <iostream>

using namespace std;


extern char board[4][4];
extern char auxBoard[4][4];

void playing(){
    
    while(!verifyEndGame()){
        
        int r1, c1, r2, c2;

        cout << "Enter the coordinates, separated by space, corresponding the first card you wanna flip" << endl;
        cout << "Example: 0 1 will flip the card at row 0 column 1" << endl;
        cout << "Coordinates: " << endl;
        
        do{
            cin >> r1;
            cin >> c1;
            cout << "Enter a number between 0 and 3!" << endl;
        }while(r1 > 3 || r1 < 0 || c1 < 0 || c1 > 3);

        while(auxBoard[r1][c1] == board[r1][c1]){
            cout << "You already chose this card! Choose another one!" << endl;
            cin >> r1;
            cin >> c1;
        }

        auxBoard[r1][c1] = board[r1][c1];
        printBoard();

        cout << endl;
        cout << "Enter the coordinates, separated by space, corresponding the second card you wanna flip" << endl;
        cout << "Example: 0 1 will flip the card at row 0 column 1" << endl;
        cout << "Coordinates: " << endl;
        
        do{
            cin >> r2;
            cin >> c2;
            cout << "Enter a number between 0 and 3!" << endl;
        }while(r2 > 3 || r2 < 0 || c2 < 0 || c2 > 3);

        while(auxBoard[r2][c2] == board[r2][c2]){
            cout << "You already chose this card! Choose another one!" << endl;
            cin >> r2;
            cin >> c2;
        }

        auxBoard[r2][c2] = board[r2][c2];
        printBoard();

        if(auxBoard[r1][c1] != auxBoard[r2][c2]){
            auxBoard[r1][c1] = '#';
            auxBoard[r2][c2] = '#';
            cout << "WRONG!!!!!" << endl;
            delay();
            system("clear");
            printBoard();
        }

        cout << "ending!" << endl;

   }

}

void delay(){
    int sec = 2;
    clock_t endwait;
    endwait = clock() + sec * CLOCKS_PER_SEC;
    while(clock() < endwait){}
}

bool verifyEndGame(){
    bool verification = false;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(auxBoard[i][j] != board[i][j]){
                return verification;
            }
        }
    }
    verification = true;

    return verification;
}