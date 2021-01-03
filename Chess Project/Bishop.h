#pragma once
#include "Piece.h"

class Bishop : public Piece {
private:
public:
	Bishop(const unsigned color); // constructor
	void move(boardMatrix& boardState, const std::string& from, const std::string& to, const bool checkMove) override; // moves the bishop
	~Bishop() = default; // destructor
};