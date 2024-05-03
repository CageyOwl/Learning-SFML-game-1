#pragma once

#include <SFML/System/Vector2.hpp>


namespace sfgm {
class Moveable
{
public:
    Moveable(const sf::Vector2f &acceleration = { 0.0, 0.0 }, const sf::Vector2f &maxSpeed = { 0.0, 0.0 });
    virtual ~Moveable();

    void update();

protected:
    MovementBasicParameters *movementBasicParameters;
    sf::Vector2f acceleration, speed;
};

struct MovementBasicParameters
{
    MovementBasicParameters(const sf::Vector2f &acceleration  = { 0.0, 0.0 }, const sf::Vector2f &maxSpeed = { 0.0, 0.0 });
    void setParameters(const sf::Vector2f &acceleration, const sf::Vector2f &maxSpeed);
    void setHorizontalAcceleration(const float);
    void setVerticalAcceleration(const float);
    void setMaxHorizontalSpeed(const float);
    void setMaxVerticalSpeed(const float);

    sf::Vector2f acceleration;
    sf::Vector2f maxSpeed;
};
}