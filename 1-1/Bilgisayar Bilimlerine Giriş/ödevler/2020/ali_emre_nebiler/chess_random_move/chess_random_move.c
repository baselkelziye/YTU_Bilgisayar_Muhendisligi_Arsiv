#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Algorithm that moves the knight at position 0,0
randomly on the chessboard*/

void printTahta(int tahta[8][8]) {
  int i, j;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      printf("%2d ", tahta[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int tahta[8][8];
  int hareket[8][2] = // all possible knight moves
      {{+2, +1}, {+2, -1}, {-2, +1}, {-2, -1},
       {+1, +2}, {+1, -2}, {-1, +2}, {-1, -2}};
  int atX = 0, atY = 0;     // knight position
  int tempX = 0, tempY = 0; // stores the move temporarily
  int adim;                 // number of moves
  int i, j, rastgele;

  srand(time(NULL)); // seed random with time
  // reset the whole board
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      tahta[i][j] = 0;
    }
  }
  printf("KNIGHT ON THE CHESSBOARD");
  printf("\n\nNumber of Steps: ");
  scanf("%d", &adim);

  for (i = 1; i <= adim; i++) {

    rastgele = rand() % 7;
    tempX = tempX + hareket[rastgele][0];
    tempY = tempY + hareket[rastgele][1];
    // check whether the move stays inside the board
    while (tempX > 7 || tempX < 0 || tempY > 7 || tempY < 0) {
      tempX = atX;
      tempY = atY;
      rastgele = rand() % 7;
      tempX = tempX + hareket[rastgele][0];
      tempY = tempY + hareket[rastgele][1];
    }
    // assign the new position after validation
    atX = tempX;
    atY = tempY;

    tahta[atX][atY] = i; // mark the square after the move
    printf("\nStep %d", i);
    printf("\nRandom Number: %d\n", rastgele);
    printTahta(tahta); // print the board
  }
}
