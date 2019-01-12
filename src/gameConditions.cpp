#include "../headers/gameConditions.h"
#include "../headers/board.h"
#include "../headers/cards.h"
#include <time.h>
#include <iostream>

using namespace std;

//Extern board and auxBoard from "board.cpp"
extern char board[4][4];
extern char auxBoard[4][4];

//This function is the game loop, it will control everything related to the inputs, if the cards
//are equal or not and even how many moves the user needed to finish the game
void playing(){
    
    int moves = 0;

    //While verifyEndGame returns true, this loop will run continuously
    while(!verifyEndGame()){
        
        //Those variables will contain the coordinates of each card the user wanna flip.
        int r1, c1, r2, c2;
        
        cout << "Enter the coordinates, separated by space, corresponding the first card you wanna flip" << endl;
        cout << "Example: 0 1 will flip the card at row 0 column 1" << endl;
        cout << "Coordinates: " << endl;
        
        checkInputs(r1, c1);

        //The chosen row and column of auxBoard will pick the character at the same row and column on the original board
        auxBoard[r1][c1] = board[r1][c1];
        printBoard();

        cout << endl;
        cout << "Enter the coordinates, separated by space, corresponding the second card you wanna flip" << endl;
        cout << "Example: 0 1 will flip the card at row 0 column 1" << endl;
        cout << "Coordinates: " << endl;
        
        checkInputs(r2, c2);

        //The chosen row and column of auxBoard will pick the character at the same row and column on the original board
        auxBoard[r2][c2] = board[r2][c2];
        printBoard();

        if(auxBoard[r1][c1] != auxBoard[r2][c2]){
            //If the characters are not the same, theu are hidden again
            auxBoard[r1][c1] = '#';
            auxBoard[r2][c2] = '#';
            cout << "WRONG!!!!!" << endl;
            delay();
            system("clear");
            printBoard();
        }

        //count the moves
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

//Verify if the game was finished by comparing the board to auxBoard
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

//check the input from the user, to make sure that the game will not crash
void checkInputs(int &r, int &c){
    
    bool check = false;
    cin >> r;
    cin >> c;
    
    while(!check){
        //check if the user entered a valid interger
        if(!cin.good()){
            
            cin.clear();
            cin.ignore(__INT_MAX__, '\n');
            cout << "Please enter valid integer NUMBERS!!!" << endl;
            
        //check if the user entered a value in the range of the coordinates
        }else if(r > 3 || r < 0 || c < 0 || c > 3){
            
            cout << "Enter a number between 0 and 3!" << endl;
        //make sure that a card is not chosen twice    
        }else if(auxBoard[r][c] == board[r][c]){
            
            cout << "You already chose this card! Choose another one!" << endl;
            
        }else{
            //If the input is valid, the loop stops
            check = true;
            break;
        }

        cin >> r;
        cin >> c;
    }
    cin.clear();
    cin.ignore(__INT_MAX__, '\n');
}

//This function just handles the end game. In the and, the user is asked if he or she wants to play again
//if so, the all process will start again
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