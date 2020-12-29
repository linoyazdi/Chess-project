#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	Knight(unsigned color);
	Knight() = default;
};