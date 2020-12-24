#include "Player.h"


/*
This function returns the color of the player
input: none
output: the color
*/
unsigned Player::getColor() const
{
    return this->color;
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
bool Player::isInCheck() const
{
    return this->inCheck;
}


/*
This function sets the player a new color
input: the new color
output: none
*/
void Player::setColor(unsigned color)
{
    this->color = color;
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
void Player::setIsInCheck(bool flag)
{
    this->inCheck = flag;
}


/*
This function builds a new player - the contructor
input: the color of the game
output: none
*/
Player::Player(unsigned color)
{
    setColor(color);
    this->inCheck = false;
    this->overallScore = 0;
}
