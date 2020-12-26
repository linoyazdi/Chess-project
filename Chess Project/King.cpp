#include "King.h"

King::King(std::string color) : Piece(color, color == "white"? 'K' : 'k'){

}


void King::move(boardMatrix& boardState, string from, string to) {
	string fixedPosition = Piece::braekPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	fixedPosition = Piece::braekPosition(to);
	unsigned xTo = fixedPosition[0] - '0';
	unsigned yTo = fixedPosition[1] - '0';

	if ((y == yTo && (x-1 == xTo || x+1 == xTo)) || (x == xTo && (y-1 == yTo || y+1 == yTo)) || (y+1 == yTo && (x-1 == xTo || x+1 == xTo) || (y - 1 == yTo && (x - 1 == xTo || x + 1 == xTo)))) {
		if (boardState[yTo][xTo]) {
			std::cout << "can't move!";
		}
		else {
			boardState[yTo][xTo] = this;
			boardState[y][x] = nullptr;
		}
	}
}