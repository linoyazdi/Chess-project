#pragma once
#include "MoveException.h"
#include <iostream>
#include <string>

class NoPieceToMOve : protected MoveException
{
public:
	virtual const char* what() const override
	{
		return "You are trying to move nothing! there is no piece to move\n";
	}
};