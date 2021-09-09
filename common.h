enum pawn_Color {Grey = 2, Black = 1, White = 0};
enum pawn_Status {Dead = 1, Alive = 0};
enum position_Status {Forbidden = 2, Occupied = 1, Unoccupied = 0};

#define Error 1
#define error -1
#define line_9 9
#define line_13 13
#define line_19 19


struct struc_Coordinates {
    unsigned x;
    unsigned y;
};

struct struc_Pawn {
    struc_Coordinates coord;
    pawn_Color colour;
    pawn_Status state;
};

struct struc_Position {
    unsigned blkRobbed;
    unsigned whtRobbed;
    char shape;
    struc_Coordinates coord;
    position_Status status;
    struc_Pawn *Zi;
};

struct struc_Step {
    struc_Coordinates coord;
    struc_Pawn* Zi;
    unsigned Move;
};

struct struc_Board {
    unsigned size;
    struc_Position board[line_19][line_19];
};

int funcSizeOfBoard(unsigned);
unsigned funcCharacterToX(char);
int funcPlayable(struc_Board *, unsigned);
int funcInitBoard(struc_Board *, unsigned);
struc_Step* funceInitSteps();
struc_Coordinates funcMove();
int funcPrintBoard(struc_Board *);