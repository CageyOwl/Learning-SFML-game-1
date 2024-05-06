#include "game.hpp"
#include "player.hpp"


int main()
{
    sfgm::Game game;
    sfgm::Player player;
    ControlsManager<sfgm::Player::KeyBindableMethods> controlsManager(&sfgm::Player::KeyBindableMethods::dummyMethod);

    player.attachControls(&controlsManager);
    game.attachPlayer(&player);

    while (game.isRunning())
    {
        game.update();
        game.render();
    }

    return 0;
}