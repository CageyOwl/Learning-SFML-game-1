#include "game.hpp"


namespace sfgm {
void Game::update()
{
    this->pollEvents();
    // Other updates
    this->player->update();
}

void Game::render()
{
    this->renderWindow->clear();
    // Draws start
    this->renderWindow->draw(*(this->player));     // TODO
    // Draws end
    this->renderWindow->display();
}

//======================================================================================================= Game class

Game::Game() :
    eventsHandler(this),
    event(),
    player()
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

bool Game::attachPlayer(sfgm::Player *player)
{
    this->player = player;
    if (this->player)
        return true;
    return false;
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
            this->keyPress(event);
            break;
        case sf::Event::KeyReleased:
            this->keyRelease(event);
            break;
        case sf::Event::MouseButtonPressed:
            this->mouseButtonPress(event);
            break;
        case sf::Event::MouseButtonReleased:
            this->mouseButtonRelease(event);
            break;
        case sf::Event::Closed:
            this->owner->renderWindow->close();
            break;
    }
}

void Game::EventsHandler::keyPress(const sf::Event &event) const
{
    switch (event.key.code)
    {
    case sf::Keyboard::Escape:
        this->owner->renderWindow->close();
        break;
    case sf::Keyboard::P:
        this->owner->renderWindow->setActive(false);
        break;
    default:
        this->owner->player->processCommand(event);
    }
}

void Game::EventsHandler::keyRelease(const sf::Event &event) const
{
    switch (event.key.code)
    {
        /*
            TODO
        */
    default:
        this->owner->player->processCommand(event);
    }
}

void Game::EventsHandler::mouseButtonPress(const sf::Event &event) const
{

}

void Game::EventsHandler::mouseButtonRelease(const sf::Event &event) const
{

}
}