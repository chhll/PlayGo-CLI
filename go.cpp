#include <iostream>
#include "common.h"

using namespace std;
// const unsigned Error = 1; const int error = -1;

int main () {
    unsigned sizeOfBoard = 0;
    unsigned endOfGame = 0;
    string nextMove;
    struc_Step *allSteps = NULL;
    struc_Board *b = new struc_Board;

    cout << "Please input the board size (9, 13, 19): ";
    cin >> sizeOfBoard;

    if (error == funcSizeOfBoard(sizeOfBoard)) return error;
    if (error == funcInitBoard(b, sizeOfBoard)) return error;
    if (error == funcPrintBoard(b)) return error;

    while (!endOfGame) {
        cout << "Please input the next move (like c10): ";
        cin >> nextMove;
        if (error == funcMove(nextMove)) cout << "The move is invalid." << endl;
    };
    

    delete b;
    return 0;
}
