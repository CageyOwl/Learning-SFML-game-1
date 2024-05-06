#pragma once

#include <SFML/System/Vector2.hpp>
#include "location.hpp"


namespace sfgm {
class Moveable
{
public:
    Moveable(
        const sf::Vector2f &position,
        const sf::Vector2f &basicAcceleration = { 0.0, 0.0 },
        const sf::Vector2f &accelerationModifier = { 1.0, 1.0 },
        const sf::Vector2f &maxSpeed = { 0.0, 0.0 },
        const sf::Vector2f &maxSpeedModifier = { 1.0, 1.0 }
        );
    virtual ~Moveable();

    virtual void update();

    void setPosition(const sf::Vector2f&);
    void setBasicAcceleration(const sf::Vector2f&);
    void setAccelerationModifier(const sf::Vector2f&);
    void setMaxSpeed(const sf::Vector2f&);
    void setMaxSpeedModifier(const sf::Vector2f&);
    void setSpeedModifier(const sf::Vector2f&);

    void setLocationParameters(const LocationPhyciscInfo&);
    void setLocationParameters(const Location&);

protected:
    MovementBasicParameters *movementBasicParameters;
    sf::Vector2f position;
    sf::Vector2f acceleration, accelerationModifier;
    sf::Vector2f speed, maxSpeedModifier;

    LocationPhyciscInfo *locationPhyciscInfo;
};

struct MovementBasicParameters
{
    MovementBasicParameters(const sf::Vector2f &basicAcceleration  = { 0.0, 0.0 }, const sf::Vector2f &maxSpeed = { 0.0, 0.0 });

    sf::Vector2f acceleration;
    sf::Vector2f maxSpeed;

    void setParameters(const sf::Vector2f &acceleration, const sf::Vector2f &maxSpeed);
    void setHorizontalAcceleration(const float);
    void setVerticalAcceleration(const float);
    void setMaxHorizontalSpeed(const float);
    void setMaxVerticalSpeed(const float);
};
}