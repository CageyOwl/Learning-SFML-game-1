#pragma once

#include <SFML/System/Vector2.hpp>


namespace sfgm {
struct EntityMovementParams
{
    sf::Vector2f baseAcceleration;
    sf::Vector2f totalAcceleration, acceleration;
    
    sf::Vector2f speed, maxSpeed;

    EntityMovementParams();
};
}