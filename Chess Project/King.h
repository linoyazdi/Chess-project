#pragma once
#include "Piece.h"

class King : public Piece 
{
private:
public:
	King(unsigned color);
	virtual void move(boardMatrix& boardState, string from, string to) override;
	~King() = default;
	
};