#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	void move(boardMatrix& boardState, const std::string& from, const std::string& to, const bool checkMove) override; // moves the knight
	Knight(const unsigned color); // constructor
	Knight() = default; // destructor
};