#include "location.hpp"


namespace sfgm {
LocationPhyciscInfo::LocationPhyciscInfo(
    const float fallAcceleration = 9.81,
    const float groundMovementResistanceCoeff = 0.0,
    const float airMovementResistanceCoeff = 0.0
    ) :
    fallAcceleration(fallAcceleration),
    groundMovementResistanceCoeff(groundMovementResistanceCoeff),
    airMovementResistanceCoeff(airMovementResistanceCoeff)
{
}

LocationPhyciscInfo::LocationPhyciscInfo(
    const std::vector<float> &physicsInfo
    ) :
    fallAcceleration(physicsInfo[0]),
    groundMovementResistanceCoeff(physicsInfo[1]),
    airMovementResistanceCoeff(physicsInfo[2])
{
}

Location::Location(const char *const name, const LocationPhyciscInfo &physicsInfo = LocationPhyciscInfo()) :
    name(name),
    physicsInfo(physicsInfo)
{
}

void Location::setFallAcceleration(const float &fallAcceleration)
{
    this->physicsInfo.fallAcceleration = fallAcceleration;
}
void Location::setGroundMovementResistanceCoeff(const float &coefficient)
{
    this->physicsInfo.groundMovementResistanceCoeff = coefficient;
}
void Location::setAirMovementResistanceCoeff(const float &coefficient)
{
    this->physicsInfo.airMovementResistanceCoeff = coefficient;
}

LocationPhyciscInfo Location::getPhysicsInfo() const
{
    return this->physicsInfo;
}
}