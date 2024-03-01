#ifndef QUEEN_H
#define QUEEN_H

class Queen : public Piece
{
    private:
    public:
        Queen(char team, char number, Coords pos){
            name[0] = 'Q';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
            moveStart = 0;
            moveEnd = 8;
        }
};
#endif