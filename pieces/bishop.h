#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece
{
    private:
    public:
        Bishop(char team, char number, Coords pos){
            name[0] = 'B';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
            moveStart = 4;
            moveEnd = 8;
        }
};
#endif