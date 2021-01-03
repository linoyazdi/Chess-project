/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Game.h"
#include "Pipe.h"
#include <iostream>
#include <thread>
#include <string>


void main()
{
	srand(time_t(NULL));

	Pipe p;
	bool isConnect = p.connect();

	std::string ans;
	Game game;
	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0")
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			game.giveState();
			std::string move = "";
			std::cin >> move;
			std::cout << game.move(move);
			game.giveState();
			std::cin >> move;
			while (move != "exit") {
				std::cout << game.move(move);
				game.giveState();
				std::cin >> move;
			}

			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, game.giveBoardString().c_str()); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	std::string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		std::string move = game.move(msgFromGraphics);
		strcpy_s(msgToGraphics, move.c_str()); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
	//std::cout << "\nleaks: " << _CrtDumpMemoryLeaks();
}
