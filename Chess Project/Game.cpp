#include "Game.h"

Game::Game() : player1(Player(0)) , player2(Player(1)), turn(true){
	board.init();
}

Game::~Game() {

}
void Game::giveState() {
	std::string players_turn = turn ? "white's turn\n" : "black's turn\n";
	std::cout << players_turn;
	std::cout << board;
}