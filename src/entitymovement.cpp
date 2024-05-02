#include "entitymovement.hpp"

namespace sfgm {
    EntityMovementParams::EntityMovementParams() :
        baseAcceleration{ 0.0, 0.0 },
        totalAcceleration{ 0.0, 0.0 },
        acceleration{ 0.0, 0.0 },
        speed{ 0.0, 0.0 },
        maxSpeed{ 0.0, 0.0 }
    {
    }
}