#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>


namespace sfgm {
class Location
{
public:
    /*
        TODO
    */
    Location(const char *const name, const LocationPhyciscInfo &physicsInfo = LocationPhyciscInfo());
    ~Location();

    void setFallAcceleration(const float&);
    void setGroundMovementResistanceCoeff(const float&);
    void setAirMovementResistanceCoeff(const float&);

    float getFallAcceleration() const;
    float getGroundMovementResistanceCoeff() const;
    float getAirMovementResistanceCoeff() const;

    LocationPhyciscInfo getPhysicsInfo() const;

private:
    LocationPhyciscInfo physicsInfo;
    const char* name;
    sf::Vector2f playerSpawnPosition;
};

struct LocationPhyciscInfo
{
    float fallAcceleration;
    float groundMovementResistanceCoeff;
    float airMovementResistanceCoeff;

    LocationPhyciscInfo(
        const float fallAcceleration = 9.81,
        const float groundMovementResistanceCoeff = 0.0,
        const float airMovementResistanceCoeff = 0.0
        );

    LocationPhyciscInfo(
        const std::vector<float>&
    );
};
}