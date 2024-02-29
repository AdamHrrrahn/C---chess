class Pawn : public Piece
{
    private:
        int dir;
    public:
        Pawn(char team, char number, Coords pos){
            name[0] = 'p';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
        }
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list, int turn)
        {
            char oppose = player + '0';
            bool checking = false;
            possibleMoves.clear();
            if (dir == 1)
            {
                if (position.y < 7)
                {
                    if (board.array[position.x][position.y+1].getName()[0] != 'd')
                    {
                        possibleMoves.push_back(Coords(position.x,position.y+1));
                        if (position.y < 6)
                        {   
                            if (board.array[position.x][position.y+2].getName()[0] != 'd')
                            {                
                                possibleMoves.push_back(Coords(position.x,position.y+2));
                            }
                        }
                    }
                    if (position.x > 0)
                    {
                        if (board.array[position.x-1][position.y+1].getName()[1] == oppose)
                        {
                            possibleMoves.push_back(Coords(position.x-1,position.y+1));
                            if (board.array[position.x-1][position.y+1].getName()[0] == 'K')
                            {
                                checking = true;
                                // board.array[position.x-1][position.y+1].setCheck();
                            }
                        }
                    }
                    if (position.x < 7)
                    {
                        if (board.array[position.x+1][position.y+1].getName()[1] == oppose)
                        {
                            possibleMoves.push_back(Coords(position.x+1,position.y+1));
                            if (board.array[position.x+1][position.y+1].getName()[0] == 'K')
                            {
                                checking = true; 
                                // board.array[position.x+1][position.y+1].setCheck();                           
                            }
                        }
                    }
                }
            }
            else
            {
                if (position.y > 0)
                {
                    if (board.array[position.x][position.y-1].getName()[0] != 'd')
                    {
                        possibleMoves.push_back(Coords(position.x,position.y-1));
                        if (position.y > 1)
                        {   
                            if (board.array[position.x][position.y-2].getName()[0] != 'd')
                            {                
                                possibleMoves.push_back(Coords(position.x,position.y-2));
                            }
                        }
                    }
                    if (position.x > 0)
                    {
                        if (board.array[position.x-1][position.y-1].getName()[1] == oppose)
                        {
                            possibleMoves.push_back(Coords(position.x-1,position.y-1));
                            if (board.array[position.x-1][position.y-1].getName()[0] == 'K')
                            {
                                checking = true;
                                // board.array[position.x-1][position.y-1].setCheck();
                            }
                        }

                    }
                    if (position.x < 7)
                    {
                        if (board.array[position.x+1][position.y-1].getName()[1] == oppose)
                        {
                            possibleMoves.push_back(Coords(position.x+1,position.y-1));
                            if (board.array[position.x+1][position.y-1].getName()[0] == 'K')
                            {
                                checking = true;
                                // board.array[position.x+1][position.y-1].setCheck();
                            }
                        }
                    }
                }
            }
            return checking;
        }
};