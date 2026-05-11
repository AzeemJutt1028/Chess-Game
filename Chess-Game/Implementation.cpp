#include "Header.h"

///////Friend Function to check if move is valid ////////
bool check(Board& board, bool color) {
	if (!color) {			//Cheking Check on Green King
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board.board[i][j] != nullptr) {
					if (board.board[i][j]->getColor() != color) {
						if (board.board[i][j]->isValid(j, i, greenKingCol, greenKingRow, board, !color)) {
							cout << "\n\n\t\t\t\t===Check on Green King===\n";
							return true;
						}
					}
				}
			}
		}
	}
	else {					//Cheking Check on Red King
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board.board[i][j] != nullptr) {
					if (board.board[i][j]->getColor() != color) {
						if (board.board[i][j]->isValid(j, i, redKingCol, redKingRow, board, !color)) {
							cout << "\n\n\t\t\t\t===Check on Red King===\n";
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

//Class - Piece
Piece::Piece() {};
Piece::Piece(char sym, bool white) :symb(sym), isWhite(white) {
	//Initializer List Used
}
//Virtual Function to get symbol
char Piece::getSymbol() const {
	return this->symb;
}
//Function to get color
bool Piece::getColor()const {
	return this->isWhite;
}

//Class - Pawn
Pawn::Pawn() {};
Pawn::Pawn(char sym, bool white) :Piece(sym, white) {
	//Initializer List Used
}
//Overriden Function to get symbol
char Pawn::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color
bool Pawn::getColor()const {
	return this->isWhite;
}

//Class - Rook
Rook::Rook() {};
Rook::Rook(char sym, bool white) :Piece(sym, white) {
	//Initializer List Used
}
//Overriden Function to get symbol
char Rook::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color
bool Rook::getColor()const {
	return this->isWhite;
}


//Class - Knight
Knight::Knight() {};
Knight::Knight(char sym, bool white) :Piece(sym, white) {
	//Initializer List Used
}
//Overriden Function to get symbol
char Knight::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color
bool Knight::getColor()const {
	return this->isWhite;
}


//Class - Bishop
Bishop::Bishop() {};
Bishop::Bishop(char sym, bool white) :Piece(sym, white) {
	//Initializer List Used
}
//Overriden Function to get symbol
char Bishop::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color
bool Bishop::getColor()const {
	return this->isWhite;
}


//Class - Queen
Queen::Queen() {};
Queen::Queen(char sym, bool white) :Piece(sym, white) {
	//Initializer List Used
}
//Overriden Function to get symbol
char Queen::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color
bool Queen::getColor()const {
	return this->isWhite;
}


//Class - King
King::King() {};
King::King(char sym, bool white) :Piece(sym, white) {
	//Initializer List Used
}
//Overriden Function to get symbol
char King::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color
bool King::getColor()const {
	return this->isWhite;
}


//Class - Board
Board::Board() {}
//Function to initialize board
void Board::initializeBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i >= 0 && i < 2) {
				if (i == 1) {
					board[i][j] = new Pawn('P', 1);
				}
				else if (j == 0 || j == 7) {
					board[i][j] = new Rook('R', 1);
				}
				else if (j == 1 || j == 6) {
					board[i][j] = new Knight('N', 1);
				}
				else if (j == 2 || j == 5) {
					board[i][j] = new Bishop('B', 1);
				}
				else if (j == 3) {
					board[i][j] = new Queen('Q', 1);
				}
				else {
					board[i][j] = new King('K', 1);
				}
			}
			else if (i >= 6 && i < 8) {
				if (i == 6) {
					board[i][j] = new Pawn('p', 0);
				}
				else if (j == 0 || j == 7) {
					board[i][j] = new Rook('r', 0);
				}
				else if (j == 1 || j == 6) {
					board[i][j] = new Knight('n', 0);
				}
				else if (j == 2 || j == 5) {
					board[i][j] = new Bishop('b', 0);
				}
				else if (j == 3) {
					board[i][j] = new Queen('q', 0);
				}
				else {
					board[i][j] = new King('k', 0);
				}
			}
			else {
				board[i][j] = nullptr;
			}
		}
	}
}

