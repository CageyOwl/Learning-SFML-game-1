#include "game.hpp"


int main()
{
    sfgm::Game game;
    sfgm::Player player;

    game.attachPlayer(&player);

    while (game.isRunning())
    {
        game.update();
        game.render();
    }

    return 0;
}