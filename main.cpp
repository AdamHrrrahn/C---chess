#include<iostream>
#include<cassert>
#include<fstream>
#include<vector>
#include <memory>

#include "pieces/coords.h"
#include "pieces/directions.h"
#include "pieces/piece.h"
#include "pieces/linearPiece.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
using namespace std;

struct loadResults{
    int turn;
    Board loadBoard;
};

Board board = Board();
shared_ptr <Piece> emptyPiece(new Piece());
vector <shared_ptr <Piece>> p1list;
vector <shared_ptr <Piece>> p2list;
int p1pieceCount[4];
int p2pieceCount[4];

int intro()
{
    int input = 0;
    bool finished = false;
    while (! finished)
    {
        cout << "Select command:\n\t1) Start New Game\n\t2) Load Saved Game\n\t3) Quit\n";
        cin >> input;
        if ((input > 0) && (input < 4)){
            finished = true;
        }
          else
        {
            cout << "invalid selection, please select a numeric option";
        }
    }
    return input;
}

Board newBoard()
{
    Board newBoard = Board();
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            newBoard.array[i][j] = emptyPiece;
        }
    }
    shared_ptr <Piece> Ka1(new King('a', '1', Coords(0, 3)));
    newBoard.array[0][3] = Ka1;
    p1list.push_back(Ka1);
    shared_ptr <Piece> Ra1(new Rook('a', '1', Coords(0, 0)));
    newBoard.array[0][0] = Ra1;
    p1list.push_back(Ra1);
    shared_ptr <Piece> Na1(new Knight('a', '1', Coords(0, 1)));
    newBoard.array[0][1] = Na1;
    p1list.push_back(Na1);
    shared_ptr <Piece> Ba1(new Bishop('a', '1', Coords(0, 2)));
    newBoard.array[0][2] = Ba1;
    p1list.push_back(Ba1);
    shared_ptr <Piece> Qa1(new Queen('a', '1', Coords(0, 4)));
    newBoard.array[0][4] = Qa1;
    p1list.push_back(Qa1);
    shared_ptr <Piece> Ba2(new Bishop('a', '2', Coords(0, 5)));
    newBoard.array[0][5] = Ba2;
    p1list.push_back(Ba2);
    shared_ptr <Piece> Na2(new Knight('a', '2', Coords(0, 6)));
    newBoard.array[0][6] = Na2;
    p1list.push_back(Na2);
    shared_ptr <Piece> Ra2(new Rook('a', '2', Coords(0, 7)));
    newBoard.array[0][7] = Ra2;
    p1list.push_back(Ra2);
    shared_ptr <Piece> pa1(new Pawn('a', '1', Coords(1, 0)));
    newBoard.array[1][0] = pa1;
    p1list.push_back(pa1);
    shared_ptr <Piece> pa2(new Pawn('a', '2', Coords(1, 1)));
    newBoard.array[1][1] = pa2;
    p1list.push_back(pa2);
    shared_ptr <Piece> pa3(new Pawn('a', '3', Coords(1, 2)));
    newBoard.array[1][2] = pa3;
    p1list.push_back(pa3);
    shared_ptr <Piece> pa4(new Pawn('a', '4', Coords(1, 3)));
    newBoard.array[1][3] = pa4;
    p1list.push_back(pa4);
    shared_ptr <Piece> pa5(new Pawn('a', '5', Coords(1, 4)));
    newBoard.array[1][4] = pa5;
    p1list.push_back(pa5);
    shared_ptr <Piece> pa6(new Pawn('a', '6', Coords(1, 5)));
    newBoard.array[1][5] = pa6;
    p1list.push_back(pa6);
    shared_ptr <Piece> pa7(new Pawn('a', '7', Coords(1, 6)));
    newBoard.array[1][6] = pa7;
    p1list.push_back(pa7);
    shared_ptr <Piece> pa8(new Pawn('a', '8', Coords(1, 7)));
    newBoard.array[1][7] = pa8;
    p1list.push_back(pa8);

    shared_ptr <Piece> Kb1(new King('b', '1', Coords(7, 3)));
    newBoard.array[7][3] = Kb1;
    p2list.push_back(Kb1);
    shared_ptr <Piece> Rb1(new Rook('b', '1', Coords(7, 0)));
    newBoard.array[7][0] = Rb1;
    p2list.push_back(Rb1);
    shared_ptr <Piece> Nb1(new Knight('b', '1', Coords(7, 1)));
    newBoard.array[7][1] = Nb1;
    p2list.push_back(Nb1);
    shared_ptr <Piece> Bb1(new Bishop('b', '1', Coords(7, 2)));
    newBoard.array[7][2] = Bb1;
    p2list.push_back(Bb1);
    shared_ptr <Piece> Qb1(new Queen('b', '1', Coords(7, 4)));
    newBoard.array[7][4] = Qb1;
    p2list.push_back(Qb1);
    shared_ptr <Piece> Bb2(new Bishop('b', '2', Coords(7, 5)));
    newBoard.array[7][5] = Bb2;
    p2list.push_back(Bb2);
    shared_ptr <Piece> Nb2(new Knight('b', '2', Coords(7, 6)));
    newBoard.array[7][6] = Nb2;
    p2list.push_back(Nb2);
    shared_ptr <Piece> Rb2(new Rook('b', '2', Coords(7, 7)));
    newBoard.array[7][7] = Rb2;
    p2list.push_back(Rb2);
    shared_ptr <Piece> pb1(new Pawn('b', '1', Coords(6, 0)));
    newBoard.array[6][0] = pb1;
    p2list.push_back(pb1);
    shared_ptr <Piece> pb2(new Pawn('b', '2', Coords(6, 1)));
    newBoard.array[6][1] = pb2;
    p2list.push_back(pb2);
    shared_ptr <Piece> pb3(new Pawn('b', '3', Coords(6, 2)));
    newBoard.array[6][2] = pb3;
    p2list.push_back(pb3);
    shared_ptr <Piece> pb4(new Pawn('b', '4', Coords(6, 3)));
    newBoard.array[6][3] = pb4;
    p2list.push_back(pb4);
    shared_ptr <Piece> pb5(new Pawn('b', '5', Coords(6, 4)));
    newBoard.array[6][4] = pb5;
    p2list.push_back(pb5);
    shared_ptr <Piece> pb6(new Pawn('b', '6', Coords(6, 5)));
    newBoard.array[6][5] = pb6;
    p2list.push_back(pb6);
    shared_ptr <Piece> pb7(new Pawn('b', '7', Coords(6, 6)));
    newBoard.array[6][6] = pb7;
    p2list.push_back(pb7);
    shared_ptr <Piece> pb8(new Pawn('b', '8', Coords(6, 7)));
    newBoard.array[6][7] = pb8;
    p2list.push_back(pb8);

    return newBoard;
}

