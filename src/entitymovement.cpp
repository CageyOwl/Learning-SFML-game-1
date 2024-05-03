#include "entitymovement.hpp"


namespace sfgm {
    Moveable::Moveable(const sf::Vector2f &acceleration, const sf::Vector2f &maxSpeed) :
        movementBasicParameters{ new MovementBasicParameters(acceleration, maxSpeed) }
    {

    }

    Moveable::~Moveable()
    {
        if (this->movementBasicParameters)
            delete movementBasicParameters;
    }

    //========================================================================================================================

    MovementBasicParameters::MovementBasicParameters(const sf::Vector2f &acceleration, const sf::Vector2f &maxSpeed) :
        acceleration{ acceleration },
        maxSpeed{ maxSpeed }
    {
    }

    void MovementBasicParameters::setParameters(const sf::Vector2f &acceleration, const sf::Vector2f &maxSpeed)
    {
        this->acceleration = acceleration;
        this->maxSpeed = maxSpeed;
    }
    void MovementBasicParameters::setHorizontalAcceleration(const float value)
    {
        this->acceleration.x = value;
    }
    void MovementBasicParameters::setVerticalAcceleration(const float value)
    {
        this->acceleration.y = value;
    }
    void MovementBasicParameters::setMaxHorizontalSpeed(const float value)
    {
        this->maxSpeed.x = value;
    }
    void MovementBasicParameters::setMaxVerticalSpeed(const float value)
    {
        this->maxSpeed.y = value;
    }
}