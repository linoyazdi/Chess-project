#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Piece.h"

typedef std::vector<std::vector<Piece>> boardMatrix;

class Board
{
private:
	boardMatrix board;

public:
	Board(boardMatrix board);
	Board();
	~Board() = default;

	boardMatrix getBoard() const;
	void setBoard(boardMatrix newBoard) const;

	friend std::ostream& operator<<(std::ostream& os, Board& board);
};