loadResults loadGame()
{
    Board loadBoard = Board();
    loadResults result;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            loadBoard.array[i][j] = emptyPiece;
        }
    }
    cout << "please enter file name\n";
    string filename;
    cin >> filename;
    ifstream fin(filename);
    if(fin.fail())
    {
        cout << "Error: Unable to open file, starting a new game\n";
        fin.close();
        result.turn = 1;
        result.loadBoard = newBoard();
        return result;
    }
    // while (fin.fail())
    // {
        // cout << "Error: Unable to open file, please enter valid file path or type 'new game' to start a new game\n";
        // cin >> filename;
        // bool newg = true;
        // string newString = "new game"
        // if (filename[8] = NULL)
        // {
        //     for (int i = 0; i < 8){
        //         if (filename[i] != newString[i])
        //             newg = false;
        //     }
        // }
        // else {newg = false}
        // if (newg) {return newBoard()};
        // ifstream fin(filename)
    // }
    fin >> result.turn;
    string data;
    string name;
    // string place;
    int num = 0;
    int x;
    int y;
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    while(fin >> data){
        if (num == 0){
            name = data;
            num = 1;
        } else if (num == 1){
            x = data[0]-'0';
            y = data[1]-'0';
            num = 0;
            switch(name[0]){
                case 'K':
                {
                    shared_ptr <Piece> newPiece(new King(name[1], name[2], Coords(x, y)));
                    loadBoard.array[x][y] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                    break;
                }
                case 'Q':
                {
                    shared_ptr <Piece> newPiece(new Queen(name[1], name[2], Coords(x, y)));
                    loadBoard.array[x][y] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                        break;
                }
                case 'R':
                {
                    shared_ptr <Piece> newPiece(new Rook(name[1], name[2], Coords(x, y)));
                    loadBoard.array[x][y] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                    break;
                }
                case 'B':
                {
                    shared_ptr <Piece> newPiece(new Bishop(name[1], name[2], Coords(x, y)));
                    loadBoard.array[x][y] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                    break;
                }
                case 'N':
                {
                    shared_ptr <Piece> newPiece(new Knight(name[1], name[2], Coords(x, y)));
                    loadBoard.array[x][y] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                    break;
                }
                case 'p':
                {
                    shared_ptr <Piece> newPiece(new Pawn(name[1], name[2], Coords(x, y)));
                    loadBoard.array[x][y] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                    break;
                }
            }
        }
    }
    fin.close();
    result.loadBoard = loadBoard;
    return result;
}

