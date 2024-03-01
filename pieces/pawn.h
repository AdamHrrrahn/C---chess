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
            player = team - '0';
        }
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list, int turn, bool threatBoard[8][8]){
            // char oppose = ((player % 2) + 1) + '0';
            bool checking = false;
            if (player == 1)
            {
                if (position.y < 7)
                {
                    if (board.array[position.x][position.y+1].getName()[0] == 'd')
                    {
                        possibleMoves.push_back(Coords(position.x,position.y+1));
                        if (position.y < 6)
                        {   
                            if (board.array[position.x][position.y+2].getName()[0] == 'd')
                            {                
                                possibleMoves.push_back(Coords(position.x,position.y+2));
                            }
                        }
                    }
                    if (position.x > 0)
                    {
                        if (board.array[position.x-1][position.y+1].getName()[1] == '2')
                        {
                            possibleMoves.push_back(Coords(position.x-1,position.y+1));
                            if (board.array[position.x-1][position.y+1].getName()[0] == 'K')
                            {
                                checking = true;
                            }
                        }
                    }
                    if (position.x < 7)
                    {
                        if (board.array[position.x+1][position.y+1].getName()[1] == '2')
                        {
                            possibleMoves.push_back(Coords(position.x+1,position.y+1));
                            if (board.array[position.x+1][position.y+1].getName()[0] == 'K')
                            {
                                checking = true; 
                            }
                        }
                    }
                }
            }
            else
            {
                if (position.y > 0)
                {
                    if (board.array[position.x][position.y-1].getName()[0] == 'd')
                    {
                        possibleMoves.push_back(Coords(position.x,position.y-1));
                        if (position.y > 1)
                        {   
                            if (board.array[position.x][position.y-2].getName()[0] == 'd')
                            {                
                                possibleMoves.push_back(Coords(position.x,position.y-2));
                            }
                        }
                    }
                    if (position.x > 0)
                    {
                        if (board.array[position.x-1][position.y-1].getName()[1] == '1')
                        {
                            possibleMoves.push_back(Coords(position.x-1,position.y-1));
                            if (board.array[position.x-1][position.y-1].getName()[0] == 'K')
                            {
                                checking = true;
                            }
                        }

                    }
                    if (position.x < 7)
                    {
                        if (board.array[position.x+1][position.y-1].getName()[1] == '1')
                        {
                            possibleMoves.push_back(Coords(position.x+1,position.y-1));
                            if (board.array[position.x+1][position.y-1].getName()[0] == 'K')
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