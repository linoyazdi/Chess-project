#pragma once
#include "Piece.h"

class King : public Piece 
{
private:
public:
	King(unsigned color);
	virtual void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) override;
	~King() = default;
	
};