void saveGame(int turn)
{
    ofstream fout;
    cout << "Please enter file name\n";
    string filename;
    cin >> filename;
    fout.open(filename);
    if (fout.fail())
        cout << "Error, unable to write to file\n";
    else
        fout << turn << ' ';
        for (int i = 0; i < p1list.size(); i++)
            fout << p1list[i]->getName() << ' ' << p1list[i]->getCoords().x << p1list[i]->getCoords().y << ' ';
        for (int i = 0; i < p2list.size(); i++)
            fout << p2list[i]->getName() << ' ' << p2list[i]->getCoords().x << p2list[i]->getCoords().y << ' ';
    fout.close();
    return;
}

void display()
{
    
    cout << "  |  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  |" << endl << "--+";

    for (int z = 0; z < 8; z++)
        cout << "-----+";
    cout << endl;
    for (int i = 0; i < 8; i++){
        cout << i << " | ";
        for (int j = 0; j < 8; j++)
        {
            string name = board.array[i][j]->getName();
            if (name[0] == 'd')
                cout << " " << " " << " ";
            else
                cout << name;
            cout << " | ";
        }
        cout << endl << "--+";
        for (int z = 0; z < 8; z++)
            cout << "-----+";
        cout << endl;
    }
    return;   
}


int updateMovesPossible(int turn)
{
    int winner = 0;
    // bool Loss = true;
    bool check = false;
    bool threatBoard[8][8];
    // reset moves and threat
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            threatBoard[i][j] = false;
        }
    }
    for (int i = 0; i < p1list.size(); i++){
        p1list[i]->clear();
    }
    for (int i = 0; i < p2list.size(); i++){
        p2list[i]->clear();
    }
    
    switch (turn){
        case 1:
            for (int i = 0; i < p1list.size(); i++){
                p1list[i]->updateMoves(board, p1list, p2list, turn, threatBoard);
            }
            for (int i = 0; i < p2list.size(); i++){
                if (p2list[i]->updateMoves(board, p1list, p2list, turn, threatBoard)){
                    check = true;
                }
            }
            if (check){
                int moveCount = 0;          
                for (int i = 0; i < p1list.size(); i++){
                    moveCount += p1list[i]->pareMoves(threatBoard);
                }
                if (moveCount == 0){
                    winner = 2;
                }
            }
            break;
        case 2:
            for (int i = 0; i < p2list.size(); i++){
                p2list[i]->updateMoves(board, p1list, p2list, turn, threatBoard);
            }
            for (int i = 0; i < p1list.size(); i++){
                if (p1list[i]->updateMoves(board, p1list, p2list, turn, threatBoard)){
                    check = true;
                }
            }
            if (check){
                int moveCount = 0;          
                for (int i = 0; i < p2list.size(); i++){
                    moveCount += p2list[i]->pareMoves(threatBoard);
                }
                if (moveCount == 0){
                    winner = 1;
                }
            }
            break;
        default:
            cout << "Fatal Error: turn counter corrupted\n";
            assert(false);
    }
    return winner;
}

