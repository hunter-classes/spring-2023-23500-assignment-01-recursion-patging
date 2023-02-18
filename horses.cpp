#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

int EMPTY = 0;
int ME = -1;
bool solved = false;

/*
    isSolved

    determines whether or not the board is solved
*/
bool isSolved(int b[5][5]) {

    std::vector<int> v;

    for (int i = 1; i < 26; i++ ) 
        v.push_back(i);

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if( std::find(v.begin(), v.end(), b[i][j]) == v.end()) {
                return false;
            }
        }
    }

    return true;
}

/* 
    printBoard

    prints board
*/
void printBoard(int (b)[5][5]) {
   //std::cout << "[0;0H\n";
    usleep(0);
    for(int i = 0; i<5;i++) {
        std::cout << std::endl;
        for (int j = 0; j<5; j++) {
            printf( "%3d :", b[i][j]);
        }
    }  
}

/* 
    solves

    solves a 5x5 knight hopping problem

    args:

    board : the board we're moving on
    hX : where the horse is rn
    hY : where the horse Y is
    row : the row we're planning on moving the horse to (state is not updated on board)
    col : the col we're planning on moving the horse to (state is not updated on board)
    moveNum : the move this next move we're about to make is
    solved : reference to whether or not the move is solved

*/
void solve(int board[5][5], int hX, int hY ,int row, int col, int moveNum,bool& solved) {

    int newBoard[5][5];
    memcpy(newBoard, board, 25 * sizeof(int));

    // terminating process if it's solved
    if(solved) { 
        return;
    }

    // making move or throwing it out b/c invalid move
    if (row < 0 || row > 4 || col < 0|| col > 4) {
        // the move itself is out of bounds
        return;
    }

    if (newBoard[row][col] == EMPTY ) {
        // it' free slot

        // swapping
        newBoard[hX][hY] = moveNum;

        // analyzing the move
        if(isSolved(newBoard)) {
            printBoard(newBoard);
            solved = true;
            return;
        } else {
            newBoard[row][col] = ME;

            //print board animation
            printBoard(newBoard);
            std::cout << row << col << moveNum << std::endl;
            std::cout << &newBoard;

            // recursive calls
            solve(newBoard, row, col ,row + 2, col + 1, moveNum + 1, solved);
            solve(newBoard, row, col ,row + 2, col - 1, moveNum + 1, solved);
            solve(newBoard, row, col ,row - 2, col - 1, moveNum + 1, solved);
            solve(newBoard, row, col ,row - 2, col + 1, moveNum + 1, solved);
            solve(newBoard, row, col ,row + 1, col + 2, moveNum + 1, solved);
            solve(newBoard, row, col ,row + 1, col - 2, moveNum + 1, solved);
            solve(newBoard, row, col ,row - 1, col + 2, moveNum + 1, solved);
            solve(newBoard, row, col ,row - 1, col - 2, moveNum + 1, solved);
        }
    } else {
        // the move in question is invalid because it'd be stepping on an already stepped tile
        return;
    }
}

/* 
    main()

    Shows a 5x5 Knight hopping problem be solved
*/
int main() {
    // board setup
    int board[5][5]; 
    /* = {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}};
    */
    for(int i = 0;i<5;i++) { 
        for(int j=0; j<5;j++) {
            board[i][j] = EMPTY;
        }
    } 

    //board[0][0] = ME;
    //printBoard(board);

    solve(board, 0, 0, 0, 0, 0, solved);

    return 0;
}