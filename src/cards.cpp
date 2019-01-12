#include "../headers/cards.h"

char cards[16];

//This function returns a char pointer and is responsible for randomize the ASCII table characters
char* randomCard(){
    char* random = new char[16];
    for(int i = 0; i < 8; i++){
        //Pick a number between 36 and 125, which represents a character on ASCII table
        random[i] = rand() % 90 + 36;
        //This block of code ensures that there is no repeated character in the cards array.
        for(int j = 0; j < i; j++){
            while(random[j] == random[i]){
                //If a repeated character was chosen, another number will be picked
                random[i] = rand() % 90 + 36;
                j = 0;
                
            }
        }
       
    }
    //Fill the other half of the cards array with the same characters as the first half
    //This for loop "mirrors" the array, just to have pairs of character instead of one single character
    //Otherwise, it would be impossible to finish the game with one character without its pair on the board
    for(int i = 0, j = 8; i < 8; i++, j++ ){
        random[j] = random[i];
    }
    
    //return the array filled with pairs of characters
    return random;
}

//This function just populate the cards array
void populateCards(){
    char* ptrRandom = randomCard();
    
    int counter = 0;
    for(int i = 0; i < sizeof(cards); i++){
        
        cards[i] = ptrRandom[i];
    }
    randomizeCards();
    delete ptrRandom;
    ptrRandom = NULL;
   
}

//This function shuffle the cards array, just to make sure that the characters will not always be
//in the same order on the board
void randomizeCards(){
    for(int i = 0; i < 16; i++){
        int index = rand() % 16;
        char temp = cards[i];
        cards[i] = cards[index];
        cards[index] =  temp;
    }
     
}