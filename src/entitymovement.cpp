#include "entitymovement.hpp"

namespace sfgm {
    EntityMovementParams::EntityMovementParams() :
        speed{ 0.0, 0.0 },
        acceleration{ 0.0, 0.0 },
        maxSpeed{ 0.0 },
        baseAcceleration{ 0.0 }
    {
    }
}