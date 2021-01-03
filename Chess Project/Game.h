#pragma once
#include "Board.h"
#include "Player.h"

class Game 
{
private:
	Player player1;
	Player player2;
	unsigned turn;
	Board board;
public:
	Game(); // constructor
	~Game() = default; // destructor
	void giveState(); // returns the state
	std::string giveBoardString() const; // returns the board string
	std::string move(const string& move); // moves a piece
};