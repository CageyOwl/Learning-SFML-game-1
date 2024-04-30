#pragma once

#include <SFML/Graphics.hpp>
#include "entitymovement.hpp"


namespace sfgm {
class Player : public sf::Drawable
{
public:
    Player();
    virtual ~Player();

private:
    sf::CircleShape shape;
    EntityMovementParams moveParams;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
}