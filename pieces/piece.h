#ifndef PIECE_H
#define PIECE_H

#include<vector>
// #include "board.h"
// #include "directions.h"
// #include "coords.h"
using namespace::std;

class Board;

class Piece
{
    protected:
        char name[4];
        int player;
        Coords position;
        vector <Coords> possibleMoves;
        // bool protecting = false;
        int moveStart;
        int moveEnd;
    public:
        char* getName(){return name;};
        Coords getCoords(){return position;};
        void setCoords(Coords pos){position=pos;};
        vector <Coords> getMoves(){return possibleMoves;};
        void clear(){
            possibleMoves.clear();
            // protecting = false;
        }
        Piece()
        {
            name[0] = 'd';
            name[1] = 'n';
            name[2] = 'n';
            name[3] = '\0';
            position.x = -1;
            position.y = -1;
        }
        void cheackAndRemoveMove(Coords target){
            for (int i = 0; i < possibleMoves.size(); i++){
                if ((target.x = possibleMoves[i].x)&&(target.y = possibleMoves[i].y)){
                    possibleMoves.erase(possibleMoves.begin()+i);
                }
            }
        }
        int pareMoves(bool threatBoard[8][8]){
            int index = 0;
            while (index < possibleMoves.size()){
                if(threatBoard[possibleMoves[index].x][possibleMoves[index].y]){
                    index++;
                } else{
                    possibleMoves.erase(possibleMoves.begin()+index);
                }
            }
            return possibleMoves.size();
        }
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list, int turn, bool threatBoard[8][8]){
            bool checking = false;
            int count = 0;
            if(turn == player){
                count = 2;
            } else {
                count = 1;
            }
            Directions dir = Directions(count, moveStart, moveEnd);
            int distance = 1;
            while(dir.isNDone()){
                for(int i = moveStart; i < moveEnd; i++){
                    int x = distance*dir.modifiers[i][0] + position.x;
                    int y = distance*dir.modifiers[i][1] + position.y;
                    if ((x < 0)||(y < 0)||(x >7)||(x > 7)){
                        dir.directions[i] = 0;
                        break;
                    }   
                    Coords target = Coords(x,y);
                    if ((player != turn) && (dir.directions[i] == 2)){
                        switch (turn)
                        {               
                            case 1:
                                p2list[0].cheackAndRemoveMove(target);
                                break;
                            case 2:
                                p1list[0].cheackAndRemoveMove(target);
                                break;
                        }
                    }
                    char ally = name[1];
                    char enemy = ((player % 2) + 1) +'0';
                    char targetTeam = board.array[x][y].getName()[1];
                    if (targetTeam == 'n'){
                        possibleMoves.push_back(target);
                    } else if (targetTeam == ally) {
                        dir.directions[i] = 0;
                    } else if (targetTeam == enemy){
                        dir.directions[i]--;
                        possibleMoves.push_back(target);
                        if (player != turn){
                            if (board.array[x][y].getName()[0] = 'K'){
                                if(dir.directions[i] == 1){
                                    checking = true;
                                    dir.directions[i] = 0;
                                    Coords Ntarget = Coords(dir.modifiers[i][0] + x, dir.modifiers[i][1] + y);
                                    switch (turn){               
                                        case 1:
                                            p2list[0].cheackAndRemoveMove(Ntarget);
                                            break;
                                        case 2:
                                            p1list[0].cheackAndRemoveMove(Ntarget);
                                            break;
                                    }                        
                                    for(int j = 1; j < distance; j++){
                                        threatBoard[j*dir.modifiers[i][0] + position.x][j*dir.modifiers[i][1] + position.y] = true;
                                    }
                                } else  {
                                    bool proced = false;
                                    for(int j = 1; !proced; j++){
                                        if (board.array[j*dir.modifiers[i][0] + position.x][j*dir.modifiers[i][1] + position.y].getName()[1] != 'n'){
                                            bool pareBoard[8][8];
                                            for (int m = 0; m < 8; m++){
                                                for (int n = 0; n < 8; n++){
                                                    pareBoard[m][n] = false;
                                                }
                                            } 
                                            for (int m = 1; m < distance; m++){
                                                pareBoard[m*dir.modifiers[i][0] + position.x][m*dir.modifiers[i][1] + position.y] = true;
                                            }
                                            board.array[j*dir.modifiers[i][0] + position.x][j*dir.modifiers[i][1] + position.y].pareMoves(pareBoard);
                                            proced = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(checking){threatBoard[position.x][position.y] = true;}    
            return checking;
        };
};

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