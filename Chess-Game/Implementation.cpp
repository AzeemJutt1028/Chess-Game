#include "Header.h"

//Function to check if move is valid
bool isInCheck(Board& board, bool color) {
	if (color) {			//Cheking Check on Green King
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (board.board[i][j] != nullptr) {
					if (board.board[i][j]->getColor() != color) {
						if (board.board[i][j]->isValid(j, i, greenKingCol, greenKingRow, board, !color)) {

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

							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

//Function for CHECK Print
bool check(Board& board, bool color) {
	if (isInCheck(board, color)) {
		cout << "\n\t\t\t\t=== " << (color ? "Green" : "Red") << " King is in CHECK! ===\n";
		return true;
	}
	return false;
}

//Class - Piece
Piece::Piece() {};
Piece::Piece(char sym, bool white, bool ismoved) :symb(sym), isWhite(white), isMoved(ismoved) {
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
Pawn::Pawn(char sym, bool white) :Piece(sym, white, 1) {
	//Initializer List Used
}
//Overriden Function to get symbol - for Pawn
char Pawn::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color - for Pawn
bool Pawn::getColor()const {
	return this->isWhite;
}

//Class - Rook
Rook::Rook() {};
Rook::Rook(char sym, bool white) :Piece(sym, white, 1) {
	//Initializer List Used
}
//Overriden Function to get symbol - for Rook
char Rook::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color - for Rook
bool Rook::getColor()const {
	return this->isWhite;
}


//Class - Knight
Knight::Knight() {};
Knight::Knight(char sym, bool white) :Piece(sym, white, 1) {
	//Initializer List Used
}
//Overriden Function to get symbol - for Knight
char Knight::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color - for Knight
bool Knight::getColor()const {
	return this->isWhite;
}


//Class - Bishop
Bishop::Bishop() {};
Bishop::Bishop(char sym, bool white) :Piece(sym, white, 1) {
	//Initializer List Used
}
//Overriden Function to get symbol - for Bishop
char Bishop::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color - for Bishop
bool Bishop::getColor()const {
	return this->isWhite;
}


//Class - Queen
Queen::Queen() {};
Queen::Queen(char sym, bool white) :Piece(sym, white, 1) {
	//Initializer List Used
}
//Overriden Function to get symbol - for Queen
char Queen::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color - for Queen
bool Queen::getColor()const {
	return this->isWhite;
}


//Class - King
King::King() {};
King::King(char sym, bool white) :Piece(sym, white, 1) {
	//Initializer List Used
}
//Overriden Function to get symbol - for King
char King::getSymbol()const {
	return this->symb;
}
//Overriden Function to get color - for King
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
	cout << "    A       B       C       D       E       F       G       H\n";
	int disp = 1;
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
		cout << "  " << disp++;
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

//Overriden Function to check validate move - for Pawn
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
				else {   // Red pawn not on starting row
					if (row1 - 1 == row2) {
						if (col1 == col2) {
							if (board.board[row1 - 1][col1] == nullptr) {
								checker = true;
							}
							else {
								checker = false;   // Blocked
							}
						}
						else if (row2 == row1 - 1 && col2 == col1 + 1) {
							if (board.board[row1 - 1][col1 + 1] != nullptr) {
								if (board.board[row1][col1]->getColor() !=
									board.board[row1 - 1][col1 + 1]->getColor()) {
									checker = true;
								}
								else {
									checker = false;   // Same color
								}
							}
							else {
								checker = false;   // Nothing to capture
							}
						}
						else if (row2 == row1 - 1 && col2 == col1 - 1) {
							if (board.board[row1 - 1][col1 - 1] != nullptr) {
								if (board.board[row1][col1]->getColor() !=
									board.board[row1 - 1][col1 - 1]->getColor()) {
									checker = true;
								}
								else {
									checker = false;   // Same color
								}
							}
							else {
								checker = false;   // Nothing to capture
							}
						}
						else {
							checker = false;   // Illegal Move
						}
					}
					else {
						checker = false;   // Illegal Move
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

	return checker;
}

//Overriden Function to check validate move - for Rook
bool Rook::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;

	if (board.board[row1][col1]->getColor() == color) {
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
	}
	else {

		checker = false;		//Illegal Move
	}

	return checker;
}

//Overriden Function to check if moev is validate - for Knight
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

	return checker;
}
//Overriden Function to check if moev is validate - for Bishop
bool Bishop::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;

	if (board.board[row1][col1]->getColor() == color) {
		if (abs(row2 - row1) == abs(col2 - col1)) {
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
			checker = false;	//Illegal Move

		}
	}
	else {
		checker = false;	//Illegal Move
	}

	return checker;
}

//Overriden Function to check if moev is validate - for Queen
bool Queen::isValid(int col1, int row1, int col2, int row2, Board& board, bool color) {
	bool checker = true;

	if (board.board[row1][col1]->getColor() == color) {
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
	}
	else {
		checker = false;		//Illegal Move
	}

	return checker;
}

//Overriden Function to check if moev is validate - for King
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


	//Cheking Validations for Castling..........
	if (color && row2 == 0 && col2 == 6) {
		checker = false;
		if (board.board[row1][col1]->isMoved) {
			if (board.board[0][7]->isMoved) {

				//Checking Piece in Path
				for (int i = col1 + 1; i < 7; i++) {
					if (board.board[row1][i] != nullptr) {

						return 0;
					}
				}

				//check if king is already in check
				if (!isInCheck(board, color)) {

					//Temporary move king one step
					board.board[0][5] = board.board[0][4];
					board.board[0][4] = nullptr;
					int saveKingCol = greenKingCol;
					greenKingCol = 5;

					//now check if IsInCheck
					if (!isInCheck(board, color)) {

						//Temporary move king one more step
						board.board[0][6] = board.board[0][5];
						board.board[0][5] = nullptr;
						greenKingCol = 6;

						//now check if IsInCheck
						if (!isInCheck(board, color)) {

							board.board[0][4] = board.board[0][6];
							board.board[0][6] = nullptr;
							greenKingCol = saveKingCol;
							return 1;
						}
						else {

							//Move king back
							board.board[0][4] = board.board[0][6];
							board.board[0][6] = nullptr;
							greenKingCol = saveKingCol;

							return 0;
						}
					}
					else {

						//Move king back
						board.board[0][4] = board.board[0][5];
						board.board[0][5] = nullptr;
						greenKingCol = saveKingCol;

						return 0;
					}
				}
				else {
					return 0;
				}

			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}

	}
	else if (color && row2 == 0 && col2 == 2) {
		checker = false;
		if (board.board[row1][col1]->isMoved) {
			if (board.board[0][0]->isMoved) {

				//Checking Piece in Path
				for (int i = col1 - 1; i > 0; i--) {
					if (board.board[row1][i] != nullptr) {
						return 0;
					}
				}

				//check if king is already in check
				if (!isInCheck(board, color)) {

					//Temporary move king one step
					board.board[0][3] = board.board[0][4];
					board.board[0][4] = nullptr;
					int saveKingCol = greenKingCol;
					greenKingCol = 3;

					//now check if IsInCheck
					if (!isInCheck(board, color)) {

						//Temporary move king one more step
						board.board[0][2] = board.board[0][3];
						board.board[0][3] = nullptr;
						greenKingCol = 2;

						//now check if IsInCheck
						if (!isInCheck(board, color)) {

							//Moving King Back
							board.board[0][4] = board.board[0][2];
							board.board[0][2] = nullptr;
							greenKingCol = saveKingCol;

							return 1;

						}
						else {
							//Move king back
							board.board[0][4] = board.board[0][2];
							board.board[0][2] = nullptr;
							greenKingCol = saveKingCol;

							return 0;
						}
					}
					else {
						//Move king back
						board.board[0][4] = board.board[0][3];
						board.board[0][3] = nullptr;
						greenKingCol = saveKingCol;

						return 0;
					}
				}
				else {
					return 0;
				}

			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else if (!color && row2 == 7 && col2 == 6) {
		checker = false;
		if (board.board[row1][col1]->isMoved) {
			if (board.board[7][7]->isMoved) {

				//Checking Piece in Path
				for (int i = col1 + 1; i < 7; i++) {
					if (board.board[row1][i] != nullptr) {
						return 0;
					}
				}

				//check if king is already in check
				if (!isInCheck(board, color)) {

					//Temporary move king one step
					board.board[7][5] = board.board[7][4];
					board.board[7][4] = nullptr;
					int saveKingCol = redKingCol;
					redKingCol = 5;

					//now check if IsInCheck
					if (!isInCheck(board, color)) {

						//Temporary move king one more step
						board.board[7][6] = board.board[7][5];
						board.board[7][5] = nullptr;
						redKingCol = 6;

						//now check if IsInCheck
						if (!isInCheck(board, color)) {

							board.board[7][4] = board.board[7][6];
							board.board[7][6] = nullptr;
							redKingCol = saveKingCol;

							return 1;
						}
						else {
							//Move king back
							board.board[7][4] = board.board[7][6];
							board.board[7][6] = nullptr;
							redKingCol = saveKingCol;

							return 0;
						}
					}
					else {
						//Move king back
						board.board[7][4] = board.board[7][5];
						board.board[7][5] = nullptr;
						redKingCol = saveKingCol;

						return 0;
					}
				}
				else {
					return 0;
				}

			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}

	}
	else if (!color && row2 == 7 && col2 == 2) {
		checker = false;
		if (board.board[row1][col1]->isMoved) {
			if (board.board[7][0]->isMoved) {

				//Checking Piece in Path
				for (int i = col1 - 1; i > 0; i--) {
					if (board.board[row1][i] != nullptr) {
						return 0;
					}
				}

				//check if king is already in check
				if (!isInCheck(board, color)) {

					//Temporary move king one step
					board.board[7][3] = board.board[7][4];
					board.board[7][4] = nullptr;
					int saveKingCol = redKingCol;
					redKingCol = 3;

					//now check if IsInCheck
					if (!isInCheck(board, color)) {

						//Temporary move king one more step
						board.board[7][2] = board.board[7][3];
						board.board[7][3] = nullptr;
						redKingCol = 2;

						//now check if IsInCheck
						if (!isInCheck(board, color)) {

							//Moving King Back
							board.board[7][4] = board.board[7][2];
							board.board[7][2] = nullptr;
							redKingCol = saveKingCol;

							return 1;

						}
						else {
							//Move king back
							board.board[7][4] = board.board[7][2];
							board.board[7][2] = nullptr;
							redKingCol = saveKingCol;

							return 0;
						}
					}
					else {
						//Move king back
						board.board[7][4] = board.board[7][3];
						board.board[7][3] = nullptr;
						redKingCol = saveKingCol;

						return 0;
					}
				}
				else {
					return 0;
				}

			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}

	return checker;
}

//Functions for CHECKMATE
bool canEscape(Board& board, int row1, int col1, int row2, int col2, bool color) {
	//Save Destination Piece
	Piece* temp = board.board[row2][col2];

	//Temporary Move
	board.board[row2][col2] = board.board[row1][col1];
	board.board[row1][col1] = nullptr;

	//Save King positions
	int oldGreenRow = greenKingRow;
	int oldGreenCol = greenKingCol;
	int oldRedRow = redKingRow;
	int oldRedCol = redKingCol;

	//Update King Positions
	if (board.board[row2][col2]->getColor() == true && board.board[row2][col2]->getSymbol() == 'K') {
		greenKingRow = row2;
		greenKingCol = col2;
	}
	else if (board.board[row2][col2]->getColor() == false && board.board[row2][col2]->getSymbol() == 'k') {
		redKingRow = row2;
		redKingCol = col2;
	}

	//Check After Move
	bool stillCheck = isInCheck(board, color);

	//Undo Move
	board.board[row1][col1] = board.board[row2][col2];
	board.board[row2][col2] = temp;

	//Restore King Positions
	greenKingCol = oldGreenCol;
	greenKingRow = oldGreenRow;
	redKingCol = oldRedCol;
	redKingRow = oldRedRow;

	//Checker if King is Ssafe
	if (!stillCheck) {
		return 1;
	}

	return 0;
}

//Function to CHECKMATE
bool checkMate(Board& board, bool color) {
	//Check if Really in check
	if (!isInCheck(board, color)) {
		return 0;
	}

	//Checking Every Piece of Current Player
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			//Check if piece exist
			if (board.board[i][j] != nullptr) {

				//Check Color is Opponent
				if (board.board[i][j]->getColor() == color) {

					//Try Every Position on Board
					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {

							//Check Valid Move
							if (board.board[i][j]->isValid(j, i, l, k, board, color)) {

								if (canEscape(board, i, j, k, l, color)) {		//Can King Escap
									return 0;	//Check can Stoped
								}
							}
						}
					}
				}
			}
		}
	}

	//CHECK MATE
	return 1;
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

//Function to get Name
string Player::getName() {
	return this->name;
}

//Function to make move
bool Player::makeMove(string from, string to, Board& board, bool color) {

	//Checking size of input string
	if (from.size() != 2 || to.size() != 2) {
		cout << "===Invalid input===\n";
		return 0;
	}

	//converting input string to indexes
	int col1, row1, col2, row2;
	col1 = tolower(from[0]) - 'a';
	row1 = from[1] - '1';
	col2 = tolower(to[0]) - 'a';
	row2 = to[1] - '1';

	//Checking Boundaries
	if (row1 < 0 || row1>7 || col1 < 0 || col1>7 || row2 < 0 || row2>7 || col2 < 0 || col2>7) {
		cout << "===Out of bounds===\n";
		return 0;
	}

	//Now Check Move Validation
	if (board.board[row1][col1] != nullptr) {
		if (board.board[row1][col1]->getColor() == color) {
			bool checker = board.board[row1][col1]->isValid(col1, row1, col2, row2, board, color);
			if (checker) {

				if (canEscape(board, row1, col1, row2, col2, color)) {

					board.board[row1][col1]->isMoved = false;
				
					//Castling.........Rook Movement
					if (row2 == 0 && col2 == 6) {
						//Move Rook
						board.board[0][5] = board.board[0][7];
						board.board[0][7] = nullptr;
						cout << "\nUpdating......\n";
					}
					else if (row2 == 0 && col2 == 2) {
						//Move Rook
						board.board[0][3] = board.board[0][0];
						board.board[0][0] = nullptr;
						cout << "\nUpdating......\n";
					}
					else if (row2 == 7 && col2 == 6) {
						//Move Rook
						board.board[7][5] = board.board[7][7];
						board.board[7][7] = nullptr;
						cout << "\nUpdating......\n";
					}
					else if (row2 == 7 && col2 == 2) {
						//Move Rook
						board.board[7][3] = board.board[7][0];
						board.board[7][0] = nullptr;
						cout << "\nUpdating......\n";
					}

					//Moving/Capturing piece........
					board.board[row2][col2] = board.board[row1][col1];
					board.board[row1][col1] = nullptr;

					//Updating King Positions if Needed
					Piece* temp = board.board[row2][col2];
					if (temp->getColor() == true && temp->getSymbol() == 'K') {
						greenKingCol = col2;
						greenKingRow = row2;
					}
					if (temp->getColor() == false && temp->getSymbol() == 'k') {
						redKingCol = col2;
						redKingRow = row2;
					}

					//Print Board
					cout << "\n\n";
					board.display();

					//Announce Check on Opponent
					bool oppColor = !color;
					if (check(board, oppColor)) {
						//////Check Statement is Printed in Check Function//////
					}
					if (checker) {
						if (temp->getSymbol() == 'P') {
							if (row2 == 7) {
								cout << "===Pawn Promotion===\n";
								int choice;
								do {
									cout << "Choose piece to promote to (1-Queen, 2-Rook, 3-Bishop, 4-Knight) : ";
									cin >> choice;
									cin.ignore();
									if (choice == 1) {
										board.board[row2][col2] = new Queen('Q', 1);
										board.display();
										break;
									}
									else if (choice == 2) {
										board.board[row2][col2] = new Rook('R', 1);
										board.display();
										break;
									}
									else if (choice == 3) {
										board.board[row2][col2] = new Bishop('B', 1);
										board.display();
										break;
									}
									else if (choice == 4) {
										board.board[row2][col2] = new Knight('N', 1);
										board.display();
										break;
									}
									else {
										cout << "Invalid Choice, Try Again...\n";
									}
								} while (true);
							}
						}
						else if (temp->getSymbol() == 'p') {
							if (row2 == 0) {
								cout << "===Pawn Promotion===\n";
								int choice;
								do {
									cout << "Choose piece to promote to (1-Queen, 2-Rook, 3-Bishop, 4-Knight) : ";
									cin >> choice;
									cin.ignore();
									if (choice == 1) {
										board.board[row2][col2] = new Queen('q', 0);
										board.display();
										break;
									}
									else if (choice == 2) {
										board.board[row2][col2] = new Rook('r', 0);
										board.display();
										break;
									}
									else if (choice == 3) {
										board.board[row2][col2] = new Bishop('b', 0);
										board.display();
										break;
									}
									else if (choice == 4) {
										board.board[row2][col2] = new Knight('n', 0);
										board.display();
										break;
									}
									else {
										cout << "Invalid Choice, Try Again...\n";
									}
								} while (true);
							}
						}
					}
					return 1;
				}
				else {
					cout << "===Illegal move (leaves your King in check)===\n";
					return 0;
				}

			}
			else {
				cout << "===Illegal move (piece rules)===\n";
				return 0;
			}
		}
		else {
			cout << "===No friendly piece at " << from << "===\n";
			return 0;
		}
	}
	else {
		cout << "===No piece at " << from << "===\n";
		return 0;
	}
}

//Class - Game
Game::Game() : isWhiteTurn(1) {
	string name;
	cout << "\nEnter Player 1 Name : ";
	getline(cin, name);
	player1 = new Player(name, 1);
	cout << "Enter Player 2 Name : ";
	getline(cin, name);
	player2 = new Player(name, 0);
}

//Function to Start Game
void Game::startGame() {
	board.initializeBoard();
	board.display();

	while (true) {
		if (!checkGameOver()) {
			play();
		}
		else {
			break;
		}
	}

}
//Function to Switch Turn
bool Game::switchTurn() {

	if (isWhiteTurn) {
		return 1;
	}
	else {
		return 0;
	}

}
//Function to Play
void Game::play() {
	string from, to;
	bool checker = switchTurn();
	bool playerColor = isWhiteTurn;
	bool moved = false;
	if (checker) {
		do {
			cout << "\nGreen Player (" << player1->getName() << ")'s Turn\n";

			if (isInCheck(board, playerColor)) {
				cout << "*** Your King is in CHECK — you must get out of check! ***\n";
			}

			cout << "\nEnter Starting Location : ";
			getline(cin, from);
			cout << "Enter Destination : ";
			getline(cin, to);

			moved = player1->makeMove(from, to, board, playerColor);
			if (!moved) {
				cout << "Try again...\n";
			}
		} while (!moved);

		isWhiteTurn = !isWhiteTurn;
	}
	else {
		do {
			cout << "\nRed Player (" << player2->getName() << ")'s Turn\n";

			if (isInCheck(board, playerColor)) {
				cout << "*** Your King is in CHECK — you must get out of check! ***\n";
			}

			cout << "\nEnter Starting Location : ";
			getline(cin, from);
			cout << "Enter Destination : ";
			getline(cin, to);

			moved = player2->makeMove(from, to, board, playerColor);
			if (!moved) {
				cout << "Try again...\n";
			}
		} while (!moved);

		isWhiteTurn = !isWhiteTurn;
	}
}
//Function to Check Game Over
bool Game::checkGameOver() {

	//Check for Green Player
	if (checkMate(board, 1)) {
		cout << "\n\n====== CHECKMATE ======\n";
		cout << "Red Player Wins\n";
		return 1;
	}

	//Check for Red Player
	if (checkMate(board, 0)) {
		cout << "\n\n====== CHECKMATE ======\n";
		cout << "Green Player Wins\n";
		return 1;
	}

	return 0;
}