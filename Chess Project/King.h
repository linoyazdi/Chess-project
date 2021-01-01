#pragma once
#include "Piece.h"
#include "Player.h"

class King : public Piece 
{
private:
	void updateXY(const unsigned newX, const unsigned newY);
	void checkForSelfCheck(const unsigned x, const unsigned y, const unsigned newX, const unsigned newY, boardMatrix& boardState);
public:
	King(unsigned color);
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	~King() = default;
	
};