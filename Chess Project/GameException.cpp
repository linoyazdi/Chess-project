#include "GameException.h"

const char* CausingSelfCheck::what() const
{
	return "If you'll move that way, you'll cause a self check!\n";
}

const char* NoPieceToMOve::what() const
{
	return "You are trying to move nothing! there is no piece to move\n";
}

const char* InvalidMoveToPiece::what() const
{
	return "That's an inalid move to this piece!\n";
}

const char* SamePlace::what() const
{
	return "The source place and the destination place are the same place\nYou are not moving the piece!\n";
}

const char* PieceAtDestPlace::what() const
{
	return "There is a piece that is blocking you on your way to the destination place!\n";
}

const char* InvalidIndex::what() const
{
	return "This is an invalid index!\n";
}
