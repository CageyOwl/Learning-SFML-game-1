#pragma once

#include <SFML/Graphics.hpp>
#include "player.hpp"


namespace sfgm {
class Game
{
public:
    Game();
    virtual ~Game();

    bool attachPlayer(Player*);
    const bool isRunning() const;

    void update();
    void render();

private:
    class EventsHandler
    {
    public:
        EventsHandler() = delete;
        EventsHandler(Game *owner);
        void processEvent(const sf::Event &) const;
        
    private:
        Game *owner;

        void keyPress(const sf::Event&) const;
        void keyRelease(const sf::Event&) const;
        void mouseButtonPress(const sf::Event&) const;
        void mouseButtonRelease(const sf::Event&) const;
    } eventsHandler;
    
    sf::Event event;
    sf::RenderWindow *renderWindow;
    Player *player;

    void initWindow();
    void pollEvents();
};
}