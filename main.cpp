#include "horses.h"


/* 
    main()

    Shows a 5x5 Knight hopping problem be solved
*/
int main() {
    // board setup
    std::vector<std::vector<int>> board  {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    /*
     = {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}};
    */

    //board[0][0] = ME;
    //printBoard(board);
    bool solved = false;
    solve(board, 0, 0, 0, 0, 0, solved);

    return 0;
}