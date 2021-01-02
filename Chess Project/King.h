#pragma once
#include "Piece.h"
#include "Player.h"

class King : public Piece 
{
private:
public:
	King(unsigned color);
	static void checkForSelfCheck(const unsigned x, const unsigned y, const unsigned newX, const unsigned newY, boardMatrix& boardState);
	static void updateXY(const unsigned newX, const unsigned newY, unsigned color);
	void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	~King() = default;
	
};