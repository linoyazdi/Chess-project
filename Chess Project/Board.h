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
	static unsigned BOARD_SIZE;

public:
	Board(boardMatrix board);
	Board();
	~Board();
	void init();
	boardMatrix getBoard() const;
	void setBoard(boardMatrix newBoard) const;
	std::string getString() const;
	void move(std::string from, std::string to, unsigned turn);
	friend std::ostream& operator<<(std::ostream& os, Board& board);
};
