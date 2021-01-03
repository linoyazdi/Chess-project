#pragma once
#include "Piece.h"

class Queen : public Piece {
private:
public:
	Queen(const unsigned color); // constructor
	void move(boardMatrix& boardState, const std::string& from, const std::string& to, const bool checkMove) override; // moves the queen
	~Queen() = default; // destructor
};