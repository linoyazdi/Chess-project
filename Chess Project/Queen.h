#pragma once
#include "Piece.h"

class Queen : public Piece {
private:
public:
	Queen(const unsigned color);
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	~Queen() = default;
};