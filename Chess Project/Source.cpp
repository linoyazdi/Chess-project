#include "Game.h"

int main()
{
	Game game;
	game.giveState();
	string move = "";
	std::cin >> move;
	game.move(move);
	game.giveState();
	system("pause");
	return 0;
}