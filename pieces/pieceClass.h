// #include "coords.h"
#include<vector>
using namespace std;
class Coords
{
    public:
        Coords(){x = -1; y = -1;};
        Coords(int a, int b){x = a; y = b;};
        int x;
        int y;
};

class Directions
{
    public:
        Directions(int count, int start, int stop){
            for(int i = 0; i < 8; i++){directions[i] = 0;};
            for(int i = start; i < stop; i++){directions[i] = count;};
            modifiers[0][0] = 1;
            modifiers[0][1] = 0;
            modifiers[1][0] = -1;
            modifiers[1][1] = 0;
            modifiers[2][0] = 0;
            modifiers[2][1] = 1;
            modifiers[3][0] = 0;
            modifiers[3][1] = -1;
            modifiers[4][0] = 1;
            modifiers[4][1] = 1;
            modifiers[5][0] = -1;
            modifiers[5][1] = 1;
            modifiers[6][0] = -1;
            modifiers[6][1] = 1;
            modifiers[7][0] = -1;
            modifiers[7][1] = -1;
        }
        int modifiers[8][2];
        bool directions[4];
        bool isNDone(){
            for(int i = 0; i < 8; i++){if(directions[i]) return true;}
            return false;
        }
};

class Piece
{
    protected:
        char name[4];
        int player;
        Coords position;
        vector <Coords> possibleMoves;
        bool protecting;
    public:
        char* getName(){return name;};
        Coords getCoords(){return position;};
        void setCoords(Coords pos){position=pos;};
        void updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list, int turn){return;};
        void checkProtecting(){if (protecting)possibleMoves.clear();}
        Piece()
        {
            name[0] = 'd';
            name[1] = 'n';
            name[2] = 'n';
            name[3] = '\0';
            position.x = -1;
            position.y = -1;
        }
        // void set_pos(self, int a,int b){self.position[0] = a; self.position[1] = b};
};
