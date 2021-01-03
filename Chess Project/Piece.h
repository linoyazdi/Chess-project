#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "GameException.h"

class Piece;
typedef std::vector<std::vector<Piece*>> boardMatrix;
using std::string;

class Piece
{
protected:
	char symbol;
	unsigned color;
public:
	virtual char getSymbol() const; // getter
	virtual void move(boardMatrix& boardState, std::string& from, std::string& to, const bool checkMove) = 0; // moves the piece
	Piece(const unsigned color, const char& symbol); // constructor
	static string breakPosition(const string& position); // converts the position to numbers
	static string createPosition(const int x, const int y); // converts the numbers to a position
	virtual ~Piece() = default; // destructor
	unsigned getColor() const; // getter
};

