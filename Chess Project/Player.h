#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string color;
	unsigned deadPieces;
	unsigned overallScore;
	bool onCheck;

public:
	// getters
	std::string getColor() const;
	unsigned getDeadPieces() const;
	unsigned getOverallScore() const;
	bool isOnCheck() const;

	// setters
	void setColor(std::string color);
	void incDeadPieces();
	void incOverallScore(unsigned value);
	void setIsOnCheck(bool flag);

	Player(std::string color);
	~Player() = default;
};