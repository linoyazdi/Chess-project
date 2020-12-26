#pragma once
#include "GameException.h"
#include <iostream>
#include <string>

class MoveException : protected GameException
{
public:
	virtual const char* what() const override = 0;
};