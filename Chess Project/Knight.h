#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	virtual void move(boardMatrix& boardState, string from, string to, bool checkMove) override;
	Knight(unsigned color);
	Knight() = default;
};