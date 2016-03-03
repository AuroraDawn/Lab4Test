/*
createDeck.c

Author: Emily Sandness
History:
02 Mar 2016 - Initial Version.
*/

#include "pokerHeader.h"

/*
TODO - fill this comment out
Creates a deck of 52 cards (unshuffled).
Assumes ?
how it changes parameters or heap memory
*/
void createDeckEGS(CARD deck[]) {
  short i;

  //create each card in order
  for (i = 0; i < CARDS_IN_DECK; i++) {

    //create the face of the card (1-13)
    deck[i].face = (i % CARDS_IN_SUIT);
    //create the suit of the card (0-3)
    deck[i].suit = i / CARDS_IN_SUIT;
  }
}