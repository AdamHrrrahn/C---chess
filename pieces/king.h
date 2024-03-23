#ifndef KING_H
#define KING_H



class King : public Piece
{
    private:
    public:
        King(char team, char number, Coords pos){
            name[0] = 'K';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - 'a' + 1;
        }
        virtual bool updateMoves(Board board, vector <shared_ptr <Piece>> p1list, vector <shared_ptr <Piece>> p2list, int turn, bool threatBoard[8][8]){
            Directions dir = Directions(0, 8);
            for(int i = 0; i < 8; i++){
                int x = dir.modifiers[i][0] + position.x;
                int y = dir.modifiers[i][1] + position.y;
                if ((x < 0)||(y < 0)||(x >7)||(x > 7)){
                    break;
                }
                Coords target = Coords(x,y);
                if (board.array[target.x][target.y]->getName()[1] != name[1]){
                    possibleMoves.push_back(target);

                }
                if (player != turn){
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
            }
            return false;
        };
};
#endif