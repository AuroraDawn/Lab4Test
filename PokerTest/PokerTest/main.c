/*
Poker game
Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01

Notes:
evryones functions will end in thier initials Example:
getPokerHandJNH.c
*/

#include "pokerHeader.h"
#include "pokerInitializations.h"

int main(void) {
	short i;
	int score = 0;
	CARD deck[53];
	CARD hand[5];
  createDeckEGS(deck);
  
  //printDeck(deck);
 // for (short i = 0; i < 100; i++) {
  //  printf("\n\n\n%d", i);
    
    shuffleDeckEGS(deck);
    dealCardsEGS(deck, hand);
    
//  }
 


	/*for (i = 0; i <= CARDS_IN_HAND; i++) {
		hand[i] = deck[i];
	}
	printf("Current hand:");
	for (i = 0; i <= CARDS_IN_HAND; i++) {
		printf("\n%s %s", suit[hand[i].cardSuit], face[hand[i].cardFace]);
	}
  paintHandMER(hand);

	printf("\n\n===============\n\n");

	score = scoreHandJNH(hand);
	printf("%s!  %d", scoreStrings[score], scoreNums[score]);*/
	PAUSE;
}

void printDeck(CARD *deck) {
  short i;
  for (i = 0; i < CARDS_IN_DECK; i++) {
    printf("\n%s %s", suit[deck[i].cardSuit], face[deck[i].cardFace]);
  }
}