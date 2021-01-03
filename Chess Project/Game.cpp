#include "Game.h"


/*
This function builds a new game - the constructor
input: none
output: none
*/
Game::Game() : player1(Player(0)) , player2(Player(1)), turn(0){
	board.init();
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


/*
This function returns the board state
input: none
output: the board state (the board' string, a char that represents the player's turn and the null char) 
*/
std::string Game::giveBoardString() const 
{
	const char nullChar = '\0';
	char turnChar = turn == 0 ? '0' : '1';
	std::string str = board.getString() + turnChar + nullChar;
	return str;
}


/*
This function moves a piece
input: the move
output: a code that represents if the move was valid
*/
std::string Game::move(const std::string& move) {
	std::string from = "00";
	from[0] = move[0];
	from[1] = move[1];
	std::string to = "00";
	to[0] = move[2];
	to[1] = move[3];
	
	
	try {
		board.move(from, to, turn);
	}
	
	catch (Check& err) {
		std::cout << err.what();
		turn = turn == 0 ? 1 : 0;
		return "1\0";
	}

	catch (NoPieceToMove& err) {
		std::cout << err.what();
		return "2\0";
	}

	catch (PieceAtDestPlace& err) {
		std::cout << err.what();
		return "3\0";
	}

	catch (CausingSelfCheck& err) {
		std::cout << err.what();
		return "4\0";
	}

	catch (InvalidIndex& err) {
		std::cout << err.what();
		return "5\0";
	}

	catch (InvalidMoveToPiece& err) {
		std::cout << err.what();
		return "6\0";
	}

	catch (SamePlace& err) {
		std::cout << err.what();
		return "7\0";
	}

	catch (...) {
		std::cout << "unkown exception!!!";
	}
	// TODO: handle excaptions
	turn = turn == 0 ? 1 : 0;
	return "0\0";
}