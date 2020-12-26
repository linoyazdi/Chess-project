#pragma once
#include "Piece.h"

class King : public Piece {
private:
public:
	King(std::string color);
	virtual void move(boardMatrix& boardState, string from, string to);
	~King() = default;
	
};