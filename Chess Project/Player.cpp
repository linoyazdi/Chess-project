#include "Player.h"


unsigned Player::blackX = 4;
unsigned Player::whiteX = 4;
unsigned Player::blackY = 0;
unsigned Player::whiteY = 7;


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
This function sets the player a new color
input: the new color
output: none
*/
void Player::setColor(const unsigned color)
{
    this->color = color;
}


/*
This function increases the overall score by a certian value
input: the value to add
output: none
*/
void Player::incOverallScore(const unsigned value)
{
    this->overallScore += value;
}


/*
This function builds a new player - the contructor
input: the color of the game
output: none
*/
Player::Player(const unsigned color)
{
    setColor(color);
    this->overallScore = 0;
}