int move(const int turn)
{
    bool validSelection = false;
    cout << "Select a piece from the following list, or type 'C' for cancel. use only upper case letters.\n";
    Coords coordinates;
    char turnC;
    vector <Coords> moveList;
    int pieceListSize;
    vector <string> pieces;
    vector <bool> validPieces;
    switch (turn)
    {
        case 1:
            // turnC = 'a';
            pieceListSize = p1list.size();
            for (int i = 0; i < pieceListSize; i++){
                pieces.push_back(p1list[i]->getName());
                validPieces.push_back(p1list[i]->getMoves().size());
            }
            break;
        case 2:
            // turnC = 'b';
            pieceListSize = p2list.size();
            for (int i = 0; i < pieceListSize; i++){
                validPieces.push_back(p2list[i]->getMoves().size() > 0);
                pieces.push_back(p2list[i]->getName());
            }
            break;
        default:
            cout << "Fatal Error: turn counter corrupted\n";
            assert(false);
    }
    //receive input and verify it is valid
    for (int i = 0 ; i < pieceListSize; i++){
        if (validPieces[i])
            cout << "\t" << pieces[i] << endl;
    }
    int pieceNum = 0;
    string pieceName;
    while (! validSelection)
    {
        string input;
        cin >> input;
        if (input[0] == 'C') {
            return -1;
        } else {
            for (int i = 0 ; i < pieceListSize; i++){
                if (pieces[i] == input){
                    validSelection = true;
                    pieceNum = i;
                    pieceName = input;
                    break;
                }
            }
        }
        if(! validSelection)
            cout << "please enter valid piece name, or the letter 'C' for cancel.\n";    
    }

    switch (turn){
    case 1:
        moveList = p1list[pieceNum]->getMoves();
        coordinates = p1list[pieceNum]->getCoords();
        break;
    case 2:
        moveList = p2list[pieceNum]->getMoves();
        coordinates = p2list[pieceNum]->getCoords();
        break;
    }
    //Dipslay possible moves
    cout << "Please select the number of the move you would like to make for piece " << pieces[pieceNum] << ", Or enter C to go back to piece select.\n";
    for (int i = 1; i <= moveList.size(); i++){
        cout << "\t" << i << ". " << moveList[i-1].x << " ";
        switch(moveList[i-1].y)
        {
            case 0:
                cout << "a\n";
                break;
            case 1:
                cout << "b\n";
                break;
            case 2:
                cout << "c\n";
                break;
            case 3:
                cout << "d\n";
                break;
            case 4:
                cout << "e\n";
                break;
            case 5:
                cout << "f\n";
                break;
            case 6:
                cout << "g\n";
                break;
            case 7:
                cout << "h\n";
                break;
        }
    }
    //receive input and verify it is valid 
    validSelection = false;
    int inInt = 0;
    while (! validSelection){
        string input;
        cin >> input;
        if (input[0] == 'C') {
            return move(turn);
        } else if (input.size() < 3){
            inInt = 0;
            int a = input[0] - '0';
            if (!((a > 9) || (a < 0))){
                inInt = a;
                if (input.size() == 2){
                    inInt *= 10;
                    a = input[1] - '0';
                    if (!((a > 9) || (a < 0))){
                        inInt += a;
                    } else {
                        inInt = -1;
                    }
                }
            }
            inInt--;
            if ((inInt >= 0)&&(inInt < moveList.size()))
                validSelection = true;
        }
        if(! validSelection)
            cout << "please enter valid number.\n";   
    }

    // move piece
    cout << "test1\n";
    Coords target = moveList[inInt];
    if (board.array[target.x][target.y]->getName()[0] != 'd'){
        switch (turn)
        {
        case 1:
            for (int i = 0; i < p2list.size(); i++){
                if (board.array[target.x][target.y]->getName() == p2list[i]->getName()){
                    p2list.erase(p2list.begin()+i);
                    break;
                }
            }
            break;        
        case 2:
            for (int i = 0; i < p1list.size(); i++){
                if (board.array[target.x][target.y]->getName() == p1list[i]->getName()){
                    p1list.erase(p1list.begin()+i);
                    break;
                }
            }
            break;
        }
    }
    board.array[target.x][target.y] = board.array[coordinates.x][coordinates.y];
    board.array[target.x][target.y]->setCoords(target);
    board.array[coordinates.x][coordinates.y] = emptyPiece;
    cout << "test2\n";
    if (pieceName[0] == 'P'){
        bool needsPromotion = false;
        switch(turn){
            case 1:
                if (target.x == 7){
                    needsPromotion = true;
                }
                break;
            case 2:
                if (target.x == 0){
                    needsPromotion = true;
                }
                break;
        }
        if (needsPromotion){
            cout << "Please select promotion for " << pieceName << "\n\t1. Queen\n\t2. Rook\n\t3. Bishop\n\t4. Knight\n";
            vector <shared_ptr <Piece>> promotionPiece;
            int choice = 0;
            while (choice == 0)
            {
                string input;
                cin >> input;
                if (input.size() != 1){
                    input = "0";
                }
                switch (input[0])
                {
                case '1':
                    choice = 1;
                    break;
                case '2':
                    choice = 2;
                    break;
                case '3':
                    choice = 3;
                    break;
                case '4':
                    choice = 4;
                    break;
                default:
                    break;
                }
                if(! choice)
                    cout << "Please a number from 1 to 4.\n";    
            }
            char team = 'a'-1;
            char num = '0';
            switch(turn){
                case 1:
                    team += 1;
                    p1pieceCount[choice-1]++;
                    num += p1pieceCount[choice-1] % 10;
                    break;
                case 2:
                    team += 2;
                    p2pieceCount[choice-1]++;
                    num += p2pieceCount[choice-1] % 10;
                    break;
            }
            switch(choice){
                case 1:
                {
                    shared_ptr <Piece> newPiece(new Queen(team, num, Coords(target.x, target.y)));
                    board.array[target.x][target.y] = newPiece;
                    promotionPiece.push_back(newPiece);
                    break;
                }
                case 2:
                {
                    shared_ptr <Piece> newPiece(new Rook(team, num, Coords(target.x, target.y)));
                    board.array[target.x][target.y] = newPiece;
                    promotionPiece.push_back(newPiece);
                    break;
                }
                case 3:
                {
                    shared_ptr <Piece> newPiece(new Bishop(team, num, Coords(target.x, target.y)));
                    board.array[target.x][target.y] = newPiece;
                    promotionPiece.push_back(newPiece);
                    break;
                }
                case 4:
                {
                    shared_ptr <Piece> newPiece(new Knight(team, num, Coords(target.x, target.y)));
                    board.array[target.x][target.y] = newPiece;
                    promotionPiece.push_back(newPiece);
                    break;
                }
            }
            switch (turn)
            {
            case 1:
                p1list.push_back(promotionPiece[0]);
                break;
            case2:
                p2list.push_back(promotionPiece[0]);
                break;
            }
        }

    }    
    cout << "test3\n";
    return updateMovesPossible((turn % 2) + 1);
}


