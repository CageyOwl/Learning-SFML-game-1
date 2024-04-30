#pragma once

#include <SFML/System/Vector2.hpp>


namespace sfgm {
struct EntityMovementParams
{
    sf::Vector2f speed;
    sf::Vector2f acceleration;

    EntityMovementParams();
};
}