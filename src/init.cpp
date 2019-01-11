#include "../headers/init.h"
#include "../headers/board.h"
#include "../headers/gameConditions.h"
#include "../headers/cards.h"

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