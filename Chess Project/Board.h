#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"
#include "King.h"

typedef std::vector<std::vector<Piece*>> boardMatrix;

class Board
{
private:
	boardMatrix board;

public:
	Board(boardMatrix board);
	Board();
	~Board();
	void init();
	boardMatrix getBoard() const;
	void setBoard(boardMatrix newBoard) const;

	friend std::ostream& operator<<(std::ostream& os, Board& board);
};
