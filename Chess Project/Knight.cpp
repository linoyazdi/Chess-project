#include "Knight.h"


/*
This function moves the knight
input: the board, where the knight is and where is the dest, and if the function called
to check if the knight can do check
output: none
*/
void Knight::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
{
	string fixedPosition = Piece::breakPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	unsigned xTo = fixedPosition[0] - '0';
	unsigned yTo = fixedPosition[1] - '0';
	bool flag = true;

	if (x == xTo && y == yTo) {
		throw SamePlace();
	}

	if ((x == xTo - 2 && y == yTo - 1) || (x == xTo - 1 && y == yTo - 2) || (x == xTo + 2 && y == yTo + 1) || (x == xTo + 1 && y == yTo + 2))
	{
		if (boardState[yTo][xTo])
		{
			if (boardState[yTo][xTo]->getColor() == this->color)
			{
				if (!checkMove) 
				{
					std::cout << "can't move!";
					throw PieceAtDestPlace();
				}
			}

			else
			{
				if (!checkMove)
				{
					delete boardState[yTo][xTo]; // deleting ("eating") the other piece
					boardState[yTo][xTo] = this; // moving the king
					boardState[y][x] = nullptr; // emptying the old place
				}

				else
				{
					throw Check();
				}
			}
		}

		else
		{
			if (!checkMove)
			{
				boardState[yTo][xTo] = this; // moving the knight
				boardState[y][x] = nullptr; // emptying the old place
			}

			else
			{
				throw Check();
			}
		}
	}
	else
	{
		if (!checkMove)
		{
			throw InvalidMoveToPiece();
		}
	}
}


/*
This function builds a new knight - the constructor
input: the color of the knight
output: none
*/
Knight::Knight(const unsigned color) : Piece(color, color == 0 ? 'N' : 'n')
{
}
