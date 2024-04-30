#include "game.hpp"
#include <iostream> // tmp


namespace sfgm {
void Game::update()
{
    this->pollEvents();
    // Other updates

}

void Game::render()
{
    this->renderWindow->clear();
    // Draws start

    // Draws end
    this->renderWindow->display();
}

//======================================================================================================= Game class

Game::Game() :
    eventsHandler(this),
    event()
{
    this->initWindow();
}

Game::~Game()
{
    if (this->renderWindow)
        delete this->renderWindow;
}

void Game::initWindow()
{
    /*
        TODO:
            - render window parameters definition;
    */
    sf::VideoMode videoMode{ 1200, 800 };
    this->renderWindow = new sf::RenderWindow(videoMode, "SFML game", sf::Style::Close);
    this->renderWindow->setFramerateLimit(60);
}

const bool Game::isRunning() const
{
    return this->renderWindow->isOpen();
}

void Game::pollEvents()
{
    while (this->renderWindow->pollEvent(this->event))
    {
        this->eventsHandler.processEvent(this->event);
    }
}

//======================================================================================================= Events handling

Game::EventsHandler::EventsHandler(Game *owner) :
    owner(owner)
{
}

void Game::EventsHandler::processEvent(const sf::Event & event) const
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            this->keyPress(event.key.code);
            break;
        case sf::Event::KeyReleased:
            this->keyRelease(event.key.code);
            break;
        case sf::Event::MouseButtonPressed:
            this->mouseButtonPress(event.mouseButton.button);
            break;
        case sf::Event::MouseButtonReleased:
            this->mouseButtonRelease(event.mouseButton.button);
            break;
        case sf::Event::Closed:
            this->owner->renderWindow->close();
            break;
    }
}

void Game::EventsHandler::keyPress(sf::Keyboard::Key key) const
{
    std::cout << "The key " << key << " is pressed\n";
}

void Game::EventsHandler::keyRelease(sf::Keyboard::Key key) const
{
    std::cout << "The key " << key << " is released\n";
}

void Game::EventsHandler::mouseButtonPress(const sf::Mouse::Button btn) const
{
    std::cout << "The mouse button " << btn << " is pressed\n";
}

void Game::EventsHandler::mouseButtonRelease(const sf::Mouse::Button btn) const
{
    std::cout << "The mouse button " << btn << " is released\n";
}
}