//Function to display board
void Board::display() const {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << "+-------";
		}
		cout << "+";
		cout << "\n";
		for (int k = 0; k < 8; k++) {
			if (board[i][k] != nullptr) {
				if (board[i][k]->getColor()) {
					cout << "|  " << GREEN << board[i][k]->getSymbol() << RESET << "    ";
				}
				else {
					cout << "|  " << RED << board[i][k]->getSymbol() << RESET << "    ";
				}
			}
			else {
				cout << "|       ";
			}
		}
		cout << "|";
		if (i == 7) {
			cout << "\n";
			for (int j = 0; j < 8; j++) {
				cout << "+-------";
			}
			cout << "+";
		}
		cout << endl;
	}
}

//Virtual Function to check if move is validate
bool Piece::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	///////////////////////////////////
	return 1;
}
bool Pawn::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;


	if (board.board[row1][col1] != nullptr) {
		if (board.board[row1][col1]->getColor() == color) {
			if (board.board[row1][col1]->getColor()) {		//For Green Player

				if (row1 == 1) {
					if ((row2 <= row1 + 2) && (row2 > row1)) {
						if (col1 == col2) {
							if ((row2 == row1 + 1) && (board.board[row1 + 1][col1] == nullptr)) {
								checker = true;
							}
							else {
								if ((board.board[row1 + 1][col1] == nullptr) && (board.board[row1 + 2][col1] == nullptr)) {
									checker = true;
								}
							}
						}
						else if ((row2 == row1 + 1 && col2 == col1 + 1)) {
							if ((board.board[row1 + 1][col1 + 1] != nullptr)) {
								if ((board.board[row1][col1]->getColor() != board.board[row1 + 1][col1 + 1]->getColor())) {
									checker = true;
								}
								else {
									checker = false;	//Illegal Move
								}
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else if ((row2 == row1 + 1 && col2 == col1 - 1)) {
							if ((board.board[row1 + 1][col1 - 1] != nullptr)) {
								if ((board.board[row1][col1]->getColor() != board.board[row1 + 1][col1 - 1]->getColor())) {
									checker = true;
								}
								else {
									checker = false;	//Illegal Move
								}
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else {
							checker = false;	//Illegal Move
						}
					}
					else {
						checker = false;	//Illegal Move
					}
				}
				else {
					if (row1 + 1 == row2) {
						if (col1 == col2) {
							if ((board.board[row1 + 1][col1] == nullptr)) {
								checker = true;
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else if ((row2 == row1 + 1 && col2 == col1 + 1)) {
							if ((board.board[row1 + 1][col1 + 1] != nullptr)) {
								if ((board.board[row1][col1]->getColor() != board.board[row1 + 1][col1 + 1]->getColor())) {
									checker = true;
								}
								else {
									checker = false;	//Illegal Move
								}
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else if ((row2 == row1 + 1 && col2 == col1 - 1)) {
							if ((board.board[row1 + 1][col1 - 1] != nullptr)) {
								if ((board.board[row1][col1]->getColor() != board.board[row1 + 1][col1 - 1]->getColor())) {
									checker = true;
								}
								else {
									checker = false;	//Illegal Move
								}
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else {
							checker = false;	//Illegal Move
						}
					}
					else {
						checker = false;	//Illegal Move
					}
				}

			}
			else {			//For Red Player
				if (row1 == 6) {
					if ((row2 >= row1 - 2) && (row2 < row1)) {
						if (col1 == col2) {
							if ((row2 == row1 - 1) && (board.board[row1 - 1][col1] == nullptr)) {
								checker = true;
							}
							else {
								if ((board.board[row1 - 1][col1] == nullptr) && (board.board[row1 - 2][col1] == nullptr)) {
									checker = true;
								}
							}
						}
						else if ((row2 == row1 - 1 && col2 == col1 + 1)) {
							if ((board.board[row1 - 1][col1 + 1] != nullptr)) {
								if ((board.board[row1][col1]->getColor() != board.board[row1 - 1][col1 + 1]->getColor())) {
									checker = true;
								}
								else {
									checker = false;	//Illegal Move
								}
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else if ((row2 == row1 - 1 && col2 == col1 - 1)) {
							if ((board.board[row1 - 1][col1 - 1] != nullptr)) {
								if ((board.board[row1][col1]->getColor() != board.board[row1 - 1][col1 - 1]->getColor())) {
									checker = true;
								}
								else {
									checker = false;	//Illegal Move
								}
							}
							else {
								checker = false;	//Illegal Move
							}
						}
						else {
							checker = false;	//Illegal Move
						}
					}
					else {
						checker = false;	//Illegal Move
					}
				}
			}
		}
		else {
			checker = false;	//Illegal Move
		}

	}
	else {
		checker = false;	//Illegal Move
	}
	//if (checker) {
	//	bool test;
	//	if (board.board[row1][col1]->getColor()) {		//Green Moved    checking if check on red king
	//		test = check(board, color);

	//	}
	//	else {			//Red Moved    checking if check on green king
	//		test = check(board, color);
	//	}
	//}
	return checker;
}

//Overriden Function to check validate move
bool Rook::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {

	bool checker = true;
	if ((row1 != row2) || (col1 != col2)) {
		if (row1 == row2) {			//move in same row

			if (col2 > col1) {		//move forward
				for (int i = col1 + 1; i < col2; i++) {
					if (board.board[row1][i] != nullptr) {		//check for obstacle in path

						checker = false;		//Illegal Move
						break;
					}

				}

			}
			else {		//move backward
				for (int i = col1 - 1; i > col2; i--) {
					if (board.board[row1][i] != nullptr) {		//check for obstacle in path

						checker = false;		//Illegal Move
						break;
					}

				}

			}
		}
		else if (col1 == col2) {		//move in same coloumn

			if (row2 > row1) {		//move upward

				for (int i = row1 + 1; i < row2; i++) {
					if (board.board[i][col1] != nullptr) {		//check for obstacle in path
						checker = false;		//Illegal Move
						break;
					}

				}


			}
			else {		//move downward

				for (int i = row1 - 1; i > row2; i--) {
					if (board.board[i][col1] != nullptr) {		//check for obstacle in path

						checker = false;		//Illegal Move
						break;
					}

				}

			}
		}
		else {

			checker = false;		//Illegal Move
		}
	}
	else {

		checker = false;		//Illegal Move
	}

	if (checker) {
		if (board.board[row2][col2] != nullptr) {
			if (board.board[row1][col1]->getColor() == board.board[row2][col2]->getColor()) {		//check colors are different
				checker = false;		//Illegal Move
			}
		}
	}
	//if (checker) {
	//	bool test;
	//	if (board.board[row1][col1]->getColor()) {		//Green Moved    checking if check on red king
	//		test = check(board, color);
	//	}
	//	else {			//Red Moved    checking if check on green king
	//		test = check(board, color);
	//	}
	//}

	return checker;
}

//Overriden Function to check if moev is validate
bool Knight::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;
	if (board.board[row1][col1]->getColor() == color) {
		if ((row2 == row1 + 2 && col2 == col1 + 1) || (row2 == row1 + 2 && col2 == col1 - 1) || (row2 == row1 - 2 && col2 == col1 + 1) || (row2 == row1 - 2 && col2 == col1 - 1) || (row2 == row1 + 1 && col2 == col1 + 2) || (row2 == row1 + 1 && col2 == col1 - 2) || (row2 == row1 - 1 && col2 == col1 + 2) || (row2 == row1 - 1 && col2 == col1 - 2)) {
			if (board.board[row2][col2] != nullptr) {
				if (board.board[row1][col1]->getColor() != board.board[row2][col2]->getColor()) {
					checker = true;
				}
				else {
					checker = false;	//Illegal Move
				}
			}
			else {
				checker = true;
			}
		}
		else {
			checker = false;	//Illegal Move
		}
	}
	else {
		checker = false;	//Illegal Move
	}
	///////////////////////////////////
	//if (checker) {
	//	bool test;
	//	if (board.board[row1][col1]->getColor()) {		//Green Moved    checking if check on red king
	//		test = check(board, color);
	//	}
	//	else {			//Red Moved    checking if check on green king
	//		test = check(board, color);
	//	}
	//}
	return checker;
}
//Overriden Function to check if moev is validate
bool Bishop::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;
	if (board.board[row1][col1]->getColor() == color) {
		if (abs(row2 - row1) == abs(col2 - col1)) {
			if(board.board[row2][col2] != nullptr) {
				if (board.board[row1][col1]->getColor() == board.board[row2][col2]->getColor()) {
					checker = false;	//Illegal Move
					return checker;
				}
				else {
					checker = true;
				}
			}
			else {
				checker = true;
			}
			//check path obstacle
			int rowDirection = (row2 - row1) / abs(row2 - row1);    //-1 or +1
			int colDirection = (col2 - col1) / abs(col2 - col1);    //-1 or +1
			for (int i = row1 + rowDirection; i != row2 && checker == true; i += rowDirection) {
				for (int j = col1 + colDirection; j != col2 && checker == true; j += colDirection) {
					if (abs(i - row1) == abs(j - col1)) {
						if (board.board[i][j] != nullptr) {
							checker = false;	//Illegal Move
							break;
						}
						else {
							checker = true;
						}
					}
				}
			}
		}
		else {
			checker = false;	//Illegal Move

		}
	}
	else {
		checker = false;	//Illegal Move
	}
	///////////////////////////////////
	//if(checker) {
	//	bool test;
	//	if (board.board[row1][col1]->getColor()) {		//Green Moved    checking if check on red king
	//		test = check(board, color);
	//	}
	//	else {			//Red Moved    checking if check on green king
	//		test = check(board, color);
	//	}
	//}
	return checker;
}

//Overriden Function to check if moev is validate
bool Queen::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;
	if ((row1 == row2) || (col1 == col2)) {
		if (row1 == row2) {			//move in same row

			if (col2 > col1) {		//move forward
				for (int i = col1 + 1; i < col2; i++) {
					if (board.board[row1][i] != nullptr) {		//check for obstacle in path

						checker = false;		//Illegal Move
						break;
					}

				}

			}
			else {		//move backward
				for (int i = col1 - 1; i > col2; i--) {
					if (board.board[row1][i] != nullptr) {		//check for obstacle in path

						checker = false;		//Illegal Move
						break;
					}

				}

			}
		}
		else {		//move in same coloumn

			if (row2 > row1) {		//move upward

				for (int i = row1 + 1; i < row2; i++) {
					if (board.board[i][col1] != nullptr) {		//check for obstacle in path
						checker = false;		//Illegal Move
						break;
					}

				}


			}
			else {		//move downward

				for (int i = row1 - 1; i > row2; i--) {
					if (board.board[i][col1] != nullptr) {		//check for obstacle in path

						checker = false;		//Illegal Move
						break;
					}

				}

			}
		}

		if (checker) {
			if (board.board[row2][col2] != nullptr) {
				if (board.board[row1][col1]->getColor() == board.board[row2][col2]->getColor()) {		//check colors are different
					checker = false;		//Illegal Move
				}
			}
		}

	}
	else if (abs(row2 - row1) == abs(col2 - col1)) {
		if (board.board[row2][col2] != nullptr) {
			if (board.board[row1][col1]->getColor() == board.board[row2][col2]->getColor()) {
				checker = false;	//Illegal Move
				return checker;
			}
			else {
				checker = true;
			}
		}
		else {
			checker = true;
		}
		//check path obstacle
		int rowDirection = (row2 - row1) / abs(row2 - row1);    //-1 or +1
		int colDirection = (col2 - col1) / abs(col2 - col1);    //-1 or +1
		for (int i = row1 + rowDirection; i != row2 && checker == true; i += rowDirection) {
			for (int j = col1 + colDirection; j != col2 && checker == true; j += colDirection) {
				if (abs(i - row1) == abs(j - col1)) {
					if (board.board[i][j] != nullptr) {
						checker = false;	//Illegal Move
						break;
					}
					else {
						checker = true;
					}
				}
			}
		}
	}
	else {

		checker = false;		//Illegal Move
	}
	//if (checker) {
	//	bool test;
	//	if (board.board[row1][col1]->getColor()) {		//Green Moved    checking if check on red king
	//		test = check(board, color);
	//	}
	//	else {			//Red Moved    checking if check on green king
	//		test = check(board, color);
	//	}
	//}
	return checker;
}
//Overriden Function to check if moev is validate
bool King::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;
	if (board.board[row1][col1]->getColor() == color) {
		if ((abs(row2 - row1) == 1 && col2 == col1) || (row2 == row1 && abs(col2 - col1) == 1) || (abs(row2 - row1) == 1 && abs(col2 - col1) == 1)) {
			if (board.board[row2][col2] != nullptr) {
				if (board.board[row1][col1]->getColor() != board.board[row2][col2]->getColor()) {
					checker = true;
				}
				else {
					checker = false;	//Illegal Move
				}
			}
			else {
				checker = true;
			}
		}
		else {
			checker = false;	//Illegal Move
		}
	}
	else {
		checker = false;	//Illegal Move
	}

	//king position update//
	if(checker) {
		if (board.board[row1][col1]->getColor()) {		//Green King
			greenKingRow = row2;
			greenKingCol = col2;
		}
		else {			//Red King
			redKingRow = row2;
			redKingCol = col2;
		}
	}


	///////////////////////////////////
	return checker;
}

//Class - PLayer
Player::Player() {};
Player::Player(string n, bool white) :name(n), isWhite(white) {
	//Initializer List Used
}
//Function to get Player Color
bool Player::getColor() {
	return this->isWhite;
}
//Function to make move
void Player::makeMove(string from, string to, Board& board, bool color) {
	int col1, row1, col2, row2;
	col1 = tolower(from[0]) - 'a';
	//col1 = from[0];
	row1 = from[1] - '0';
	col2 = tolower(to[0]) - 'a';
	//col2 = to[0];
	row2 = to[1] - '0';

	if (board.board[row1 - 1][col1] != nullptr) {
		if (board.board[row1 - 1][col1]->getColor() == color) {
			bool checker = board.board[row1 - 1][col1]->isValid(col1, row1 - 1, col2, row2 - 1, board, color);
			if (checker) {
				board.board[row2 - 1][col2] = board.board[row1 - 1][col1];
				board.board[row1 - 1][col1] = nullptr;
				cout << "\n\n";
				if (checker) {
					bool test;
					test = check(board, color);
					cout << "\n\n";
					board.display();
				}
				else {
					cout << "\n\n===Illegal Move===\n";
					board.display();
				}
			}
			else {
				cout << "\n\n===Illegal Move===\n";
				board.display();
			}
		}
		else {
			cout << "\n\n===Illegal Move===\n";
			board.display();
		}
	}
}

//Class - Game
	Game::Game(): count(0), converter(1) {
	string name;
	cout << "\nEnter Player 1 Name : ";
	getline(cin, name);
	player1 = new Player(name, 1);
	cout << "\nEnter Player 2 Name : ";
	getline(cin, name);
	player2 = new Player(name, 0);
}
//Function to Start Game
void Game::startGame() {
	board.initializeBoard();
	board.display();
	bool checker;
	do {
		play();
		checker = checkGameOver();
	} while (checker);
}
//Function to Switch Turn
bool Game::switchTurn() {
	if (converter) {
		converter = false;
		return 1;
	}
	else {
		converter = true;
		return 0;
	}
}
//Function to Play
void Game::play() {
	string from, to;
	bool checker = switchTurn();
	if (checker) {
		cout << "\nPlayer==========1\n";
		cout << "\nEnter Starting Location : ";
		getline(cin, from);
		cout << "\nEnter Destination : ";
		getline(cin, to);
		bool playerColor = player1->getColor();
		player1->makeMove(from, to, board, playerColor);
	}
	else {
		cout << "\nPlayer==========2\n";
		cout << "\nEnter Starting Location : ";
		getline(cin, from);
		cout << "\nEnter Destination : ";
		getline(cin, to);
		bool playerColor = player2->getColor();
		player2->makeMove(from, to, board, playerColor);
	}
}
//Function to Check Game Over
bool Game::checkGameOver() {
	count++;
	if (count == 15)
		return 0;
	else
		return 1;
}

