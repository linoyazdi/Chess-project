#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	virtual void move(boardMatrix& boardState, string from, string to) override;
	Rook(unsigned color);
	~Rook() = default;
};