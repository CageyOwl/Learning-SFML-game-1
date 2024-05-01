#pragma once


namespace sfgm {
class GameLevel
{
public:
    GameLevel();
    ~GameLevel();

private:
    LevelSettings settings;
    const char* name;
};

struct LevelSettings
{
    float fallAcceleration;
};
}