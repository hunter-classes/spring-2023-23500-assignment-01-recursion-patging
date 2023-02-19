#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

int EMPTY = 0;
int ME = -1;
int row = 0;
int col = 0;
bool solved = false;

/*
    isSolved

    determines whether or not the board is solved
*/
bool isSolved(std::vector<std::vector<int>> b) {

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
void printBoard(std::vector<std::vector<int>> b) {
   std::cout << "[0;0H\n";
    usleep(800000);
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
void solve(std::vector<std::vector<int>> board, int hX, int hY ,int row, int col, int moveNum,bool& solved) {

    // terminating process if it's solved
    if(solved) { 
        return;
    }

    // making move or throwing it out b/c invalid move

    if (row < 0 || row > 4 || col < 0|| col > 4) {
        // the move itself is out of bounds
        return;
    }

    if (board[row][col] != EMPTY ) {
        // it's an occupied slot
        return;
    }

    // swapping

    if (moveNum == 25) { 
        board[hX][hY] = moveNum;
    } else { 
        board[hX][hY] = moveNum;
        board[row][col] = ME;
    }

    //print board animation
    printBoard(board);

    // analyzing the move
    if(isSolved(board)) {
        solved = true;
        printBoard(board);
        return;
    }

    // recursive moves

    if (!solved) {
        solve(board, row, col ,row + 2, col - 1, moveNum + 1, solved);
        solve(board, row, col ,row + 2, col + 1, moveNum + 1, solved);
        solve(board, row, col ,row - 2, col - 1, moveNum + 1, solved);
        solve(board, row, col ,row - 2, col + 1, moveNum + 1, solved);
        solve(board, row, col ,row + 1, col + 2, moveNum + 1, solved);
        solve(board, row, col ,row + 1, col - 2, moveNum + 1, solved);
        solve(board, row, col ,row - 1, col + 2, moveNum + 1, solved);
        solve(board, row, col ,row - 1, col - 2, moveNum + 1, solved);

    }
}

/* 
    main()

    Shows a 5x5 Knight hopping problem be solved
*/
int main() {
    // board setup
    std::vector<std::vector<int>> board;

    //= {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
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