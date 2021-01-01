#include "Pawn.h"

void Pawn::move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove)
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

	if (this->doneFirstMove)
	{
		if ((y == yTo + 1 && this->color == 0 && x == xTo) || (y == yTo - 1 && this->color == 1 && x == xTo))
		{
			if (boardState[yTo][xTo])
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
					boardState[yTo][xTo] = this; // moving the knight
					boardState[y][x] = nullptr; // emptying the old place
				}

				else
				{
					throw Check();
				}
			}
		}
		else if ((x == xTo + 1 && y == yTo + 1 && this->color == 0) || (x == xTo + 1 && y == yTo - 1 && this->color == 0) || (x == xTo - 1 && y == yTo + 1 && this->color == 1) || (x == xTo + 1 && y == yTo + 1 && this->color == 1))
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
						if (!checkMove)
						{
							throw Check();
						}
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
	else
	{
		this->doneFirstMove = true;
		if ((y == yTo + 1 && this->color == 0 && x == xTo) || (y == yTo - 1 && this->color == 1 && x == xTo) || (y == yTo + 2 && this->color == 0 && x == xTo) || (y == yTo - 2 && this->color == 1 && x == xTo))
		{
			if (boardState[yTo][xTo])
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
					boardState[yTo][xTo] = this; // moving the knight
					boardState[y][x] = nullptr; // emptying the old place
				}

				else
				{
					throw Check();
				}
			}
		}
		else if ((x == xTo + 1 && y == yTo + 1 && this->color == 0) || (x == xTo - 1 && y == yTo + 1 && this->color == 0) || (x == xTo - 1 && y == yTo - 1 && this->color == 1) || (x == xTo + 1 && y == yTo - 1 && this->color == 1))
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
		}
		
		else
		{
			if (!checkMove)
			{
				throw InvalidMoveToPiece();
			}
		}
	}
}

Pawn::Pawn(unsigned color) : Piece(color, color == 0 ? 'P' : 'p')
{
	this->doneFirstMove = false;
}