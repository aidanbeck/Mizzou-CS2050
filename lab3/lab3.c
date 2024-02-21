#include "lab3.h"

/*
    Creates a new board.
    Malloc's enough memory for a float, two ints, and an int for every cell on the board.
    Assigns the first index as a 0.0 float, then converts to an int array and increments index origin by 3, hiding 3 values.
    This means [-3] is a float representing score. Also assigns [-2] to successfulHits and [-1] to shotsTaken.
    Assigns the remaining memory (the board) to 0, and returns the board.
*/
int * newBoard () {

    float *preboard = malloc( sizeof(float) + sizeof(int) + sizeof(int) + BOARD_SIZE*sizeof(int) );
    if (!preboard) { return NULL; }

    float score = 0.0; preboard[0] = score; //[-3] in the end

    int *board = (int *)(preboard + 3);
    
    int successfulHits = 0; board[-2] = successfulHits;
    int shotsTaken = 0;     board[-3] = shotsTaken;
    for (int i=0;i<BOARD_SIZE;i++) *(board+i) = 0;

    return board;
}

/*
    Increments [-1] (shotsTaken).
    If the targeted cell is 1 (a ship), increments [-2] (successfulShots) and runs updateScore(). returns 1 indicating hit.
    If not, it runs updateScore() and returns 0 indicating miss.
*/
int takeShot(int *board, int cell) {

    board[-1]++;

    if(board[cell] == 1) {
        board[-2]++;
        board[cell] = -1;
        updateScore(board);
        return 1;
    } else {
        updateScore(board);
        return 0;
    }
}

/*
    Loops through a board and returns the number of empty cells.
*/
int countFreeCells(int *board) {
    int count = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == 0) {
            count++;
        }
    }

    return count;
}

/*
    This function takes a board and retrieves the value at index -1, the hidden value for shots taken.
*/
int getShotsTaken(int *board) {
    return board[-1];
}

/*
    This function takes a board and retrieves the value at index -2, the hidden value for successful hits.
*/
int getHits(int *board) {
    return board[-2];
}

/*
    This function takes a board and retrieves the value at index -3, the hidden value for the player's score.
    It casts the board array into a float array: (float *)(board)
    And by putting that into parenthesis, it can access the value at [-3]
*/
float getScore(int *board) {
    return ((float *)(board))[-3];
}

/*
    This function calculates the score float from hits and shots, and sets the value at -3.
    In order to do this it casts the board to a float array.
*/
void updateScore(int *board) {
    float hits = board[-2];
    float shots = board[-1];

    float result = hits/shots;

    ((float *)(board))[-3] = result;
    
}

/*
    This function decrements the board pointer back to it's true origin, and frees the memory allocated to it.
*/
void endGame(int *board) {
    board -= 3; //do I need to do this?
    free(board);
}

/*
    Main function for testing/showcasing.
*/
// int main() {
//     int* board = newBoard();
//     board[6] = 1;
//     board[8] = 1;

//     takeShot(board, 6);
//     takeShot(board, 7);
//     takeShot(board, 8);

//     int shots = getShotsTaken(board);
//     printf("\nshots:%d\n", shots);

//     int hits = getHits(board);
//     printf("hits:%d\n", hits);

//     updateScore(board);
//     float score = getScore(board);
//     printf("score:%f\n", (float)score);

//     endGame(board);

//     return 0;
// }