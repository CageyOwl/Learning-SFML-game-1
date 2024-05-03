#include "game.hpp"
#include "player.hpp"


int main()
{
    sfgm::Game game;
    sfgm::Player player;
    ControlsManager<sfgm::Player::KeyBindableMethods> ControlsManager(&sfgm::Player::KeyBindableMethods::dummyMethod);

    player.attachControls(&ControlsManager);
    game.attachPlayer(&player);

    while (game.isRunning())
    {
        game.update();
        game.render();
    }

    return 0;
}