#include "Board.h"

Board::Board(boardMatrix board)
{
}

Board::Board()
{
}

boardMatrix Board::getBoard() const
{
	return this->board;
}

void Board::setBoard(boardMatrix newBoard) const
{
}

std::ostream& operator<<(std::ostream& os, Board& board)
{
	// TODO: insert return statement here
}
