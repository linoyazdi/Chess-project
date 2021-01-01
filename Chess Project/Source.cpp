#include "Game.h"

int main()
{
	Game game;
	string move = "";
	game.giveState();
	std::cin >> move;
	while (move != "exit") {
		std::cout << game.move(move);
		game.giveState();
		std::cin >> move;
	}
	system("pause");
	return 0;
}

/*
TODO
exceptions classes

adding all the piece

handling check - 
1. checking if the next step leads to a check 
2. after there's a check allowing only steps that will defened the king 

*culculating score
*/