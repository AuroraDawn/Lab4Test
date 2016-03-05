/*
pokerInitialization.h
Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01
only called in main.c
*/

//#include "wincurs.h"

// faces on cards as constant array of strings
// put an empty string in position 0 so index 
// is the # on the card
const char *face[] =
{ "", "Ace", "Two", "Three", "Four",
"Five", "Six", "Seven", "Eight", "Nine",
"Ten", "Jack", "Queen", "King" };

// suit on cards, order is arbitrary
const char *suit[] =
{ "Hearts", "Diamonds", "Spades", "Clubs" };

const char *scoreStrings[] =
{"You Lost", "Jacks", "Two Pair", "Three of a Kind", "Straight", "Flush", "Full House", "Four of a Kind", "Straight Flush", "Royal Flush"};

const short *scoreNums[] =
{ -50, 50, 100, 150, 200, 250, 400, 500, 1000, 2000 };
