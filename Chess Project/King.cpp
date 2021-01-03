#include "King.h"


/*
This function builds a new king - the constructor
input: the color of the king
output: none
*/
King::King(unsigned color) : Piece(color, color == 0 ? 'K' : 'k'){
	this->doneFirstMove = false;
}


/*
This function moves the king
input: the board, where the king is and where is the dest, and if the function called
to check if the king can do check
output: none
*/
void King::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
{
	enum rows{LastRow = 0, FirstRow = 7};
	enum cols{LeftRook, LeftKnight, LeftBishop, Queenpos, Kingpos, RightBishop, RightKnight, RightRook};
	std::string fixedPosition = Piece::breakPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	unsigned xTo = fixedPosition[0] - '0';
	unsigned yTo = fixedPosition[1] - '0';

	if (x == xTo && y == yTo && !checkMove) {
		throw SamePlace();
	}

	bool leftRight = (y == yTo && (x - 1 == xTo || x + 1 == xTo));
	bool upDown = (x == xTo && (y - 1 == yTo || y + 1 == yTo));
	bool upRightLeft = (y + 1 == yTo && (x - 1 == xTo || x + 1 == xTo));
	bool downRightLeft = (y - 1 == yTo && (x - 1 == xTo || x + 1 == xTo));
	bool validMove = ( leftRight || upDown || upRightLeft || downRightLeft);
	size_t size = boardState.size();

	if (validMove) 
	{
		if (boardState[yTo][xTo]) 
		{
			if (boardState[yTo][xTo]->getColor() == this->color) // if player from the same color
			{
				if (!checkMove) {
					throw PieceAtDestPlace();
					std::cout << "can't move!";
				}
			}
			else
			{
				if (!checkMove) {
					checkForSelfCheck(x, y, xTo, yTo, boardState);
					delete boardState[yTo][xTo]; // deleting ("eating") the other piece
					boardState[yTo][xTo] = this; // moving the king
					boardState[y][x] = nullptr; // emptying the old place
				}
				else {
					throw Check();
				}
			}
		}
		else 
		{
			if (!checkMove) {
				checkForSelfCheck(x, y, xTo, yTo, boardState);
				boardState[yTo][xTo] = this; // moving the king
				boardState[y][x] = nullptr; // emptying the old place
			}
			else {
				throw Check();
			}
		}
		// Update the new x, y after a successful move
		updateXY(xTo, yTo, color);
	}
	else if (!doneFirstMove && !checkMove) //  the king didn't move
	{
		if (color == 0) // white
		{
			if ((xTo == RightRook || xTo == LeftRook) && yTo == FirstRow) // right indexes
			{
				// the rook is at its first position and didn't move yet
				if (boardState[yTo][xTo] && boardState[yTo][xTo]->getSymbol() == 'R' && !boardState[yTo][xTo]->hasMoved())
				{
					if (xTo == RightRook)
					{
						// no pieces blocking on the way
						if (boardState[FirstRow][6] == nullptr && boardState[FirstRow][5] == nullptr)
						{
							boardState[FirstRow][RightKnight] = boardState[FirstRow][Kingpos];
							boardState[FirstRow][RightBishop] = boardState[FirstRow][RightRook];
							boardState[FirstRow][RightRook] = nullptr;
							boardState[FirstRow][Kingpos] = nullptr;
							Player::whiteX = RightKnight;
							Player::whiteY = FirstRow;
							this->setHasMove(true);
							boardState[FirstRow][RightBishop]->setHasMove(true);
						}
						else
						{
							throw PieceAtDestPlace();
						}
					}
					else if (xTo == LeftRook)
					{
						// no pieces blocking on the way
						if (boardState[FirstRow][LeftKnight] == nullptr && boardState[FirstRow][LeftBishop] == nullptr && boardState[FirstRow][Queenpos] == nullptr)
						{
							boardState[FirstRow][LeftBishop] = boardState[FirstRow][Kingpos];
							boardState[FirstRow][Queenpos] = boardState[FirstRow][LeftRook];
							boardState[FirstRow][Kingpos] = nullptr;
							boardState[FirstRow][LeftRook] = nullptr;
							Player::whiteX = LeftBishop;
							Player::whiteY = FirstRow;
							this->setHasMove(true);
							boardState[FirstRow][Queenpos]->setHasMove(true);
						}
						else
						{
							throw PieceAtDestPlace();
						}
					}
					else
					{
						throw InvalidMoveToPiece();
					}
				}
				else
				{
					throw InvalidMoveToPiece();
				}
			}
			else
			{
				throw InvalidMoveToPiece();
			}
		}
		else // color black
		{
			if ((xTo == RightRook || xTo == LeftRook) && yTo == LastRow) // right indexes
			{
				// the rook is at its first position and didn't move yet
				if (boardState[yTo][xTo] && boardState[yTo][xTo]->getSymbol() == 'r' && !boardState[yTo][xTo]->hasMoved())
				{
					if (xTo == RightRook)
					{
						// no pieces blocking on the way
						if (boardState[LastRow][RightKnight] == nullptr && boardState[LastRow][RightBishop] == nullptr)
						{
							boardState[LastRow][RightKnight] = boardState[LastRow][Kingpos];
							boardState[LastRow][RightBishop] = boardState[LastRow][RightRook];
							boardState[LastRow][RightRook] = nullptr;
							boardState[LastRow][Kingpos] = nullptr;
							Player::blackX = RightKnight;
							Player::blackY = LastRow;
							this->setHasMove(true);
							boardState[LastRow][RightBishop]->setHasMove(true);
						}
						else
						{
							throw PieceAtDestPlace();
						}
					}
					else if (xTo == LeftRook)
					{
						// no pieces blocking on the way
						if (boardState[LastRow][LeftKnight] == nullptr && boardState[LastRow][LeftBishop] == nullptr && boardState[LastRow][Queenpos] == nullptr)
						{
							boardState[LastRow][LeftBishop] = boardState[LastRow][Kingpos];
							boardState[LastRow][Queenpos] = boardState[LastRow][LeftRook];
							boardState[LastRow][Kingpos] = nullptr;
							boardState[LastRow][LeftRook] = nullptr;
							Player::blackX = LeftBishop;
							Player::blackY = LastRow;
							this->setHasMove(true);
							boardState[LastRow][Queenpos]->setHasMove(true);
						}
						else
						{
							throw PieceAtDestPlace();
						}
					}
					else
					{
						throw InvalidMoveToPiece();
					}
				}
				else
				{
					throw InvalidMoveToPiece();
				}
			}
		}
		
	}
	else {
		if (!checkMove) {
			throw InvalidIndex();
		}
	}
}


