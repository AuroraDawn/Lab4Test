/*
createDeckEGS.c
Creates a deck of 52 cards (unshuffled).

Author: Emily Sandness
History:
02 Mar 2016 - Initial Version.
03 Mar 2016 - Fixed create bug.
*/

#include "pokerHeader.h"

/*
TODO - fill this comment out
what does it do?
Assumes ?
how it changes parameters or heap memory
*/
void createDeckEGS(CARD *deck) {
  short i;

  //create each card in order
  for (i = 0; i < CARDS_IN_DECK; i++) {

    //create the face of the card (1-13)
    deck[i].cardFace = (i % CARDS_IN_SUIT) + 1;
    //create the suit of the card (0-3)
    deck[i].cardSuit = i / CARDS_IN_SUIT;
  }
}