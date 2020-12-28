#include "Rook.h"

void Rook::move(boardMatrix& boardState, string from, string to, bool checkMove)
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


	if ((x == xTo && y != yTo) || (x != xTo && y == yTo))
	{
		if (x > xTo)
		{
			for (unsigned i = x; i > xTo; i--)
			{
				if (boardState[yTo][i])
				{
					throw PieceAtDestPlace();
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
					throw PieceAtDestPlace();
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
					throw PieceAtDestPlace();
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
					throw PieceAtDestPlace();
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
					throw PieceAtDestPlace();
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

Rook::Rook(unsigned color) : Piece(color, color == 0 ? 'R' : 'r')
{
}
