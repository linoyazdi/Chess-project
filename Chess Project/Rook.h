#pragma once
#include "Piece.h"

using String = std::string;

class Rook : public Piece
{
public:
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	Rook(const unsigned color);
	~Rook() = default;
};