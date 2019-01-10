#include "../headers/cards.h"

char cards[16];
char* randomCard(){
    char* random = new char[16];
    for(int i = 0; i < 8; i++){
        random[i] = rand() % 90 + 36;
        for(int j = 0; j < i; j++){
            while(random[j] == random[i]){
                random[i] = rand() % 90 + 36;
                j = 0;
                
            }
        }
       
    }
    for(int i = 0, j = 8; i < 8; i++, j++ ){
        random[j] = random[i];
    }
    
    
    return random;
}

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

void randomizeCards(){
    for(int i = 0; i < 16; i++){
        int index = rand() % 16;
        char temp = cards[i];
        cards[i] = cards[index];
        cards[index] =  temp;
    }
     
}