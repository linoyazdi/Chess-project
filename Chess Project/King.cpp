#include "King.h"

King::King(unsigned color) : Piece(color, color == 0 ? 'K' : 'k'){

}


void King::move(boardMatrix& boardState, string from, string to, bool checkMove)
{
	string fixedPosition = Piece::breakPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	fixedPosition = Piece::breakPosition(to);
	unsigned xTo = fixedPosition[0] - '0';
	unsigned yTo = fixedPosition[1] - '0';

	if ((y == yTo && (x-1 == xTo || x+1 == xTo)) || (x == xTo && (y-1 == yTo || y+1 == yTo)) || (y+1 == yTo && (x-1 == xTo || x+1 == xTo) || (y - 1 == yTo && (x - 1 == xTo || x + 1 == xTo)))) {
		if (boardState[yTo][xTo]) 
		{
			if (boardState[yTo][xTo]->getColor() == this->color) // if player from the same color
			{
				std::cout << "can't move!";
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