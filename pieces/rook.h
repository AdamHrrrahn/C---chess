#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece
{
    private:
    public:
        Rook(char team, char number, Coords pos){
            name[0] = 'R';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
            moveStart = 0;
            moveEnd = 4;
        }
};
#endif