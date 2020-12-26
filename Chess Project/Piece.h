#pragma once
#include <iostream>
#include <vector>
#include <string>

class Piece;
typedef std::vector<std::vector<Piece*>> boardMatrix;
using std::string;

class Piece
{
protected:
	char symbol;
	unsigned color;
public:
	virtual char getSymbol() const;
	virtual void move(boardMatrix& boardState, string from, string to) = 0;
	Piece(unsigned color, char symbol);
	static string breakPosition(string position);
	virtual ~Piece() = default;
	unsigned getColor() const;
};

