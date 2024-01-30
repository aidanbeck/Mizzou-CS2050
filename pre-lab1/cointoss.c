//COMPILE WITH: gcc cointoss.c -o cointoss.exe -Wall -Werror -Wpedantic
//RUN WITH: ./cointoss.exe

//Default Libraries
#include <stdio.h>
#include <time.h>

int main () {

  srand(time(NULL));

  char playerOneString[3] = "THT"; //each char is H or T
  char playerTwoString[3] = "HTH"; //each char is H or T

  int winner;
  int numTosses; 

  //printf("Game 1 Tosses: ");
  int testToss = coinTossGame(playerOneString, playerTwoString, &winner, &numTosses);

  
  printf("\nWinner: Player %d", winner);
  printf("\nNumber of Tosses: %d\n", numTosses);

  printf("\nPlay 100 games:\n");

  int p1wins = 0;
  int p2wins = 0;

  for (int i = 0; i < 100; i++) {
    coinTossGame(playerOneString, playerTwoString, &winner, &numTosses);
    if (winner == 1) {
      p1wins++;
    }
    else if (winner == 2) {
      p2wins++;
    }
  }

  printf("\nPlayer 1 wins: %d", p1wins);
  printf("\nPlayer 2 wins: %d", p2wins);

  printf("\n\nPress Anything + ENTER to Quit.\n");
  getchar(); //stops the program so I can read the output 

  return 0;
}



/* This function simulates the coin-toss game for two players.

X The first two arguments are character strings of length 3,
where each character is H or T.

X If one of the strings does not satisfy the requirements, the function returns a nonzero number
to signify an error, otherwise it returns 0 to signify there were no errors.

X A sequence of coin tosses is then simulated

X until the sequence of one of the players is encountered.

The number of the winning player will be stored at the
location specified by winner and the number of tosses
performed will be stored in numTosses. */

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses) {

  //verify input
  int oneIsVerified = verifyInput(player1);
  int twoIsVerified = verifyInput(player2);
  if (oneIsVerified == 1 || twoIsVerified == 1) {
    return 1;
  }

  //toss coins until the sequence of one of the players is encountered.
  int toss;
  char tossCharList[2] = "HT";
  char tossChar;
  int tosses = 0;
  char sequence[3] = "XXX";
  int gameWinner = 0;

  while(gameWinner == 0) {
    tosses++;
    toss = rand() % 2;
    tossChar = tossCharList[toss]; //H or T

    printf("%c", tossChar); //show tosses

    //get new sequence
    insertIntoSequence(tossChar, sequence);

    int p1wins = checkWinner(sequence, player1);
    int p2wins = checkWinner(sequence, player2);

    if (p1wins == 1) {
      gameWinner = 1;
    } else if (p2wins) {
      gameWinner = 2;
    } else {
      gameWinner = 0;
    }
  }


  *numTosses = tosses;
  *winner = gameWinner;

  return 0;
}

//if input consists of H's and T's, return 0.
//Anything else, and it returns 1.
int verifyInput(char string[3]) {

  int isVerified = 0;
  
  for (int i = 0; i < 3; i++) {
    if (string[i] != 'H' && string[i] != 'T') {
      isVerified = 1;
      break;
    }
  }

  return isVerified;

}

//input the current sequence and the 3 guesses. return 1 if they match, 0 if not
int checkWinner(char sequence[3], char guess[3]) {

  for (int i = 0; i < 3; i++) {
    if (sequence[i] != guess[i]) { //if they don't match
      return 0;
    }
  }

  return 1; //if all were right
}

//enter a new character into the end of a sequence
void insertIntoSequence(char newChar, char sequence[3]) {
  char newSequence[3] = {sequence[0], sequence[1], sequence[2]};

  //rotate sequence and enter new char
  newSequence[0] = newSequence[1];
  newSequence[1] = newSequence[2];
  newSequence[2] = newChar;

  sequence[0] = newSequence[0];
  sequence[1] = newSequence[1];
  sequence[2] = newSequence[2];
}