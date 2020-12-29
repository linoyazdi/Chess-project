#pragma once
#include "Piece.h"

class Bishop : public Piece {
private:
public:
	Bishop(const unsigned color);
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	~Bishop() = default;
};