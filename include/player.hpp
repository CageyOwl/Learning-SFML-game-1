#pragma once

#include <SFML/Graphics.hpp>
#include "entitymovement.hpp"
#include "control.hpp"


namespace sfgm {
class Player : public sf::Drawable
{
public:
    Player(const sf::Vector2f &baseAcceleration = { 0.1, 0.0 });
    virtual ~Player();

    void update();

    struct KeyBindableMethods
    {
        KeyBindableMethods() = delete;
        KeyBindableMethods(Player *const owner);

        void dummyMethod();
        void startAccelerationRight();
        void startAccelerationLeft();
        void stopAccelerationX();

    private:
        Player *owner;

    } keyBindableMethods;
    void processCommand(const sf::Event&);
    
    bool attachControlsScheme(ControlsScheme<Player::KeyBindableMethods> *const);

private:
    sf::CircleShape shape;
    EntityMovementParams moveParams;
    ControlsScheme<Player::KeyBindableMethods> *controlsScheme;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setDefaultControls();

    // Level object pointer?
};
}