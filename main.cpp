#include<iostream>
#include<cassert>
#include<fstream>
#include<vector>

#include "pieces/pieceClass.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/board.h"
using namespace std;


Board board;
vector <Piece> p1list;
vector <Piece> p2list;

int intro()
{
    int input = 0;
    bool finished = false;
    while (! finished)
    {
        cout << "Select command:\n\t1) Start New Game\n\t2) Load Saved Game\n\t3) Quit\n";
        cin >> input;
        if ((input > 0) &&(input < 4))
            finished = true;
        else
        {
            cout << "invalid selection, please select a numeric option";
        }
    }
    return input;
}

Board newBoard()
{
    Board newBoard;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            newBoard.array[i][j] = Piece();
        }
    }
    King Ka1('a', '1', Coords(0, 3));
    newBoard.array[0][3] = Ka1;
    p1list.push_back(Ka1);
    Rook Ra1('a', '1', Coords(0, 0));
    newBoard.array[0][0] = Ra1;
    p1list.push_back(Ra1);
    Knight Na1('a', '1', Coords(0, 1));
    newBoard.array[0][1] = Na1;
    p1list.push_back(Na1);
    Bishop Ba1('a', '1', Coords(0, 2));
    newBoard.array[0][2] = Ba1;
    p1list.push_back(Ba1);
    Queen Qa1('a', '1', Coords(0, 4));
    newBoard.array[0][4] = Qa1;
    p1list.push_back(Qa1);
    Bishop Ba2('a', '2', Coords(0, 5));
    newBoard.array[0][5] = Ba2;
    p1list.push_back(Ba2);
    Knight Na2('a', '2', Coords(0, 6));
    newBoard.array[0][6] = Na2;
    p1list.push_back(Na2);
    Rook Ra2('a', '2', Coords(0, 7));
    newBoard.array[0][7] = Ra2;
    p1list.push_back(Ra2);
    Pawn pa1('a', '1', Coords(1, 0));
    newBoard.array[1][0] = pa1;
    p1list.push_back(pa1);
    Pawn pa2('a', '2', Coords(1, 1));
    newBoard.array[1][1] = pa2;
    p1list.push_back(pa2);
    Pawn pa3('a', '3', Coords(1, 2));
    newBoard.array[1][2] = pa3;
    p1list.push_back(pa3);
    Pawn pa4('a', '4', Coords(1, 3));
    newBoard.array[1][3] = pa4;
    p1list.push_back(pa4);
    Pawn pa5('a', '5', Coords(1, 4));
    newBoard.array[1][4] = pa5;
    p1list.push_back(pa5);
    Pawn pa6('a', '6', Coords(1, 5));
    newBoard.array[1][5] = pa6;
    p1list.push_back(pa6);
    Pawn pa7('a', '7', Coords(1, 6));
    newBoard.array[1][6] = pa7;
    p1list.push_back(pa7);
    Pawn pa8('a', '8', Coords(1, 7));
    newBoard.array[1][7] = pa8;
    p1list.push_back(pa8);

    King Kb1('b', '1', Coords(7, 3));
    newBoard.array[7][3] = Kb1;
    p2list.push_back(Kb1);
    Rook Rb1('b', '1', Coords(7, 0));
    newBoard.array[7][0] = Rb1;
    p2list.push_back(Rb1);
    Knight Nb1('b', '1', Coords(7, 1));
    newBoard.array[7][1] = Nb1;
    p2list.push_back(Nb1);
    Bishop Bb1('b', '1', Coords(7, 2));
    newBoard.array[7][2] = Bb1;
    p2list.push_back(Bb1);
    Queen Qb1('b', '1', Coords(7, 4));
    newBoard.array[7][4] = Qb1;
    p2list.push_back(Qb1);
    Bishop Bb2('b', '2', Coords(7, 5));
    newBoard.array[7][5] = Bb2;
    p2list.push_back(Bb1);
    Knight Nb2('b', '2', Coords(7, 6));
    newBoard.array[7][6] = Nb2;
    p2list.push_back(Nb1);
    Rook Rb2('b', '2', Coords(7, 7));
    newBoard.array[7][7] = Rb2;
    p2list.push_back(Rb1);
    Pawn pb1('b', '1', Coords(6, 0));
    newBoard.array[6][0] = pb1;
    p2list.push_back(pb1);
    Pawn pb2('b', '2', Coords(6, 1));
    newBoard.array[6][1] = pb2;
    p2list.push_back(pb2);
    Pawn pb3('b', '3', Coords(6, 2));
    newBoard.array[6][2] = pb3;
    p2list.push_back(pb3);
    Pawn pb4('b', '4', Coords(6, 3));
    newBoard.array[6][3] = pb4;
    p2list.push_back(pb4);
    Pawn pb5('b', '5', Coords(6, 4));
    newBoard.array[6][4] = pb5;
    p2list.push_back(pb5);
    Pawn pb6('b', '6', Coords(6, 5));
    newBoard.array[6][5] = pb6;
    p2list.push_back(pb6);
    Pawn pb7('b', '7', Coords(6, 6));
    newBoard.array[6][6] = pb7;
    p2list.push_back(pb7);
    Pawn pb8('b', '8', Coords(6, 7));
    newBoard.array[6][7] = pb8;
    p2list.push_back(pb8);
    return newBoard;
}

