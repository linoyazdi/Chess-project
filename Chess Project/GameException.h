#pragma once
#include <iostream>
#include <string>
#include <exception>


class GameException : std::exception
{
public:
	virtual const char* what() const = 0;
};


class MoveException : protected GameException
{
public:
	virtual const char* what() const override = 0;
};


class CausingSelfCheck : protected MoveException
{
public:
	virtual const char* what() const override;
};


class NoPieceToMOve : protected MoveException
{
public:
	virtual const char* what() const override;
};


class InvalidMoveToPiece : protected MoveException
{
public:
	virtual const char* what() const override;
};


class SamePlace : protected MoveException
{
public:
	virtual const char* what() const override;
};


class PieceAtDestPlace : protected MoveException
{
public:
	virtual const char* what() const override;
};


class InvalidIndex : protected MoveException
{
public:
	virtual const char* what() const override;
};