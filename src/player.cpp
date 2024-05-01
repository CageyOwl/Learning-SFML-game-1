#include "player.hpp"


namespace sfgm {
Player::Player() :
    sf::Drawable(),
    shape{ 20.0 },     // TODO
    moveParams(),
    controlsScheme(nullptr)
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

bool Player::attachControlsScheme(ControlsScheme<Player> *const controlsScheme)
{
    /*
        TODO
    */
    if (this->controlsScheme != controlsScheme && controlsScheme != nullptr)
    {
        this->controlsScheme = controlsScheme;
        return true;
    }
    return false;
}

void Player::processCommand(const sf::Keyboard::Key key)
{

}

void Player::dummyMethodPtr()
{
}

void Player::update()
{
    /*
        TODO
    */
    this->moveParams.acceleration.x += (
        0
    );
    this->moveParams.acceleration.y += (
        0
    );

    this->moveParams.speed += this->moveParams.acceleration;

    this->shape.move(this->moveParams.speed);
}
}