Board loadGame()
{
    Board loadBoard;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            loadBoard.array[i][j] = Piece();
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
        return newBoard();
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
    string name;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            fin >> name;
            // cout << i << " " << j << ' ' << name << endl;
            if (name[0] != 'd')
            {
                if (name[0] == 'K')
                {
                    Piece newPiece = King(name[1], name[2], Coords(i, j));
                    loadBoard.array[i][j] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                }
                else if(name[0] == 'Q')
                {
                    Piece newPiece = Queen(name[1], name[2], Coords(i, j));
                    loadBoard.array[i][j] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                }
                else if(name[0] == 'R')
                {
                    Piece newPiece = Rook(name[1], name[2], Coords(i, j));
                    loadBoard.array[i][j] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                }
                else if(name[0] == 'B')
                {
                    Piece newPiece = Bishop(name[1], name[2], Coords(i, j));
                    loadBoard.array[i][j] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                }
                else if(name[0] == 'N')
                {
                    Piece newPiece = Knight(name[1], name[2], Coords(i, j));
                    loadBoard.array[i][j] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                }
                else if(name[0] == 'p')
                {
                    Piece newPiece = Pawn(name[1], name[2], Coords(i, j));
                    loadBoard.array[i][j] = newPiece;
                    if(name[1] == 'a')
                        p1list.push_back(newPiece);
                    else
                        p2list.push_back(newPiece);
                }
                else
                {
                    cout << "Error: invalid file. starting new Game.\n";
                    return newBoard();
                }
            }
        }
    }
    fin.close();
    return loadBoard;
}

void saveGame()
{
    ofstream fout;
    cout << "Please enter file name\n";
    string filename;
    cin >> filename;
    fout.open(filename);
    if (fout.fail())
        cout << "Error, unable to write to file\n";
    else
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                // cout << i << " " << j << ' ' << board.array[i][j].getName() << endl;
                fout << board.array[i][j].getName() << " ";
            }
        }
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
            string name = board.array[i][j].getName();
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
    bool p1Loss = true;
    bool p1check = false;
    bool p2Loss = true;
    bool p2check = false;
    bool threatBoard[8][8];
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            threatBoard[i][j] = false;
        }
    }
    // check current player's king's moves

    // check opposing player's pieces moves

    //check remaining current player pieces moves

    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         if (board.array[i][j].updateMoves(board))
    //         {
    //             if (board.array[i][j].getName()[1] == 'a')
    //                 p1check = true
    //         }                
    //     }
    // }
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         board.array[i][j].updateMoves(board, p1list, p2list);
    //     }
    // }
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         board.array[i][j].checkProtecting();

    //     }
    // }
    return winner;
}

int move(const int turn)
{
    bool validSelection = false;
    cout << "Select piece or type 'c' for cancel\n";
    Coords coordinates;
    char turnC;
    vector <Piece> turnList;
    switch (turn)
    {
        case 1:
            turnC = 'a';
            turnList = p1list;
            break;
        case 2:
            turnC = 'b';
            turnList = p2list;
            break;
        default:
            cout << "Fatal Error: turn counter corrupted\n";
            assert(false);
    }
    //receive input and vrify it is valid
    while (! validSelection)
    {
        string input;
        cin >> input;
        if (input[0] == 'c')
            return -1;
        else if (input[1] != turnC)
            cout << "Please choose one of your own pieces\n";
        else if (input[3])
            cout << "please enter valid piece\n";
        else
        {
            for (int i = 0; i < turnList.size(); i++)
            {
                string name = turnList[i].getName();              
                bool valid = true;
                for (int k = 0; k < 3; k++)
                {
                    if (name[k] != input[k])
                        valid = false;
                        break;
                }
                if (valid)
                {
                    // coordinates = turnList[i].getCoords();
                    validSelection = true;
                    break;  
                }
            }
        }
        if(! validSelection)
            cout << "please enter valid piece\n";
    }
    cout << coordinates.x << ' ' << coordinates.y << endl;

    //Dipslay possible moves

    //receive input and verify it is valid 

    // Coords targetCoords;
    // move piece
    // board.array[coordinates.x][coordinates.y].setCoords(targetCoords);
    // board.array[targetCoords.x][targetCoords.y] = board.array[coordinates.x][coordinates.y];
    // board.array[coordinates.x][coordinates.y] = Piece();

    return updateMovesPossible((turn % 2) + 1);
}


void turnLoop()
{
    bool finished = false;
    int win = 0;
    int turn = 1;
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
                saveGame();
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
    Board board;

    switch (intro())
    {
        case 1:
            board = newBoard();
            break;
        case 2:
            board = loadGame();
            break;
        case 3:
            break;
        default:
            cout << "Fatal Error, bad startup\n";
            assert(false);
    }
    // display(board);
    updateMovesPossible(1);
    turnLoop();
    return 0;
}
