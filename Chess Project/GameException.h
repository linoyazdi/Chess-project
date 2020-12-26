#pragma once
#include <iostream>
#include <string>

class GameException
{
public:
	virtual const char* what() const = 0;
};