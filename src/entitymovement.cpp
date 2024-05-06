#include "entitymovement.hpp"


namespace sfgm {
    void Moveable::update()
    {
        this->speed.x += (
            this->accelerationModifier.x * this->acceleration.x
        );
        this->speed.y += (
            this->accelerationModifier.y * this->acceleration.y
        );

        if (this->speed.x > this->movementBasicParameters->maxSpeed.x * this->maxSpeedModifier.x)
        {
            this->speed.x = this->movementBasicParameters->maxSpeed.x * this->maxSpeedModifier.x;
        }
        if (this->speed.y > this->movementBasicParameters->maxSpeed.y * this->maxSpeedModifier.y)
        {
            this->speed.y = this->movementBasicParameters->maxSpeed.y * this->maxSpeedModifier.y;
        }

        this->position += this->speed;
    }

    Moveable::Moveable(
        const sf::Vector2f &position,
        const sf::Vector2f &basicAcceleration = { 0.0, 0.0 },
        const sf::Vector2f &maxSpeed = { 0.0, 0.0 },
        const sf::Vector2f &maxSpeedModifier = { 1.0, 1.0 },
        const sf::Vector2f &accelerationModifier = { 1.0, 1.0 }
        ) :
        position{ position },
        movementBasicParameters{ new MovementBasicParameters{ basicAcceleration, maxSpeed } },
        maxSpeedModifier(maxSpeedModifier),
        accelerationModifier(accelerationModifier)
    {
    }

    Moveable::~Moveable()
    {
        if (this->movementBasicParameters)
            delete movementBasicParameters;
    }

    void Moveable::setPosition(const sf::Vector2f &vector)
    {
        this->position = vector;
    }
    void Moveable::setBasicAcceleration(const sf::Vector2f &vector)
    {
        this->movementBasicParameters->acceleration = vector;
    }
    void Moveable::setAccelerationModifier(const sf::Vector2f &vector)
    {
        this->accelerationModifier = vector;
    }
    void Moveable::setMaxSpeed(const sf::Vector2f &vector)
    {
        this->movementBasicParameters->maxSpeed = vector;
    }
    void Moveable::setMaxSpeedModifier(const sf::Vector2f &vector)
    {
        this->maxSpeedModifier = vector;
    }
    void Moveable::setSpeedModifier(const sf::Vector2f &vector)
    {
        this->speed = vector;
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