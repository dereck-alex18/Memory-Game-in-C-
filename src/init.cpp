#include "../headers/init.h"
#include "../headers/board.h"
#include "../headers/gameConditions.h"
#include "../headers/cards.h"

//The function is responsible for managing all the game functionality. It calls the other functions
void init(){
    do{
        srand(time(NULL));
        populateCards();
        populateBoard();
        populateAuxBoard();
        printBoard();
        playing();
    
    }while(!endGame());
    
}