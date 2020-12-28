#include "Piece.h"

Piece::Piece(unsigned color, char symbol) : symbol(symbol), color(color) {

}


char Piece::getSymbol() const {
	return symbol;
}


string Piece::breakPosition(const string& position) {
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

	int chValue = char((int)position[1] - 1) - '0';
	newPosition[1] = char(7 - chValue + '0');

	return newPosition;
}


string Piece::createPosition(int x, int y) {
	string newPosition = "00";
	switch (x)
	{
	case 0:
		newPosition[0] = 'a';
		break;
	case 1:
		newPosition[0] = 'b';
		break;
	case 2:
		newPosition[0] = 'c';
		break;
	case 3:
		newPosition[0] = 'd';
		break;
	case 4:
		newPosition[0] = 'e';
		break;
	case 5:
		newPosition[0] = 'f';
		break;
	case 6:
		newPosition[0] = 'g';
		break;
	case 7:
		newPosition[0] = 'h';
		break;
	default:
		newPosition[0] =  'q';
		break;
	}

	int chValue = char(y);
	newPosition[1] = char(1 + chValue + '0');

	return newPosition;
}


unsigned Piece::getColor() const
{
	return this->color;
}

