#include "Rook.h"

void Rook::move(boardMatrix& boardState, string from, string to)
{
	string fixedPosition = Piece::breakPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	unsigned xTo = fixedPosition[0] - '0';
	unsigned yTo = fixedPosition[1] - '0';
	bool flag = true;

	if ((x == xTo && y != yTo) || (x != xTo && y == yTo))
	{
		if (x > xTo)
		{
			for (unsigned i = x; i > xTo; i--)
			{
				if (boardState[yTo][i])
				{
					// TODO: throw an excaption
					flag = false;
				}
			}
		}

		else if (x < xTo)
		{
			for (unsigned i = x; i < xTo; i++)
			{
				if (boardState[yTo][i])
				{
					// TODO: throw an excaption
					std::cout << "blocked!";
					flag = false;
				}
			}
		}

		else if (y < yTo)
		{
			for (unsigned i = y; i > yTo; i--)
			{
				if (boardState[i][xTo])
				{
					// TODO: throw an excaption
					std::cout << "blocked!";
					flag = false;
				}
			}
		}

		else if (y > yTo)
		{
			for (unsigned i = y; i < yTo; i++)
			{
				if (boardState[i][xTo])
				{
					// TODO: throw an excaption
					std::cout << "blocked!";
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
					std::cout << "can't move!";
					// TODO: throw an exaption
				}

				else
				{
					delete boardState[yTo][xTo]; // deleting ("eating") the other piece
					boardState[yTo][xTo] = this; // moving the king
					boardState[y][x] = nullptr; // emptying the old place
				}
			}

			else
			{
				boardState[yTo][xTo] = this; // moving the king
				boardState[y][x] = nullptr; // emptying the old place
			}
		}

	}
}

Rook::Rook(unsigned color) : Piece(color, color == 0 ? 'R' : 'r')
{
}
