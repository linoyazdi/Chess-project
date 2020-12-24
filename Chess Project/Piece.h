#pragma once
#include <iostream>
#include <string>

class Piece
{
protected:
	char symbol;
	std::string color;
public:
	virtual char getSymbol() const;
	Piece(std::string color, char symbol);
	virtual ~Piece() = default;
};