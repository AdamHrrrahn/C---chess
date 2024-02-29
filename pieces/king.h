class King : public Piece
{
    private:
        bool inCheck;
    public:
        King(char team, char number, Coords pos){
            inCheck = false;
            name[0] = 'K';
            name[1] = team;
            name[2] = number;
            name[3] = '\0';
            position = pos;
            player = team - '0';
        }
        void setCheck(){inCheck = true;};
        bool updateMoves(Board board, vector <Piece> p1list, vector <Piece> p2list){};

};