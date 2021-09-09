#include <iostream>
#include <vector>
#include "common.h"

using namespace std;

const unsigned total_move = 400;
const char* row_9 = "\tA   B   C   D   E   F   G   H   J";
const char* col_9 = "\t|   |   |   |   |   |   |   |   |";
const char* row_13 = "\tA   B   C   D   E   F   G   H   J   K   L   M   N";
const char* col_13 = "\t|   |   |   |   |   |   |   |   |   |   |   |   |";
const char* row_19 = "\tA   B   C   D   E   F   G   H   J   K   L   M   N   O   P   Q   R   S   T";
const char* col_19 = "\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |";

// determine the board legit.
int funcSizeOfBoard (unsigned lines) {
    if (9 != lines && 13 != lines && 19 != lines) {
        cout << "funcSizeOfBoard: Board size error." << endl;
        return error;
    };

    return 0;
};

// determine whether the next move legit.
int funcMove(unsigned x, unsigned y) {
    return 0;
};

// verify the coordinates are valid.
unsigned funcCharacterToX (char x) {
    if (x=='i' || x<'a' || x>'t') {
        cout << x + " is not a valid x coordinate.\n";
        return 1;
    };

    if (x < 'i') return x - 'a' + 1;
    if (x > 'i') return x - 'a' + 2;

    return 1;
};

// determine the X, Y point is playable or not.
int funcPlayable (struc_Board *b, unsigned x, unsigned y) {
    if (NULL == b) {
        cout << "funcPlayable: Board is empty." << endl;
        return error;
    }

    if (x<1 || x>b->size) {
        cout << "funcPlayable: coordinate x invalid." << endl;
        return error;
    };

    if (y<1 || y>b->size) {
        cout << "funcPlayable: coordinate y invalid." << endl;
        return error;
    };

    if (NULL != b->board[x-1][y-1].Zi) {
        cout << "funcPlayable: coordinate been fallen." << endl;
        return error;
    };

    return 0;
};

// initialize the steps.
struc_Step *funceInitSteps () {
    unsigned z; struc_Step *s = NULL;

    s = new struc_Step[total_move];
    for (z=0; z<total_move; z++) {
        s[z].coord.x = 0;
        s[z].coord.y = 0;
        s[z].Move = z + 1;
        s[z].Zi = NULL;
    };

    return s;
};

// initialize the Go board.
int funcInitBoard (struc_Board *b, unsigned s) {
    unsigned x, y;

    if (NULL == b) {
        cout << "funcInitBoard: Board array error." << endl;
        return error;
    };

    if (9!=s && 13!=s && 19!=s) {
        cout << "funcInitBoard: Board size error." << endl;
        return error;
    };

    b->size = s;
    for (x=0; x<b->size; x++) {
        for (y=0; y<b->size; y++) {
            b->board[x][y].blkRobbed = 0;
            b->board[x][y].whtRobbed = 0;
            b->board[x][y].shape = '+';
            b->board[x][y].status = Unoccupied;
            b->board[x][y].Zi = NULL;
        };
    };

    return 0;
};

// print the Go board after every move.
int funcPrintBoard (struc_Board *b) {
    unsigned x, y;
    string row, rowToPrint;

    if (NULL == b) {
        cout << "funcPrintBoard: Board array error." << endl;
        return error;
    };

    if (9 != b->size && 13 != b->size && 19 != b->size) {
        cout << "funcPrintBoard: Board size error." << endl;
        return error;
    };

    for (y=b->size; y>0; y--) {
        row = ""; rowToPrint = "";
        for (x=1; x<b->size+1; x++) {
            row += b->board[x-1][y-1].shape;
            if (x == b->size) NULL==b->board[x-1][y-1].Zi ? row+=(b->board[x-1][y-1].shape) : row+=(b->board[x-1][y-1].Zi->colour);
            else {
                NULL == b->board[x-1][y-1].Zi ? 
                NULL == b->board[x][y-1].Zi ? row+=(b->board[x-1][y-1].shape+"---") : row+=(b->board[x-1][y-1].Zi->colour+"-- ")
                : NULL == b->board[x][y-1].Zi ? row+=(b->board[x-1][y-1].Zi->colour+" --") : row+=(b->board[x-1][y-1].Zi->colour+" - ");
            };
        };

        1 == y ? rowToPrint = "\t" + y + row + "\t" + "\n" 
        : rowToPrint = "\t" + y + row + "\t" + "\n" + col_19;
        // rowToPrint = "\t" + y + row + "\t" + "\n";
        cout << rowToPrint;
    };

    return 0;
};
