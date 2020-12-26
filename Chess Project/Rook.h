#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	virtual void move(boardMatrix& boardState, string from, string to);
	Rook(unsigned color);
	~Rook() = default;
};