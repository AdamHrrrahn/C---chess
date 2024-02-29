class Rook : public Piece
{
    private:
    public:
        Rook(char team, char number, Coords pos){
            name[0] = 'R';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
        }
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list){};
};