#include "game.hpp"
#include "player.hpp"


int main()
{
    sfgm::Game game;
    sfgm::Player player;
    ControlsScheme<sfgm::Player> controlsScheme(&sfgm::Player::dummyMethodPtr);

    player.attachControlsScheme(&controlsScheme);
    game.attachPlayer(&player);

    while (game.isRunning())
    {
        game.update();
        game.render();
    }

    return 0;
}