#include "Board.h"

unsigned Board::BOARD_SIZE = 8;

Board::Board(boardMatrix board)
{
}

Board::Board()
{
}

Board::~Board() 
{
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

void Board::init() 
{
	for (unsigned i = 0; i < BOARD_SIZE; i++) {
		board.push_back(std::vector<Piece*>());
		for (unsigned j = 0; j < BOARD_SIZE; j++) {
			board.back().push_back(nullptr);
			//std::cout << "Added a piece";
		}
	}
	board[3][0] = new King(0);
	board[5][0] = new King(1);
	board[7][7] = new Rook(0);
}

std::string Board::getString() const 
{
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

void Board::move(std::string from, std::string to, unsigned turn) 
{
	string fixedPosition = Piece::breakPosition(from);
	unsigned x = fixedPosition[0] - '0';
	unsigned y = fixedPosition[1] - '0';
	string positionTo = Piece::breakPosition(to);
	unsigned xTo = positionTo[0] - '0';
	unsigned yTo = positionTo[1] - '0';

	size_t size = board.size();
	
	//checking good from index
	if (x < 0 || x >= size || y < 0 || y >= size) {
		throw InvalidIndex();
	}

	//checking good to index
	if (xTo < 0 || xTo >= size || yTo < 0 || yTo >= size) {
		throw InvalidIndex();
	}

	//checking if there's a piece in the location
	if (board[y][x]) 
	{
		//checking if the piece is of the same color as the active player
		if (board[y][x]->getColor() == turn)
		{
			board[y][x]->move(board, from, to, false);

			//getting the new location in x, y
			string fixed = Piece::breakPosition(to);
			unsigned newX = fixed[0] - '0';
			unsigned newY = fixed[1] - '0';
			String kingPos = turn == 0 ? Piece::createPosition(Player::blackX, Player::blackY) : Piece::createPosition(Player::whiteX, Player::whiteY);

			board[newY][newX]->move(board, to, kingPos, true);
		}
		else
		{
			throw NoPieceToMove();
		}
	}

	else
	{
		throw NoPieceToMove();
	}
}