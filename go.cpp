#include <iostream>
#include "common.h"

using namespace std;
const char white = 'O';
const char black = 'X';

int main () {
    unsigned sizeOfBoard = 0, endOfGame = 0;
    int x = 0, y = 0; char shape = '+'; 
    unsigned step = 0; struc_Pawn *p = NULL;
    string nextMove;
    struc_Step *allSteps = NULL;
    struc_Board *b = new struc_Board;

    cout << "Please input the board size (9, 13, 19): ";
    cin >> sizeOfBoard;

    if (error == funcSizeOfBoard(sizeOfBoard)) return error;
    if (error == funcInitBoard(b, sizeOfBoard)) return error;
    if (error == funcPrintBoard(b)) return error;

    while (!endOfGame) {
        cout << "Please enter the next move (like D4): ";
        cin >> nextMove;
        
        if (error == funcMoveX(b, nextMove)) {
            cout << "X move invalid. ";
            continue;
        };

        if (error == funcMoveY(b, nextMove)) {
            cout << "Y move invalid. ";
            continue;
        };

        x = funcMoveX(b, nextMove);
        y = funcMoveY(b, nextMove);
        step % 2 == 0 ? shape = black : shape = white;
        p = funcFall(b, shape, x, y);

        if (NULL == p) {
            cout << "Position invalid. ";
            continue;
        }

        else b->board[x][y].Zi = p;

        if (error == funcPrintBoard(b)) return error;
        step++;
    };

    delete b;
    return 0;
}