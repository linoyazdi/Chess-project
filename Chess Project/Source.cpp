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

/*
TODO
exceptions classes

adding all the pieces -
1. valid move
2. not out of range
3. eating other piece
4. not getting block

handling check - 
1. checking if the next step leads to a check 
2. after there's a check allowing only steps that will defened the king 

*culculating score
*/