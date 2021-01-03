#include "Piece.h"


/*
This function builds a new piece - the constructor
input: the color of the piece, the type of the piece
output: none
*/
Piece::Piece(const unsigned color, const char& symbol) : symbol(symbol), color(color) {
	this->doneFirstMove = false;
}


/*
This function returns the symbol of the piece (according to the type)
input: none
output: the symbol
*/
char Piece::getSymbol() const {
	return symbol;
}


/*
This function converts the position of the piece to the x,y of the position
input: the position of the piece 
output: a string of two numbers
*/
std::string Piece::breakPosition(const std::string& position) {
	std::string newPosition = "00";
	const unsigned maxIndex = 7;
	const char zeroChar = '0';

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

	int chValue = char((int)position[1] - 1) - zeroChar;
	newPosition[1] = char(maxIndex - chValue + zeroChar);

	return newPosition;
}


/*
This function converts the x,y of the piece to a position
input: the x,y of the piece's position
output: a string of the position according to chess
*/
std::string Piece::createPosition(const int x, const int y) {
	std::string newPosition = "00";
	const unsigned maxIndex = 7;
	const char zeroChar = '0';

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
	newPosition[1] = char(7 - chValue + 1 + '0');

	return newPosition;
}


/*
This function returns the color of the piece
input: none
output: the color of the piece
*/
unsigned Piece::getColor() const
{
	return this->color;
}


/*
This function returns if the piece done its first move
input: none
output: true if the piece done its first move otherwise false
*/
bool Piece::hasMoved() const
{
	return this->doneFirstMove;
}


/*
This function sets if the piece done its first move
input: true if the piece done its first move otherwise false
output: none
*/
void Piece::setHasMove(const bool flag)
{
	this->doneFirstMove = flag;
}

