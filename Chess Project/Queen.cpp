#include "Queen.h"


/*
This function builds a new queen - the constructor
input: the color of the queen
output: none
*/
Queen::Queen(const unsigned color) : Piece (color, color == 0 ? 'Q' : 'q')
{
}


/*
This function moves the queen
input: the board, where the queen is and where is the dest, and if the function called
to check if the queen can do check
output: none
*/
void Queen::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
{
	std::string fixedPosition = Piece::breakPosition(from);
	int x = fixedPosition[0] - '0';
	int y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	int xTo = fixedPosition[0] - '0';
	int yTo = fixedPosition[1] - '0';
	bool flag = true;

	if (x == xTo && y == yTo && !checkMove) {
		throw SamePlace();
	}


	if ((x == xTo && y != yTo) || (x != xTo && y == yTo) || xTo - x == yTo - y || -xTo + x == yTo - y)
	{
		if (x > xTo && y == yTo)
		{
			for (int i = x - 1; i > xTo; i--)
			{
				if (boardState[yTo][i])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		else if (x < xTo && y == yTo)
		{
			for (int i = x + 1; i < xTo; i++)
			{
				if (boardState[yTo][i])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		else if (y < yTo && x == xTo)
		{
			for (int i = y+1; i < yTo; i++)
			{
				if (boardState[i][xTo])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		else if (y > yTo && x == xTo)
		{
			for (int i = y-1; i > yTo; i--)
			{
				if (boardState[i][xTo])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
					}
					flag = false;
				}
			}
		}

		if (x > xTo&& y > yTo)
		{
			for (int i = 0; i < x - xTo - 1; i++)
			{
				if (boardState[y - i - 1][x - i - 1])
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

		if (x > xTo&& y < yTo)
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
					boardState[yTo][xTo] = this; // moving the king
					boardState[y][x] = nullptr; // emptying the old place
				}

				else
				{
					throw Check();
				}
			}
		}
	}
}
