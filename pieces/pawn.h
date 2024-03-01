#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece
{
    public:
        Pawn(char team, char number, Coords pos){
            name[0] = 'P';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - 'a' + 1;
        }
        virtual bool updateMoves(Board board, vector <shared_ptr <Piece>> p1list, vector <shared_ptr <Piece>> p2list, int turn, bool threatBoard[8][8]){
            bool checking = false;
            if (player == 1)
            {
                if (position.x < 7)
                {
                    if (board.array[position.x+1][position.y]->getName()[0] == 'd')
                    {
                        possibleMoves.push_back(Coords(position.x+1,position.y));
                        if (position.x == 1)
                        {   
                            if (board.array[position.x+2][position.y]->getName()[0] == 'd')
                            {                
                                possibleMoves.push_back(Coords(position.x+2,position.y));
                            }
                        }
                    }
                    if (position.y > 0)
                    {
                        if (board.array[position.x+1][position.y-1]->getName()[1] == 'b')
                        {
                            possibleMoves.push_back(Coords(position.x+1,position.y-1));
                            if (board.array[position.x+1][position.y-1]->getName()[0] == 'K')
                            {
                                checking = true;
                            }
                        }
                    }
                    if (position.y < 7)
                    {
                        if (board.array[position.x+1][position.y+1]->getName()[1] == 'b')
                        {
                            possibleMoves.push_back(Coords(position.x+1,position.y+1));
                            if (board.array[position.x+1][position.y+1]->getName()[0] == 'K')
                            {
                                checking = true; 
                            }
                        }
                    }
                }
            }
            else
            {
                if (position.x > 0)
                {
                    if (board.array[position.x-1][position.y]->getName()[0] == 'd')
                    {
                        possibleMoves.push_back(Coords(position.x-1,position.y));
                        if (position.x == 6)
                        {   
                            if (board.array[position.x-2][position.y]->getName()[0] == 'd')
                            {                
                                possibleMoves.push_back(Coords(position.x-2,position.y));
                            }
                        }
                    }
                    if (position.y > 0)
                    {
                        if (board.array[position.x-1][position.y-1]->getName()[1] == 'a')
                        {
                            possibleMoves.push_back(Coords(position.x-1,position.y-1));
                            if (board.array[position.x-1][position.y-1]->getName()[0] == 'K')
                            {
                                checking = true;
                            }
                        }

                    }
                    if (position.y < 7)
                    {
                        if (board.array[position.x-1][position.y+1]->getName()[1] == 'a')
                        {
                            possibleMoves.push_back(Coords(position.x-1,position.y+1));
                            if (board.array[position.x-1][position.y+1]->getName()[0] == 'K')
                            {
                                checking = true;
                            }
                        }
                    }
                }
            }
            if(checking){threatBoard[position.x][position.y] = true;}    
            return checking;
        }
};
#endif