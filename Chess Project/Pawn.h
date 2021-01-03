#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
public:
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override; // moves the pawn
	Pawn(const unsigned color); // constructor
	Pawn() = default; // destructor
};