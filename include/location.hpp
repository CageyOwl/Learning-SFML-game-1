#pragma once


namespace sfgm {
class Location
{
public:
    Location(const char *const name);
    ~Location();

private:
    LocationPhyciscInfo physicsInfo;
    const char* name;
};

struct LocationPhyciscInfo
{
    float fallAcceleration;
};
}