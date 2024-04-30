#pragma once

#include "entitymovement.hpp"


namespace sfgm {
class Player
{
public:
    Player();
    virtual ~Player();

private:
    EntityMovementParams moveParams;

};
}