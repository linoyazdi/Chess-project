#include "Board.h"
#define BOARD_SIZE 8
Board::Board(boardMatrix board)
{
}

Board::Board()
{
}

Board::~Board() {
	for (unsigned i = 0; i < BOARD_SIZE; i++) {
		for (unsigned j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j]) {
				delete board[i][j];
				board[i][j] = nullptr;
			}
		}
	}
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
	for (unsigned i = 0; i < board.getBoard().size(); i++) {
		for (unsigned j = 0; j < board.getBoard()[0].size(); j++) {
			Piece* piece = board.getBoard()[i][j];
			if (piece) {
				os << piece->getSymbol() << " ";
			}
			else {
				os << "_" << " ";
			}
			
		}
		os << std::endl;
	}
	return os;
}

void Board::init() {
	for (unsigned i = 0; i < BOARD_SIZE; i++) {
		board.push_back(std::vector<Piece*>());
		for (unsigned j = 0; j < BOARD_SIZE; j++) {
			board.back().push_back(nullptr);
			//std::cout << "Added a piece";
		}
	}
	board[3][0] = new King("white");
}

std::string Board::getString() const {
	std::string str = "";
	for (unsigned i = 0; i < BOARD_SIZE; i++) {
		for (unsigned j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j]) {
				str += board[i][j]->getSymbol();
			}
			else {
				str += '#';
			}
		}
	}
	return str;
}

void Board::move(std::string from, std::string to) {
	string  fixedPosition = Piece::braekPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	if (board[y][x]) {
		board[y][x]->move(board, from, to);
	}
}