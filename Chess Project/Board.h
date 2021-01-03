#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"
#include "Player.h"
#include "King.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"

using boardMatrix = std::vector<std::vector<Piece*>>;

class Board
{
private:
	boardMatrix board;
	static unsigned BOARD_SIZE;

public:
	Board() = default; // regular constructor
	~Board(); // destructor
	void init(); // initializes the board
	boardMatrix getBoard() const; // returns the board
	std::string getString() const; // returns the board as a string
	void move(const std::string& from, const std::string& to, const unsigned turn); // moves a piece on the board
	friend std::ostream& operator<<(std::ostream& os, const Board& board); // adding the board to the os
};
