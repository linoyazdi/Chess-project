#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	bool doneFirstMove;
public:
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	Pawn(unsigned color);
	Pawn() = default;
};