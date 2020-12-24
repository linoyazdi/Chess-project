#include "Player.h"


/*
This function returns the color of the player
input: none
output: the color
*/
std::string Player::getColor() const
{
    return this->color;
}


/*
This function returns how many dead pieces the player has
input: none
otuput: the number of dead players
*/
unsigned Player::getDeadPieces() const
{
    return this->deadPieces;
}


/*
This function returns the score of the player
input: none
output: the overall score
*/
unsigned Player::getOverallScore() const
{
    return this->overallScore;
}


/*
This function returns if the player is on check
input: none
output: true if the player is on check, otherwise false
*/
bool Player::isOnCheck() const
{
    return this->onCheck;
}


/*
This function sets the player a new color
input: the new color
output: none
*/
void Player::setColor(std::string color)
{
    this->color = color;
}


/*
This function increases the dead players by 1
input: none
output: none
*/
void Player::incDeadPieces()
{
    this->deadPieces++;
}


/*
This function increases the overall score by a certian value
input: the value to add
output: none
*/
void Player::incOverallScore(unsigned value)
{
    this->overallScore += value;
}


/*
This function sets if the player is on check
input: a bool flag that represents if the player is on check
output: none
*/
void Player::setIsOnCheck(bool flag)
{
    this->onCheck = flag;
}


/*
This function builds a new player - the contructor
input: the color of the game
output: none
*/
Player::Player(std::string color)
{
    this->color = color;
    this->deadPieces = 0;
    this->onCheck = false;
    this->overallScore = 0;
}
