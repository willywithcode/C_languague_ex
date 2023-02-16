#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 4
#define CARDS_PER_PLAYER NUM_CARDS / NUM_PLAYERS
void PRINT_CARD(int card) {
  if (card/NUM_PLAYERS == 0) printf("(ACE ");
  else if (card/NUM_PLAYERS == 10) printf("(JACK ");
  else if (card/NUM_PLAYERS == 11) printf("(QUEEN ");
  else if (card/NUM_PLAYERS == 12) printf("(KING ");
  else printf("(%d ",card/NUM_PLAYERS + 1);
  if(card%NUM_PLAYERS == 0) printf("Spade) ");
  else if(card%NUM_PLAYERS == 1) printf("Club) ");
  else if(card%NUM_PLAYERS == 2) printf("Diamond) ");
  else  printf("Heart) ");
}
int main() {
  bool c[CARDS_PER_PLAYER][NUM_PLAYERS];
  int d[CARDS_PER_PLAYER][NUM_PLAYERS];
  int i, j, card;

  srand(time(NULL));
  for (i = 0; i < CARDS_PER_PLAYER; i++) {
    for (j = 0; j < NUM_PLAYERS; j++) {
      c[i][j] = false;
      d[i][j] = -1;
    }
  }
  for (i = 0; i < NUM_CARDS; i++) {
    card = rand() % NUM_CARDS;

    while (c[card / NUM_PLAYERS][card % NUM_PLAYERS] == true) {
      card = (card + 1) % NUM_CARDS;
    }

    c[card / NUM_PLAYERS][card % NUM_PLAYERS] = true;
    d[card / NUM_PLAYERS][card % NUM_PLAYERS] = i %4;
  }

  
  for (int i =0; i <NUM_PLAYERS ; i ++) {
    printf("Player %d: ", i+1);
    for (int j = 0; j < NUM_CARDS; j ++) {
      if (d[j / NUM_PLAYERS][j % NUM_PLAYERS] == i) {
        PRINT_CARD(j);
      }
    }
    printf("\n");
  }
  for (int i = 0; i < CARDS_PER_PLAYER; i ++) {
    if (d[i][0] == d[i][1] && d[i][1] == d[i][2] && d[i][2] == d[i][3]) {
      printf("Player %d co tu quy ",d[i][0] +1);
      if (i == 0) printf("ACE\n");
      else if (i == 10) printf("JACK\n");
      else if (i == 11) printf("QUEEN\n");
      else if (i == 12) printf("KING\n");
      else printf("%d\n",i+1);
    }
  }

  return 0;
}
