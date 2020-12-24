#pragma once
#include "Board.h"
#include "Player.h"

class Game {
private:
	Player player1;
	Player player2;
	bool turn;
	Board board;
public:
	Game();
	~Game();
	void giveState();
};