/*
scoreHandJNH.c
Authors: Joseph helland, Mallory Russell, Emily Sandness, Tim Roller
Version .01

Notes:
evryones functions will end in thier initials Example:
getPokerHandJNH.c
*/

#include "pokerHeader.h"

int scoreHandJNH(CARD * myHand) {
	short i;
	int score = SCORE_LOSS;
	CARD temp[5];
	bool isScore = false;

	for (i = 0; i < 5; i++) {
		temp[i] = myHand[i];
	}
	sortHandJNH(temp);

	/*for (i = 0; i < 5; i++) {
	printf("%s %s\n", face[temp[i].cardFace], suit[temp[i].cardSuit]);
	}*/

	//Royal Flush
	if (isScore = scoreRoyalFlushJNH(temp)) {
		score = SCORE_ROYAL_FLUSH;
	}
	//Straigh Flush
	else if (isScore = scoreStraighFlushJNH(temp)) {
		score = SCORE_STRAIGHT_FLUSH;
	}
	//Four of a Kind
	else if (isScore = scoreFourOfAKindJNH(temp)) {
		score = SCORE_FOUR_OF_A_KIND;
	}
	//Full House
	else if (isScore = scoreFullHouseJNH(temp)) {
		score = SCORE_FULL_HOUSE;
	}
	//Flush
	else if (isScore = scoreFlushJNH(temp)) {
		score = SCORE_FLUSH;
	}
	//Straight
	else if (isScore = scoreStraightJNH(temp)) {
		score = SCORE_STRAIGHT;
	}
	//Three of a Kind
	else if (isScore = scoreThreeOfAKindJNH(temp)) {
		score = SCORE_THREE_OF_A_KIND;
	}
	//Two Pair
	else if (isScore = scoreTwoPairJNH(temp)) {
		score = SCORE_TWO_PAIR;
	}
	//pair of Jacks
	else if (isScore = scoreJacksJNH(temp)) {
		score = SCORE_JACKS;
	}
	return score;
}

void sortHandJNH(CARD* handSort) {
	short i;
	short ii;
	CARD temp;

	for (i = 0; i < 5; i++) {
		for (ii = i + 1; ii < 5; ii++) {
			if (handSort[i].cardFace > handSort[ii].cardFace) {
				temp = handSort[i];
				handSort[i] = handSort[ii];
				handSort[ii] = temp;
			}
		}
	}
	return;
}

bool scoreRoyalFlushJNH(CARD*hand) {
	bool thisScore = false;
	short i;
	short test = 0;
	CARD ace;
	//if first card is an ace and second card is a 10 put the ace high
	if (hand[0].cardFace == 1 && hand[1].cardFace == 10) {
		ace = hand[0];
		for (i = 0; i < 4; i++) {
			hand[i] = hand[i + 1];
		}
		hand[CARDS_IN_HAND] = ace;
	}
	else {
		//if first card is not an ace and second not a 10 the hand cannot be a royal flush
		return thisScore;
	}
	for (i = 0; i < 4; i++) {
		//test if all cards are same suit
		if ((test = compareCardsJNH(hand[i], hand[i + 1])) != -1) {
			sortHandJNH(hand);
			return thisScore;
		}
		//now test if they are sequential
		else if (hand[i].cardFace != hand[i + 1].cardFace - 1) {
			//k followed by A is not mathmatically sequential as A is 1 and k is 13
			//test for i == 3 and cardface == 13
			if (i == 3 && hand[i].cardFace == 13) {
				thisScore = true;
			}
			else {
				sortHandJNH(hand);
				return thisScore;
			}
		}
	}
	sortHandJNH(hand);
	return thisScore;
}

bool scoreStraighFlushJNH(CARD*hand) {
	bool thisScore = false;
	short i;
	short test = 0;

	for (i = 0; i < 4; i++) {
		//test if all cards are same suit
		if ((test = compareCardsJNH(hand[i], hand[i + 1])) != -1) {
			return thisScore;
		}
		//now test if they are sequential
		else if (hand[i].cardFace != hand[i + 1].cardFace - 1) {
			return thisScore;
		}
	}
	return thisScore = true;
}

