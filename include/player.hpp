#pragma once

#include <SFML/Graphics.hpp>
#include "entitymovement.hpp"
#include "control.hpp"


namespace sfgm {
class Player : public sf::Drawable
{
public:
    Player();
    virtual ~Player();

    bool attachControlsScheme(ControlsScheme<Player> *const);
    void processCommand(const sf::Keyboard::Key);
    void dummyMethodPtr();

    void update();

private:
    struct BindingMethods
    {

    } bindingMethods;   // Methods container
    sf::CircleShape shape;
    EntityMovementParams moveParams;
    ControlsScheme<Player> *controlsScheme;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setDefaultControls();

    // Level object pointer?
};
}