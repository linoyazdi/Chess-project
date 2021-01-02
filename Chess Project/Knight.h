#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override; // moves the knight
	Knight(const unsigned color); // constructor
	Knight() = default; // destructor
};