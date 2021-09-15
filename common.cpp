#include <iostream>
#include <vector>
#include <cctype>
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

// determine the next X move.
int funcMoveX(struc_Board *b, string m) {
    int x; string x_coord; int size;
    
    if (NULL == b) {
        cout << "funcMoveX: Board does not exist." << endl;
        return error;
    };
    
    if (2 != m.length() && 3 != m.length()) {
        cout << "funcMoveX: Length error." << endl;
        return error;
    };

    size = b->size;
    if (isupper(m[0])) {
        if (m[0]<'A' || m[0]-'A'>size || 'I'==m[0]) {
            cout << "funcMoveX: X coordinate error." << endl;
            return error;
        };

        m[0] < 'I' ? x = m[0] - 'A' : x = m[0] - 'A' + 1;
    }

    else {
        if (m[0]<'a' || m[0]-'a'>size || 'i'==m[0]) {
            cout << "funcMoveX: x coordinate error." << endl;
            return error;
        };

        m[0] < 'i' ? x = m[0] - 'a' : x = m[0] - 'a' + 1;
    };
    
    return x;
};

// determine the next Y move.
int funcMoveY(struc_Board* b, string m) {
    int y = 0; string y_coord; int size;

    if (NULL == b) {
        cout << "funcMoveY: Board does not exist." << endl;
        return error;
    };

    if (2 != m.length() && 3 != m.length()) {
        cout << "funcMoveY: Length error." << endl;
        return error;
    };

    y_coord = m.substr(1);
    y = stoi(y_coord);
    size = b->size;
    if (y<1 || y>size) {
        cout << "funcMoveY: Y coordinate error." << endl;
        return error;
    };

    return y - 1;
};

// fall the pawn on the board.
struc_Pawn *funcFall(struc_Board *b, char shape, int x, int y) {
    struc_Pawn* pawn = NULL;

    if (NULL == b) {
        cout << "funcFall: Board does not exist." << endl;
        return NULL;
    };

    if (error == funcPlayable(b, x, y)) {
        cout << "funcFall: coordinate error." << endl;
        return NULL;
    };

    pawn = new struc_Pawn;
    pawn->shape = shape;
    pawn->coord.x = x;
    pawn->coord.y = y;
    pawn->status = Alive;
    return pawn;
};

// determine the X, Y point is playable or not.
int funcPlayable (struc_Board *b, int x, int y) {
    if (NULL == b) {
        cout << "funcPlayable: Board does not exist." << endl;
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
        cout << "funcPlayable: position been fallen." << endl;
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
        cout << "funcInitBoard: Board does not exist." << endl;
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
    int x, y, size;
    string *rowToPrint, row, col;

    if (NULL == b) {
        cout << "funcPrintBoard: Board does not exist." << endl;
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
            if (NULL == b->board[x][y].Zi) rowToPrint[y] += b->board[x][y].shape;
            else rowToPrint[y] += b->board[x][y].Zi->shape;
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