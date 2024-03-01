#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece
{
    private:
    public:
        Knight(char team, char number, Coords pos){
            name[0] = 'N';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
        }
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list, int turn, bool threatBoard[8][8]){
            bool checking = false;
            if (position.x > 1) {
                if (position.y < 7){
                    int x = position.x - 2;
                    int y = position.y + 1;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }                    
                }
                if (position.y > 0){
                    int x = position.x - 2;
                    int y = position.y - 1;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }     
                }
            }
            if (position.x < 6){
                if (position.y < 7){
                    int x = position.x + 2;
                    int y = position.y + 1;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }                    
                }
                if (position.y > 0){
                    int x = position.x + 2;
                    int y = position.y - 1;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }     
                }
            }
            if (position.y > 1) {
                if (position.x < 7){
                    int x = position.x + 1;
                    int y = position.y - 2;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }                    
                }
                if (position.x > 0){
                    int x = position.x - 1;
                    int y = position.y - 2;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }     
                }
            }
            if (position.y < 6){
                if (position.x < 7){
                    int x = position.x + 1;
                    int y = position.y + 2;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }                    
                }
                if (position.x > 0){
                    int x = position.x - 1;
                    int y = position.y + 2;
                    Coords target = Coords(x, y);
                    switch (turn){               
                        case 1:
                            p2list[0].cheackAndRemoveMove(target);
                            break;
                        case 2:
                            p1list[0].cheackAndRemoveMove(target);
                            break;
                    }
                    if (board.array[x][y].getName()[1] != name[1]){
                        possibleMoves.push_back(target);
                        if (board.array[x][y].getName()[0] == 'K'){
                            checking = true;
                        }
                    }     
                }
            }        
            if(checking){threatBoard[position.x][position.y] = true;}    
            return checking;
        }
};

#endif