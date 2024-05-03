#pragma once

#include <vector>
#include "stdint.h"

#include <SFML/Window/Keyboard.hpp>

#include <iostream>


constexpr uint8_t KEYS_NUMBER{ 105 };
constexpr uint8_t MOUSE_BUTTONS_NUMBER{ 5 };

template<typename Owner_T>
using MethodPtr = void (Owner_T::*)(void);

template<typename Owner_T>
class ControlsManager
{
public:
    ControlsManager(const MethodPtr<Owner_T> dummyMethodPtr);
    ~ControlsManager();

    const MethodPtr<Owner_T> getBinding(const sf::Event&) const;

    void setKeyPressBinding(const sf::Keyboard::Key, const MethodPtr<Owner_T>);
    void setKeyReleaseBinding(const sf::Keyboard::Key, const MethodPtr<Owner_T>);
    void setMouseButtonPressBinding(const sf::Mouse::Button, const MethodPtr<Owner_T>);
    void setMouseButtonReleaseBinding(const sf::Mouse::Button, const MethodPtr<Owner_T>);

private:
    // TODO
    // std::vector<sf::Keyboard::Key, /* combinations */> ;

    std::vector<MethodPtr<Owner_T>> keyPressControls;
    std::vector<MethodPtr<Owner_T>> keyReleaseControls;
    std::vector<MethodPtr<Owner_T>> mouseButtonPressControls;
    std::vector<MethodPtr<Owner_T>> mouseButtonReleaseControls;
    static uint64_t instantiationsCount;
    const uint64_t id;

    const MethodPtr<Owner_T> getKeyBinding(const sf::Event::EventType, const sf::Keyboard::Key) const;
    const MethodPtr<Owner_T> getMouseBinding(const sf::Event::EventType, const sf::Mouse::Button) const;
};
template<typename Owner_T> uint64_t ControlsManager<Owner_T>::instantiationsCount{ 0 };

//============================================================================================================

template<typename Owner_T>
ControlsManager<Owner_T>::ControlsManager(const MethodPtr<Owner_T> dummyMethodPtr) :
    keyPressControls(KEYS_NUMBER, dummyMethodPtr),
    keyReleaseControls(KEYS_NUMBER, dummyMethodPtr),
    mouseButtonPressControls(MOUSE_BUTTONS_NUMBER, dummyMethodPtr),
    mouseButtonReleaseControls(MOUSE_BUTTONS_NUMBER, dummyMethodPtr),
    id(ControlsManager::instantiationsCount++)
{
}

template<typename Owner_T>
ControlsManager<Owner_T>::~ControlsManager()
{
}

template<typename Owner_T>
const MethodPtr<Owner_T> ControlsManager<Owner_T>::getBinding(const sf::Event &event) const
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
        case sf::Event::KeyReleased:
            return this->getKeyBinding(event.type, event.key.code);
        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseButtonReleased:
            return this->getMouseBinding(event.type, event.mouseButton.button);

    }
}

template<typename Owner_T>
const MethodPtr<Owner_T> ControlsManager<Owner_T>::getKeyBinding(const sf::Event::EventType eventType, const sf::Keyboard::Key key) const
{
    switch (eventType)
    {
        case sf::Event::KeyPressed:
            return this->keyPressControls[key];
        case sf::Event::KeyReleased:
            return this->keyReleaseControls[key];
    }
}

template<typename Owner_T>
const MethodPtr<Owner_T> ControlsManager<Owner_T>::getMouseBinding(const sf::Event::EventType eventType, const sf::Mouse::Button btn) const
{
    switch (eventType)
    {
        case sf::Event::MouseButtonPressed:
            return this->mouseButtonPressControls[btn];
        case sf::Event::MouseButtonReleased:
            return this->mouseButtonReleaseControls[btn];
    }
}

template<typename Owner_T>
void ControlsManager<Owner_T>::setKeyPressBinding(const sf::Keyboard::Key key, const MethodPtr<Owner_T> methodPtr)
{
    this->keyPressControls[key] = methodPtr;
}
template<typename Owner_T>
void ControlsManager<Owner_T>::setKeyReleaseBinding(const sf::Keyboard::Key key, const MethodPtr<Owner_T> methodPtr)
{
    this->keyReleaseControls[key] = methodPtr;
}
template<typename Owner_T>
void ControlsManager<Owner_T>::setMouseButtonPressBinding(const sf::Mouse::Button btn, const MethodPtr<Owner_T> methodPtr)
{
    this->mouseButtonPressControls[btn] = methodPtr;
}
template<typename Owner_T>
void ControlsManager<Owner_T>::setMouseButtonReleaseBinding(const sf::Mouse::Button btn, const MethodPtr<Owner_T> methodPtr)
{
    this->mouseButtonReleaseControls[btn] = methodPtr;
}