#include "../headers/gameConditions.h"
#include "../headers/board.h"
#include "../headers/cards.h"
#include <time.h>
#include <iostream>

using namespace std;


extern char board[4][4];
extern char auxBoard[4][4];

void playing(){
    
    int moves = 0;

    while(!verifyEndGame()){
        
        int r1, c1, r2, c2;
        
        cout << "Enter the coordinates, separated by space, corresponding the first card you wanna flip" << endl;
        cout << "Example: 0 1 will flip the card at row 0 column 1" << endl;
        cout << "Coordinates: " << endl;
        
        checkInputs(r1, c1);

        auxBoard[r1][c1] = board[r1][c1];
        printBoard();

        cout << endl;
        cout << "Enter the coordinates, separated by space, corresponding the second card you wanna flip" << endl;
        cout << "Example: 0 1 will flip the card at row 0 column 1" << endl;
        cout << "Coordinates: " << endl;
        
        checkInputs(r2, c2);

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

        moves++;
        cout << "Moves: " << moves << endl;
    }
    cout << "Total moves: " << moves << endl;

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

void checkInputs(int &r, int &c){
    
    bool check = false;
    cin >> r;
    cin >> c;
    
    while(!check){
        
        if(!cin.good()){
            
            cin.clear();
            cin.ignore(__INT_MAX__, '\n');
            cout << "Please enter valid integer NUMBERS!!!" << endl;
            
        }else if(r > 3 || r < 0 || c < 0 || c > 3){
            
            cout << "Enter a number between 0 and 3!" << endl;
            
        }else if(auxBoard[r][c] == board[r][c]){
            
            cout << "You already chose this card! Choose another one!" << endl;
            
        }else{
            check = true;
            break;
        }

        cin >> r;
        cin >> c;
    }
}

bool endGame(){
    cout << "Congratulations!!! you managed to finish the game!" << endl;
    cout << "Would you like to play again?" << endl;
    cout << "(y) - Yes || (anything) - No" << endl;
    
    char ans = ' ';
    cin >> ans;
    if(ans == 'y' || ans == 'Y'){
        return false;
    }else{
        cout << "See you next time! :)" << endl;
        return true;
    }
}