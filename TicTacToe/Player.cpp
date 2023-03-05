#include "Player.h"

void Player::won()
{
    //increment the score
    score++;
}

int Player::getScore()
{
    return this->score; 
}

std::string Player::getName()
{
    return this->name;
}
