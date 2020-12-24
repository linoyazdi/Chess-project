#include "Piece.h"

Piece::Piece(std::string color, char symbol) : symbol(symbol), color(color) {

}

char Piece::getSymbol() const {
	return symbol;
}