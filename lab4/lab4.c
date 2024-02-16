#include "lab4.h"

/*
    Allocates memory for an instance of the GameBoard struct,
    and initializes all of it's values to 0.
    It then returns the pointer to the board.
*/
GameBoard *newBoard() {

    GameBoard *board =  malloc(sizeof(GameBoard));
    if (!board) return NULL;

    board->shots = 0;
    board->hits = 0;
    board->score = 0;
    for (int i=0;i<BOARD_SIZE;i++) board->arena[i] = 0;

    return board;
}

/*
    Helper for takeShot().
    It sets the board's score to hits/shots.
*/
void updateScore(GameBoard *board) {
    float hits = board->hits;
    float shots = board->shots;
    float score = hits / shots;
    
    board->score = score;
}

/*
    Increments the GameBoard's "shots".
    If the targeted cell matches a 1,
        it sets the cell to -1,
        increments "hits" and updates "score",
        and returns 1.
    If it doesn't, it just updates score & returns 0.

*/
int takeShot(GameBoard *board, int cell) {

    board->shots++;

    if (board->arena[cell] == 1) {
        board->arena[cell] = -1;
        board->hits++;
        updateScore(board);
        return 1;
    }

    updateScore(board);
    return 0;
}

/*
    Loops through the arena array inside of a GameBoard,
    and returns the number of 0's counted inside.
*/
int countFreeCells(GameBoard *board) {

    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->arena[i] == 0) {
            count++;
        }
    }

    return count;
}

/*
    Returns the "shots" value on a GameBoard.
*/
int getShotsTaken(GameBoard *board) {
    return board->shots;
}

/*
    Returns the "hits" value on a GameBoard.
*/
int getHits(GameBoard *board) {
    return board->hits;
}

/*
    Returns the "score" value on a GameBoard.
*/
float getScore(GameBoard *board) {
    return board->score;
}

/*
    Sets the cell to 1 if it is not 1 or -1 already.
    Returns 1 on success, 0 on failure.
*/
int placeShip(GameBoard *board, int cell) {

    if (board->arena[cell] == 0) {
        board->arena[cell] = 1;
        return 1;
    }

    return 0;
}

/*
    Frees the memory allocated to a gameboard.
*/
void endGame(GameBoard *board) {
    free(board);
}