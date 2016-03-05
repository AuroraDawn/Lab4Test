/*
pokerHeader.h
Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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
#define CARDS_IN_HAND 5

enum SCORE
{
	SCORE_LOSS = 0,
	SCORE_JACKS = 1,
	SCORE_TWO_PAIR = 2,
	SCORE_THREE_OF_A_KIND = 3,
	SCORE_STRAIGHT = 4,
	SCORE_FLUSH = 5,
	SCORE_FULL_HOUSE = 6,
	SCORE_FOUR_OF_A_KIND = 7,
	SCORE_STRAIGHT_FLUSH = 8,
	SCORE_ROYAL_FLUSH = 9
};

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

int scoreHandJNH(CARD*);
void sortHandJNH(CARD*);
bool scoreJacksJNH(CARD*);
bool scoreTwoPairJNH(CARD*);
bool scoreThreeOfAKindJNH(CARD*);
bool scoreStraightJNH(CARD*);
bool scoreFlushJNH(CARD*);
bool scoreFullHouseJNH(CARD*);
bool scoreFourOfAKindJNH(CARD*);
bool scoreStraighFlushJNH(CARD*);
bool scoreRoyalFlushJNH(CARD*);
short compareCardsJNH(CARD, CARD);

void createDeckEGS(CARD *);
void shuffleDeckEGS(CARD *);
void dealCardsEGS(CARD *, CARD *);
void printDeck(CARD *);

void paintHandMER(CARD []);