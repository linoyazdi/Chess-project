#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
public:
	void move(boardMatrix& boardState, const std::string& from, const std::string& to, const bool checkMove) override; // moves the pawn
	Pawn(const unsigned color); // constructor
	Pawn() = default; // destructor
};