void turnLoop(int startTurn)
{
    bool finished = false;
    int win = 0;
    int turn = startTurn;
    while (! finished)
    {
        display();
        cout << "Player " << turn << " Please select one of the following options:\n\t1) Move\n\t2) Save Game\n\t3) Forfeight\n\t4) Quit\n";
        string input;
        cin >> input;
        char input1 = input[0];
        if (input[1])
            input1 = '5';
        switch (input1)
        {
            case '1':
                win = move(turn);
                if (win == -1)
                    win = 0;
                else
                {
                    turn = (turn % 2) + 1;
                }
                break;
            case '2':
                saveGame(turn);
                break;
            case '3':
                if (turn == 1)
                    win = 2;
                else
                    win = 1;
                break;
            case '4':
                finished = true; 
                break;
            default:
                cout << "Please enter a valid selection number" << endl;
        }
        if (win)
        {
            cout << "Congradulations! player " << win << " wins!\n";
            finished = true;
        }
    }
    cout << "Thank you for playing!\n";
    return;
}

int main()
{
    // Board board;
    int introNum = intro();
    int turn =1;
    switch (introNum)
    {
        case 1:
            board = newBoard();
            break;
        case 2:
        {
            loadResults result = loadGame();
            board = result.loadBoard;
            turn = result.turn;
            break;
        }
        case 3:
            return 0;
            break;
        default:
            cout << "Fatal Error, bad startup\n";
            assert(false);
    }
    p1pieceCount[0] = 1;
    p1pieceCount[1] = 2;
    p1pieceCount[2] = 2;
    p1pieceCount[3] = 2;
    p2pieceCount[0] = 1;
    p2pieceCount[1] = 2;
    p2pieceCount[2] = 2;
    p2pieceCount[3] = 2;

    updateMovesPossible(turn);
    turnLoop(turn);
    return 0;
}