/*
This function updates the (x,y) of the player's king attribute
input: the new x and y, the color of the king
output: none
*/
void King::updateXY(const unsigned newX, const unsigned newY, const unsigned color)
{
	if (color == 0) {
		Player::whiteX = newX;
		Player::whiteY = newY;
	}
	else {
		Player::blackX = newX;
		Player::blackY = newY;
	}
}


/*
This function checks if the move can cause a self check
input: the x,y of the current place, the x,y of the dest place and the board
output: none
*/
void King::checkForSelfCheck(const unsigned x, const unsigned y, const unsigned newX, const unsigned newY, boardMatrix& boardState)
{
	// Update the new x, y
	unsigned color = boardState[y][x]->getColor();
	updateXY(newX, newY, color);
	Piece* self = boardState[y][x];
	boardState[y][x] = nullptr;
	size_t size = boardState.size();

	std::string kingPos = color == 1 ? Piece::createPosition(Player::blackX, Player::blackY) : Piece::createPosition(Player::whiteX, Player::whiteY);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			try {
				if (boardState[i][j]) {
					if (boardState[i][j]->getColor() != color) {
						std::string pos = Piece::createPosition(j, i);
						boardState[i][j]->move(boardState, pos, kingPos, true);
					}
				}
			}
			catch (Check) {
				// Return to the previous x, y if necessary 
				updateXY(x, y, color);
				boardState[y][x] = self;
				throw CausingSelfCheck();
			}
		}
	}
	boardState[y][x] = self;
}
