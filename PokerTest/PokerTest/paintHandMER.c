/*
paintHandMER.c
Takes in cards and paints them onto screen.

Author: Mallory Russell
History:
03 Mar 2016 - Initial design.
*/

#include "pokerHeader.h"
#include "wincurs.h"

void paintHandMER(CARD hand[])
{
  int i = 0; // Used to flip through cards in hand
  int x = 5; // Used for

  // Used to put value on card. Fix 10.
  char *faceVal[] =
  { "", "1", "2", "3", "4",
    "5", "6", "7", "8", "9",
    "10", "J", "Q", "K" };

  //used to clear lines from main, will need to remove after main cleaned up
  clr();
  
  //temporary scores chart
  xya(2, 35);
  printf("Royal Flush = 2000    *");
  printf(" Straight Flush = 1000");
  xya(3, 35);
  printf("Four of a Kind = 500  *");
  printf(" Full House = 400");
  xya(4, 35);
  printf("Flush = 250           *");
  printf(" Straight = 200");
  xya(5, 35);
  printf("Three of a Kind = 150 *");
  printf(" Two Pair = 100");
  xya(6, 35);
  printf("Jacks or Better = 50  *");
  printf(" Loser = -50");


  for (i = 0; i < 5; i++)
  {
    boxEX(10, x, 10, 10, FORE_WHITE); // Create the card
    if (hand[i].cardSuit == 0 || hand[i].cardSuit == 1) // Is it a red card?
    {
      msg(11, x + 1, faceVal[hand[i].cardFace], FORE_RED);
      msg(18, x + 8, faceVal[hand[i].cardFace], FORE_RED);
      
       //determines suit to display
       if (hand[i].cardSuit == 0)
       {
         msg(14, x +4, "\3", FORE_RED);
       }
       else
       {
         msg(14, x +4, "\4",FORE_RED);
       }
    }
    else // It's not red, it's a black card.
    {
      msg(11, x + 1, faceVal[hand[i].cardFace], BACK_WHITE);
      msg(18, x + 8, faceVal[hand[i].cardFace], BACK_WHITE);
      
      //determines suit to display
      if (hand[i].cardSuit == 2)
      {
        msg(14, x + 4, "\6", FORE_WHITE);
      }
      else
      {
        msg(14, x + 4, "\5", FORE_WHITE);
      }
    }
    x = x + 10; // We contine pushing the cards to the left
  }

  xya(20, 40);
  return;
}
