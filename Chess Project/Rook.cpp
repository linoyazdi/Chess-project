#include "Rook.h"


/*
This function moves the rook
input: the board, where the rook is and where is the dest, and if the function called
to check if the rook can do check
output: none
*/
void Rook::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
{
	std::string fixedPosition = Piece::breakPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	unsigned xTo = fixedPosition[0] - '0';
	unsigned yTo = fixedPosition[1] - '0';
	bool flag = true;

	if (x == xTo && y == yTo && !checkMove) {
		throw SamePlace();
	}


	if ((x == xTo && y != yTo) || (x != xTo && y == yTo))
	{
		if (x > xTo)
		{
			for (unsigned i = x-1; i > xTo; i--)
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

		else if (x < xTo)
		{
			for (unsigned i = x+1; i < xTo; i++)
			{
				if (boardState[yTo][i])
				{
					if (!checkMove) {
						throw PieceAtDestPlace();
						std::cout << "blocked!";
					}
					flag = false;
				}
			}
		}

		else if (y < yTo)
		{
			for (unsigned i = y + 1; i < yTo; i++)
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

		else if (y > yTo)
		{
			for (unsigned i = y - 1; i > yTo; i--)
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
					boardState[yTo][xTo] = this; // moving the rook
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


/*
This function builds a new rook - the constructor
input: the color of the rook
output: none
*/
Rook::Rook(unsigned color) : Piece(color, color == 0 ? 'R' : 'r')
{
}
