#ifndef PIECE_H
#define PIECE_H

#include<vector>
#include<memory>
using namespace::std;

class Piece;

class Board
{
    public:
        shared_ptr <Piece> array[8][8];
        Board(){

        }
};

class Piece
{
    protected:
        char name[4];
        int player;
        Coords position;
        vector <Coords> possibleMoves;
        int moveStart;
        int moveEnd;
    public:
        char* getName(){return name;};
        Coords getCoords(){return position;};
        void setCoords(Coords pos){position=pos;};
        vector <Coords> getMoves(){return possibleMoves;};
        void clear(){
            possibleMoves.clear();
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
        virtual bool updateMoves(Board board, vector <shared_ptr <Piece>> p1list, vector <shared_ptr <Piece>> p2list, int turn, bool threatBoard[8][8]){
            cout << "Error, base piece updateMoves()\n";
            return false;
        };
        // virtual bool updateMoves();
};
#endif