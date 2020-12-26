#pragma once
#include "MoveException.h"
#include <iostream>
#include <string>

class CausingSelfCheck : protected MoveException
{
public:
	virtual const char* what() const override
	{
		return "If you'll move that way, you'll cause a self check!\n";
	}
};