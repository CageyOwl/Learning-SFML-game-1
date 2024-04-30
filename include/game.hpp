#pragma once

#include <SFML/Graphics.hpp>


namespace sfgm {
class Game
{
public:
    Game();
    virtual ~Game();

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

        void keyPress(const sf::Keyboard::Key) const;
        void keyRelease(const sf::Keyboard::Key) const;
        void mouseButtonPress(const sf::Mouse::Button) const;
        void mouseButtonRelease(const sf::Mouse::Button) const;
    } eventsHandler;
    
    sf::Event event;
    sf::RenderWindow *renderWindow;

    void initWindow();
    void pollEvents();
};
}