#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	unsigned color;
	unsigned overallScore;
	bool inCheck;

public:
	// getters
	unsigned getColor() const;
	unsigned getOverallScore() const;
	bool isInCheck() const;

	// setters
	void setColor(unsigned color);
	void incOverallScore(unsigned value);
	void setIsInCheck(bool flag);

	Player(unsigned color);
	~Player() = default;
};