bool scoreFourOfAKindJNH(CARD*hand) {
	bool thisScore = false;
	short i;
	short test = 0;
	short numSame = 0;
	if (test = compareCardsJNH(hand[0], hand[1]) == 1) {
		i = 0;
	}
	else {
		i = 1;
	}
	for (i; i < 4; i++) {
		//test if there are 4 of a kind.
		if (test = compareCardsJNH(hand[i], hand[i + 1]) != 1 && numSame != 3) {
			return thisScore;
		}
		else {
			numSame++;
		}
	}
	return thisScore = true;
}

bool scoreFullHouseJNH(CARD*hand) {
	bool thisScore = false;
	short test;

	if (test = compareCardsJNH(hand[0], hand[1]) != 1) return thisScore;

	if (test = compareCardsJNH(hand[1], hand[2]) == 1) {
		if (test = compareCardsJNH(hand[3], hand[4]) == 1) {
			thisScore = true;
		}
	}
	else if (test = compareCardsJNH(hand[2], hand[3]) == 1) {
		if (test = compareCardsJNH(hand[3], hand[4]) == 1) {
			thisScore = true;
		}
	}
	return thisScore;
}

bool scoreFlushJNH(CARD*hand) {
	bool thisScore = false;
	short i;
	short test;
	for (i = 0; i < 4; i++) {
		if (test = compareCardsJNH(hand[i], hand[i + 1]) != -1) {
			return thisScore;
		}
	}
	thisScore = true;
	return thisScore;
}

bool scoreStraightJNH(CARD*hand) {
	bool thisScore = false;
	short i;
	short test;
	CARD ace;
	if (hand[0].cardFace == 1 && hand[1].cardFace != 2) {
		ace = hand[0];
		for (i = 0; i < 4; i++) {
			hand[i] = hand[i + 1];
		}
		hand[CARDS_IN_HAND] = ace;
	}
	for (i = 0; i < 4; i++) {
		if (hand[i + 1].cardFace - 1 != hand[i].cardFace) {
			if (hand[i].cardFace - 12 != hand[i + 1].cardFace) {
				sortHandJNH(hand);
				return thisScore;
			}
		}
	}
	thisScore = true;
	return thisScore;
}

bool scoreThreeOfAKindJNH(CARD*hand) {
	bool thisScore = false;
	short test;
	short counter = 0;
	short i;
	for (i = 0; i < 4; i++) {
		if (test = compareCardsJNH(hand[i], hand[i + 1]) != 1 && counter < 2) {
			counter = 0;
		}
		else {
			counter++;
		}
	}
	if (counter >= 2) {
		thisScore = true;
	}
	return thisScore;
}

bool scoreTwoPairJNH(CARD*hand) {
	short pairOne = 0;
	short test;
	short i;
	bool thisScore = false;
	for (i = 0; i < 4; i++) {
		if (test = compareCardsJNH(hand[i], hand[i + 1]) == 1) {
			if (pairOne == 0) {
				pairOne = 1;
			}
			else {
				thisScore = true;
				return thisScore;
			}
		}
	}
	return thisScore;
}

bool scoreJacksJNH(CARD*hand) {
	short test;
	short i;
	bool thisScore = false;
	for (i = 0; i < 4; i++) {
		if (test = compareCardsJNH(hand[i], hand[i + 1]) == 1 && hand[i].cardFace == 11) {
			thisScore = true;
			return thisScore;
		}
	}
	return thisScore;
}


/*
result compareCardsJNH(cardOne, cardTwo)
Compares two cards and returns result as:
-1 cards are same suit
1 cards are same face
0 cards are not the same
*/
short compareCardsJNH(CARD cardOne, CARD cardTwo) {
	short result = 0;

	if (cardOne.cardFace == cardTwo.cardFace) {
		result = 1;
	}
	else if (cardOne.cardSuit == cardTwo.cardSuit) {
		result = -1;
	}
	return result;
}