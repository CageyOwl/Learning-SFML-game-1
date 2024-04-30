#include "player.hpp"


namespace sfgm {
Player::Player() :
    sf::Drawable(),
    shape{ 20.0 },     // TODO
    moveParams()
{
    this->shape.setPosition(40, 40);
}

Player::~Player()
{    
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->shape, states);
}
}