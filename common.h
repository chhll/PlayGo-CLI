#include <string>

using namespace std;

enum pawn_Color {Grey = 2, Black = 1, White = 0};
enum pawn_Status {Dead = 1, Alive = 0};
enum position_Status {Forbidden = 2, Occupied = 1, Unoccupied = 0};

#define Error 1
#define error -1
#define line_9 9
#define line_13 13
#define line_19 19

class struc_Coordinates {
public:
    unsigned x;
    unsigned y;
};

class struc_Pawn {
public:
    struc_Coordinates coord;
    pawn_Color colour;
    pawn_Status status;
};

class struc_Position {
public:
    unsigned blkRobbed;
    unsigned whtRobbed;
    char shape;
    struc_Coordinates coord;
    position_Status status;
    struc_Pawn *Zi;
};

class struc_Step {
public:
    struc_Coordinates coord;
    struc_Pawn* Zi;
    unsigned Move;
};

class struc_Board {
public:
    unsigned size;
    struc_Position board[line_19][line_19];
};

int funcSizeOfBoard(unsigned);
unsigned funcCharacterToX(char);
int funcPlayable(struc_Board *, unsigned, unsigned);
int funcInitBoard(struc_Board *, unsigned);
struc_Step* funceInitSteps();
int funcMove(string);
int funcPrintBoard(struc_Board *);