#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	unsigned color;

public:
	// getter
	unsigned getColor() const;

	// setter
	void setColor(const unsigned color);

	Player(const unsigned color); // constructor
	~Player() = default; // destructor

	static unsigned whiteX;
	static unsigned whiteY;
	static unsigned blackX;
	static unsigned blackY;
};