#include "King.h"


/*
This function builds a new king - the constructor
input: the color of the king
output: none
*/
King::King(unsigned color) : Piece(color, color == 0 ? 'K' : 'k'){

}


/*
This function moves the king
input: the board, where the king is and where is the dest, and if the function called
to check if the king can do check
output: none
*/
void King::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
{
	string fixedPosition = Piece::breakPosition(from);
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

	if (validMove) {
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
