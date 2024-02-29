class Queen : public Piece
{
    private:
    public:
        Queen(char team, char number, Coords pos){
            name[0] = 'Q';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
        }
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list, int turn, bool threatBoard[8][8]){
            int count = 0;
            if(turn == player){
                count = 2;
            } else {
                count = 1;
            }
            Directions dir = Directions(count, 0, 8);
            int distance = 1;
            while(dir.isNDone()){
                for(int i = 0; i < 8; i++){
                    Coords target = Coords(distance*dir.modifiers[i][0],distance*dir.modifiers[i][1]);
                    if (turn == player){

                        // threatBoard
                    }
                }
            }
        };

};