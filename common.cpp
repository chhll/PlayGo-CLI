#include <iostream>
#include <vector>
#include "common.h"

using namespace std;

const unsigned total_move = 400;
const string row_9 = "A   B   C   D   E   F   G   H   J";
const string col_9 = "|   |   |   |   |   |   |   |   |";
const string row_13 = "A   B   C   D   E   F   G   H   J   K   L   M   N";
const string col_13 = "|   |   |   |   |   |   |   |   |   |   |   |   |";
const string row_19 = "A   B   C   D   E   F   G   H   J   K   L   M   N   O   P   Q   R   S   T";
const string col_19 = "|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |";

// determine the board legit.
int funcSizeOfBoard (unsigned lines) {
    if (9 != lines && 13 != lines && 19 != lines) {
        cout << "funcSizeOfBoard: Board size error." << endl;
        return error;
    };

    return 0;
};

// determine whether the next move legit.
int funcMove(string m) {
    if (2 != m.length() && 3 != m.length()) {
        cout << "funcMove: Input length error." << endl;
        return error;
    };

    if (m[0]<'A' || m[0]>'J' || m[0]=='I') {
        cout << "funcMove: Input x coordinate error." << endl;
        return error;
    };
    
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
    int x, y; unsigned size;
    string *rowToPrint, row, col;

    if (NULL == b) {
        cout << "funcPrintBoard: Board array error." << endl;
        return error;
    };

    size = b->size;
    if (9!=size && 13!=size && 19!=size) {
        cout << "funcPrintBoard: Board size error." << endl;
        return error;
    };

    if (9 == size) {
        row = row_9;
        col = col_9;
    }

    else if (13 == size) {
        row = row_13;
        col = col_13;
    }

    else if (19 == size) {
        row = row_19;
        col = col_19;
    };

    rowToPrint = new string[size];
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            rowToPrint[y] += b->board[x][y].shape;
            x==size-1 ? rowToPrint[y]+="" : rowToPrint[y] += "---";
        };
    };

    cout << '\t' << '\t' << row << '\n';
    for (y = size; y > 0; y--) {
        cout << '\t' << y << '\t' << rowToPrint[y-1] << '\t' << y << '\n';
        y == 1 ? cout << "" : cout << '\t' << '\t' << col << '\n';
    };
    cout << '\t' << '\t' << row << '\n';

    delete []rowToPrint;
    return 0;
};