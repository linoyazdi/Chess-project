#pragma once
#include "Piece.h"

using String = std::string;

class Rook : public Piece
{
private:
public:
	void move(boardMatrix& boardState, const std::string& from, const std::string& to, const bool checkMove) override; // moves the rook
	Rook(const unsigned color); // constructor
	~Rook() = default; // destructor
};