/*
pokerHeader.h
Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wincurs.h"
//#include "unixcurs.h"

#ifdef _WIN32
#define PAUSE printf("\npress any key to continue..."); getchar()
#define FLUSH {int c; while (( c = getchar()) != '\n' && c != EOF);}
#define CLEAR system("cls")
#else
#define STR_IGNORECASE_CMP strcasecmp
#define PAUSE printf("\npress any key to continue..."); getchar()
#define FLUSH {int c; while (( c = getchar()) != '\n' && c != EOF);}
#define CLEAR printf("\033c")
#endif




#define CARDS_IN_DECK 52
#define CARDS_IN_SUIT 13
#define NAME 20
#define CARDS_IN_HAND 4

typedef struct card
{
	//Card struct
	unsigned int cardFace : 4; //face number 1-13 A-K
	unsigned int cardSuit : 2; //suit 0-3 Hearts Diamonds Spades Clubs
} CARD;

//cutting hand def. Use CARD variable[0-4] (an array of CARD stucts)

typedef struct player 
{
	//player struct
	char * playerName[NAME];
	//updated to use an array of CARDS I think I implemented this right
	CARD playerHand[CARDS_IN_HAND];
	int playerScore;
	short handsPlayed;
}PLAYER;

// faces on cards as constant array of strings
// put an empty string in position 0 so index 
// is the # on the card
const char *face[] =
{ "", "Ace", "Two", "Three", "Four",
"Five", "Six", "Seven", "Eight", "Nine",
"Ten", "Jack", "Queen", "King" };

// suit on cards, order is arbitrary
const char *suit[] =
{ "Hearts", "Diamonds", "Spades", "Clubs"};

//remove
void showDeck(CARD *);
void createDeckEGS(CARD *);
void shuffleDeckEGS(CARD *);
void dealCardsEGS(const CARD * const[]);
