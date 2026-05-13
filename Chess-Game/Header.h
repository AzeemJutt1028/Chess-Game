#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
using namespace std;

//static variable to excess king of both sides//
static int greenKingRow = 0;
static int greenKingCol = 4;
static int redKingRow = 7;
static int redKingCol = 4;

class Board;		//Forward Declaration

//Class - Piece
class Piece {
protected:
	char symb;
	bool isWhite;
	

public:
	bool isMoved;
	Piece();
	Piece(char sym, bool white, bool ismoved);
	//Virtual Function to check if moev is validate
	virtual bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color);
	//Virtual Function to get symbol
	virtual char getSymbol()const;
	//Function to get color
	virtual bool getColor()const;
};

//Class - Pawn
class Pawn :public Piece {
public:
	Pawn();
	Pawn(char sym, bool white);
	//Overriden Function to check validate move
	bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color)override;
	//Overriden Function to get symbol
	char getSymbol()const override;
	//Overriden Function to get color
	bool getColor()const override;
	//friend bool check(Board& board, bool color);
};

//Class - Rook
class Rook :public Piece {
public:
	Rook();
	Rook(char sym, bool white);
	//Overriden Function to check validate move
	bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color)override;
	//Overriden Function to get symbol
	char getSymbol()const override;
	//Overriden Function to get color
	bool getColor()const override;
	//friend bool check(Board& board, bool color);
};

//Class - Knight
class Knight :public Piece {
public:
	Knight();
	Knight(char sym, bool white);
	//Overriden Function to check validate move
	bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color)override;
	//Overriden Function to get symbol
	char getSymbol()const override;
	//Overriden Function to get color
	bool getColor()const override;
	//friend bool check(Board& board, bool color);
};

//Class - Bishop
class Bishop :public Piece {
public:
	Bishop();
	Bishop(char sym, bool white);
	//Overriden Function to check validate move
	bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color)override;
	//Overriden Function to get symbol
	char getSymbol()const override;
	//Overriden Function to get color
	bool getColor()const override;
	//friend bool check(Board& board, bool color);
};

//Class - Queen
class Queen :public Piece {
public:
	Queen();
	Queen(char sym, bool white);
	//Overriden Function to check validate move
	bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color)override;
	//Overriden Function to get symbol
	char getSymbol()const override;
	//Overriden Function to get color
	bool getColor()const override;
	//friend bool check(Board& board, bool color);
};

//Class - King
class King :public Piece {
public:
	King();
	King(char sym, bool white);
	//Overriden Function to check validate move
	bool isValid(int col1, int row1, int col2, int row2, Board& board, bool color)override;
	//Overriden Function to get symbol
	char getSymbol()const override;
	//Overriden Function to get color
	bool getColor()const override;
	//friend bool check(Board& board, bool color);
};

//Class - Board 
class Board {

public:
	//char board[8][8];
	Piece* board[8][8];
	Board();
	//Function to initialize board
	void initializeBoard();
	//Function to display board
	void display() const;
};

//Class - PLayer
class Player {
private:
	string name;
	bool isWhite;

public:
	Player();
	Player(string n, bool white);
	//Function to get color of player
	bool getColor();
	//Function to get Player Name
	string getName();
	//Function to make move
	bool makeMove(string from, string to, Board& board, bool color);
};

//Class - Game
class Game {
private:
	Board board;
	Player* player1;
	Player* player2;
	bool isWhiteTurn;
	int count;
	bool converter;

public:
	Game();
	//Function to Start Game
	void startGame();
	//Function to Switch Turn
	bool switchTurn();
	//Function to Play
	void play();
	//Function to Check Game Over
	bool checkGameOver();
};