#include "Piece.h"

Piece::Piece(std::string color, char symbol) : symbol(symbol), color(color) {

}

char Piece::getSymbol() const {
	return symbol;
}

string Piece::braekPosition(string position) {
	string newPosition = "00";
	switch (position[0])
	{
	case 'a':
		newPosition[0] = '0';
		break;
	case 'b':
		newPosition[0] = '1';
		break;
	case 'c':
		newPosition[0] = '2';
		break;
	case 'd':
		newPosition[0] = '3';
		break;
	case 'e':
		newPosition[0] = '4';
		break;
	case 'f':
		newPosition[0] = '5';
		break;
	case 'g':
		newPosition[0] = '6';
		break;
	case 'h':
		newPosition[0] = '7';
		break;
	default:
		newPosition[0] = position[0] - 1;
		break;
	}

	newPosition[1] = char((int)position[1] - 1);

	return newPosition;
}