#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
using namespace::std;

class Board
{
    public:
        Piece array[8][8];
        Board(){
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++){
                    array[i][j] = Piece();
                }
            }
        }
};
#endif