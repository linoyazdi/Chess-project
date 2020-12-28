#include "Game.h"

Game::Game() : player1(Player(0)) , player2(Player(1)), turn(0){
	board.init();
}

Game::~Game() {

}

/*
the function prints the board state
input: none
output: none
*/
void Game::giveState()
{
	std::string players_turn = turn == 0 ? "white's turn\n" : "black's turn\n";
	std::cout << players_turn;
	std::cout << board << std::endl;
}

std::string Game::giveBoardString() const {
	char turn_char = turn ? '0' : '1';
	std::string str = board.getString() + turn_char + '0';
	return str;
}

int Game::move(string move) {
	string from = "00";
	from[0] = move[0];
	from[1] = move[1];
	string to = "00";
	to[0] = move[3];
	to[1] = move[4];
	try {
		board.move(from, to, turn);
	}
	catch (NoPieceToMove) {
		return 2;
	}
	catch (PieceAtDestPlace) {
		return 3;
	}
	catch (CausingSelfCheck) {
		return 4;
	}
	catch (InvalidIndex) {
		return 5;
	}
	catch (InvalidMoveToPiece) {
		return 6;
	}
	catch (SamePlace) {
		return 7;
	}
	// TODO: handle excaptions
	turn = turn == 0 ? 1 : 0;
	return 0;
}