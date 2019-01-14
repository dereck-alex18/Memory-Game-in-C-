This project is a Memory Game with ASCII table characters. The board consists of 4 rows and 4 columns and initially, all the cards are hidden from the user. To play the game the user has to enter 2 pairs of coordinates. One pair to flip the first card, the other to flip another card. The game works exactly the same as the common memory game if the player flips two cards and they are equal, those will remain flipped. Otherwise, they will be hidden again.

The following is an example on how to play the game:

The board:
    # # # #
    # # # #
    # # # #
    # # # #

The user enters the pair of coordinates to flip the desired card:
0 0 ---> first row first column

The board:
    a # # #
    # # # #
    # # # #
    # # # #

Now the user enters the second pair of coordinates:
 0 1 ---> first row second column

 The board:
    a b # #
    # # # #
    # # # #
    # # # #

The cards are different, then they will be hidden again

The board:
    # # # #
    # # # #
    # # # #
    # # # #

Note: The cards are not always equal, each round the board is filled with different characters in different positions