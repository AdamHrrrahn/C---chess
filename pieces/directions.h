#ifndef DIRECTIONS_H
#define DIRECTIONS_H


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
        int directions[8];
        bool isNDone(){
            for(int i = 0; i < 8; i++){if(directions[i] > 0) return true;}
            return false;
        }
};
#endif