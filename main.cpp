#include "game.hpp"


int main()
{
    sfgm::Game game;

    while (game.isRunning())
    {
        game.update();
        game.render();
    }

    return 0;
}