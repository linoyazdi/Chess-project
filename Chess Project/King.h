#pragma once
#include "Piece.h"
#include "Player.h"

class King : public Piece 
{
private:
public:
	King(unsigned color); // constructor
	static void checkForSelfCheck(const unsigned x, const unsigned y, const unsigned newX, const unsigned newY, boardMatrix& boardState); // checking self check
	static void updateXY(const unsigned newX, const unsigned newY, const unsigned color); // updates the x,y of the static var king
	void move(boardMatrix& boardState, const std::string& from, const std::string& to, const bool checkMove) override; // moves the king
	~King() = default; // desctructor
};