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
This function sets the player a new color
input: the new color
output: none
*/
void Player::setColor(const unsigned color)
{
    this->color = color;
}


/*
This function builds a new player - the contructor
input: the color of the game
output: none
*/
Player::Player(const unsigned color)
{
    setColor(color);
}


