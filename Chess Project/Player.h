#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	unsigned color;
	unsigned overallScore;

public:
	// getters
	unsigned getColor() const;
	unsigned getOverallScore() const;

	// setters
	void setColor(const unsigned color);
	void incOverallScore(const unsigned value);

	Player(const unsigned color); // constructor
	~Player() = default; // destructor

	static unsigned whiteX;
	static unsigned whiteY;
	static unsigned blackX;
	static unsigned blackY;
};