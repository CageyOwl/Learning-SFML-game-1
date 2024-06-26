#include "player.hpp"


namespace sfgm {
void Player::update()
{
    /*
        TODO
    */
    this->moveParams.totalAcceleration.x = this->moveParams.acceleration.x /* + other factors */;
    this->moveParams.totalAcceleration.y = this->moveParams.acceleration.y /* + other factors */;

    this->moveParams.speed.x += (
        this->moveParams.totalAcceleration.x /* TODO */ - (abs(this->moveParams.acceleration.x) > 0 ? 0 : 0.1 * this->moveParams.speed.x)
    );
    if (!this->moveParams.acceleration.x && abs(this->moveParams.speed.x) < /* TODO */ 0.001)
        this->moveParams.speed.x = 0;
    this->moveParams.speed.y += (
        this->moveParams.totalAcceleration.y
    );

    this->shape.move(this->moveParams.speed);
}

Player::Player(const sf::Vector2f &baseAcceleration) :
    sf::Drawable(),
    shape{ 20.0 },     // TODO
    moveParams(),
    keyBindableMethods(this),
    controlsManager{ new ControlsManager<sfgm::Player::KeyBindableMethods>(&sfgm::Player::KeyBindableMethods::dummyMethod) }
{
    this->shape.setPosition(40, 40);
    this->setDefaultControls();
    this->moveParams.baseAcceleration = baseAcceleration;
}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->shape, states);
}

bool Player::attachControls(ControlsManager<Player::KeyBindableMethods> *const controlsManager)
{
    /*
        TODO
    */
    if (this->controlsManager != controlsManager && controlsManager)
    {
        this->controlsManager = controlsManager;
        this->setDefaultControls();
        return true;
    }
    return false;
}

void Player::setDefaultControls()
{
    this->controlsManager->setKeyPressBinding(sf::Keyboard::A, &Player::KeyBindableMethods::startAccelerationLeft);
    this->controlsManager->setKeyPressBinding(sf::Keyboard::D, &Player::KeyBindableMethods::startAccelerationRight);
    this->controlsManager->setKeyReleaseBinding(sf::Keyboard::A, &Player::KeyBindableMethods::stopAccelerationX);
    this->controlsManager->setKeyReleaseBinding(sf::Keyboard::D, &Player::KeyBindableMethods::stopAccelerationX);
}

void Player::processCommand(const sf::Event& event)
{
    ((this->keyBindableMethods).*(this->controlsManager->getBinding(event)))();
}

Player::KeyBindableMethods::KeyBindableMethods(Player *const owner)
{
    this->owner = owner;
}
void Player::KeyBindableMethods::dummyMethod()
{
}
void Player::KeyBindableMethods::startAccelerationLeft()
{
    this->owner->moveParams.acceleration.x = -this->owner->moveParams.baseAcceleration.x;
}
void Player::KeyBindableMethods::startAccelerationRight()
{
    this->owner->moveParams.acceleration.x = this->owner->moveParams.baseAcceleration.x;
}
void Player::KeyBindableMethods::stopAccelerationX()
{
    this->owner->moveParams.acceleration.x = 0;
}
}