#ifndef LINEARPIECE_H
#define LINEARPIECE_H

class LinearPiece : public Piece{
    public:
        virtual bool updateMoves(Board board, vector <shared_ptr <Piece>> p1list, vector <shared_ptr <Piece>> p2list, int turn, bool threatBoard[8][8]){
            bool checking = false;
            // int count = 0;
            // if(turn != player){
            //     count = 2;
            // } else {
            //     count = 1;
            // }
            Directions dir = Directions(moveStart, moveEnd);
            int distance = 0;
            while(dir.isNDone()){
                distance++;
                for(int i = moveStart; i < moveEnd; i++){
                    if(dir.directions[i] > 0){
                        int x = distance*dir.modifiers[i][0] + position.x;
                        int y = distance*dir.modifiers[i][1] + position.y;
                        if ((x < 0)||(y < 0)||(x >7)||(y > 7)){
                            dir.directions[i] = 0;
                            continue;
                        }   
                        Coords target = Coords(x,y);
                        if ((player != turn) && (dir.directions[i] == 2)){
                            switch (turn)
                            {               
                                case 1:
                                    p2list[0]->cheackAndRemoveMove(target);
                                    break;
                                case 2:
                                    p1list[0]->cheackAndRemoveMove(target);
                                    break;
                            }
                        }
                        char ally = name[1];
                        char enemy = ((player % 2) + 1) +'a'-1;
                        char targetTeam = board.array[x][y]->getName()[1];
                        if (targetTeam == 'n'){
                            possibleMoves.push_back(target);
                        } else if (targetTeam == ally) {
                            dir.directions[i] = 0;
                        } else if (targetTeam == enemy){
                            dir.directions[i] = 0;
                            possibleMoves.push_back(target);
                            if (player != turn){
                                if (board.array[x][y]->getName()[0] == 'K'){
                                    // if(dir.directions[i] == 1){
                                    checking = true;
                                    dir.directions[i] = 0;
                                    Coords Ntarget = Coords(dir.modifiers[i][0] + x, dir.modifiers[i][1] + y);
                                    switch (turn){               
                                        case 1:
                                            p2list[0]->cheackAndRemoveMove(Ntarget);
                                            break;
                                        case 2:
                                            p1list[0]->cheackAndRemoveMove(Ntarget);
                                            break;
                                    }                        
                                    for(int j = 0; j < distance; j++){
                                        threatBoard[j*dir.modifiers[i][0] + position.x][j*dir.modifiers[i][1] + position.y] = true;
                                    }
                                } else {
                                    int a = x;
                                    int b = y;
                                    bool end = false;
                                    while (!end){
                                        a += dir.modifiers[i][0];
                                        b += dir.modifiers[i][1];
                                        if ((a < 0)||(b < 0)||(a >7)||(b > 7)){
                                            end = true;
                                            break;
                                        }
                                        if (board.array[a][b]->getName()[0] != 'd'){
                                            end = true;
                                            if ((board.array[a][b]->getName()[0] == 'K') && (board.array[a][b]->getName()[1] != name[1])){
                                                bool proced = false;
                                                for(int j = 0; !proced; j++){
                                                    if (board.array[j*dir.modifiers[i][0] + position.x][j*dir.modifiers[i][1] + position.y]->getName()[1] != 'n'){
                                                        bool pareBoard[8][8];
                                                        for (int m = 0; m < 8; m++){
                                                            for (int n = 0; n < 8; n++){
                                                                pareBoard[m][n] = false;
                                                            }
                                                        } 
                                                        for (int m = 1; m < distance; m++){
                                                            pareBoard[m*dir.modifiers[i][0] + position.x][m*dir.modifiers[i][1] + position.y] = true;
                                                        }
                                                        board.array[j*dir.modifiers[i][0] + position.x][j*dir.modifiers[i][1] + position.y]->pareMoves(pareBoard);
                                                        proced = true;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                // }
                            }
                        }
                    }
                }
            }
            if(checking){threatBoard[position.x][position.y] = true;}    
            return checking;
        };
};

#endif