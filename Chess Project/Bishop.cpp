#include "Bishop.h"


/*
This function builds a new bishop - the constructor
input: the color of the bishop
output: none
*/
Bishop::Bishop(const unsigned color) : Piece(color, color == 0 ? 'B' : 'b')
{

}


/*
This function moves the bishop
input: the board, where the bishop is and where is the dest, and if the function called
to check if the bishop can do check
output: none
*/
void Bishop::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
{
	string fixedPosition = Piece::breakPosition(from);
	int x = fixedPosition[0] - '0';
	int y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	int xTo = fixedPosition[0] - '0';
	int yTo = fixedPosition[1] - '0';

	bool flag = true;

	if (x == xTo && y == yTo && !checkMove) {
		throw SamePlace();
	}

	if (xTo - x == yTo - y || -xTo + x == yTo - y)
	{
		if (x > xTo && y > yTo)
		{
			for (int i = 0; i < x - xTo - 1; i++)
			{
				if (boardState[y-i-1][x-i-1])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		if (x < xTo && y > yTo)
		{
			for (int i = 0; i < xTo - x - 1; i++)
			{
				if (boardState[y - i - 1][x + i + 1])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		if (x < xTo && y < yTo)
		{
			for (int i = 0; i < xTo - x - 1; i++)
			{
				if (boardState[y + i + 1][x + i + 1])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		if (x > xTo && y < yTo)
		{
			for (int i = 0; i < x - xTo - 1; i++)
			{
				if (boardState[y + i + 1][x - i - 1])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		if (flag)
		{
			if (boardState[yTo][xTo])
			{
				if (boardState[yTo][xTo]->getColor() == this->color)
				{
					if (!checkMove) {
						std::cout << "can't move!";
						throw PieceAtDestPlace();
					}
				}

				else
				{
					if (!checkMove)
					{
						delete boardState[yTo][xTo]; // deleting ("eating") the other piece
						boardState[yTo][xTo] = this; // moving the Bishop
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
					boardState[yTo][xTo] = this; // moving the Bishop
					boardState[y][x] = nullptr; // emptying the old place
				}

				else
				{
					throw Check();
				}
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
