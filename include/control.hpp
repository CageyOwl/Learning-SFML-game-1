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
class ControlsScheme
{
public:
    ControlsScheme(const MethodPtr<Owner_T> dummyMethodPtr);
    ~ControlsScheme();

    const MethodPtr<Owner_T> getBinding(const sf::Event&) const;

    void setKeyPressBinding(const sf::Keyboard::Key, const MethodPtr<Owner_T>);
    void setKeyReleaseBinding(const sf::Keyboard::Key, const MethodPtr<Owner_T>);
    void setMouseButtonPressBinding(const sf::Mouse::Button, const MethodPtr<Owner_T>);
    void setMouseButtonReleaseBinding(const sf::Mouse::Button, const MethodPtr<Owner_T>);

private:
    std::vector<MethodPtr<Owner_T>> keyPressControls;
    std::vector<MethodPtr<Owner_T>> keyReleaseControls;
    std::vector<MethodPtr<Owner_T>> mouseButtonPressControls;
    std::vector<MethodPtr<Owner_T>> mouseButtonReleaseControls;
    static uint64_t instantiationsCount;
    const uint64_t id;

    const MethodPtr<Owner_T> getKeyBinding(const sf::Keyboard::Key, const sf::Event::EventType) const;
    const MethodPtr<Owner_T> getMouseBinding(const sf::Mouse::Button, const sf::Event::EventType) const;
};
template<typename Owner_T> uint64_t ControlsScheme<Owner_T>::instantiationsCount{ 0 };

//============================================================================================================

template<typename Owner_T>
ControlsScheme<Owner_T>::ControlsScheme(const MethodPtr<Owner_T> dummyMethodPtr) :
    keyPressControls(KEYS_NUMBER, dummyMethodPtr),
    keyReleaseControls(KEYS_NUMBER, dummyMethodPtr),
    mouseButtonPressControls(MOUSE_BUTTONS_NUMBER, dummyMethodPtr),
    mouseButtonReleaseControls(MOUSE_BUTTONS_NUMBER, dummyMethodPtr),
    id(ControlsScheme::instantiationsCount++)
{
}

template<typename Owner_T>
ControlsScheme<Owner_T>::~ControlsScheme()
{
}

template<typename Owner_T>
const MethodPtr<Owner_T> ControlsScheme<Owner_T>::getBinding(const sf::Event &event) const
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
        case sf::Event::KeyReleased:
            return this->getKeyBinding(event.key.code, event.type);
        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseButtonReleased:
            return this->getMouseBinding(event.mouseButton.button, event.type);

    }
}

template<typename Owner_T>
const MethodPtr<Owner_T> ControlsScheme<Owner_T>::getKeyBinding(const sf::Keyboard::Key key, const sf::Event::EventType eventType) const
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
const MethodPtr<Owner_T> ControlsScheme<Owner_T>::getMouseBinding(const sf::Mouse::Button btn, const sf::Event::EventType eventType) const
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
void ControlsScheme<Owner_T>::setKeyPressBinding(const sf::Keyboard::Key key, const MethodPtr<Owner_T> methodPtr)
{
    this->keyPressControls[key] = methodPtr;
}
template<typename Owner_T>
void ControlsScheme<Owner_T>::setKeyReleaseBinding(const sf::Keyboard::Key key, const MethodPtr<Owner_T> methodPtr)
{
    this->keyReleaseControls[key] = methodPtr;
}
template<typename Owner_T>
void ControlsScheme<Owner_T>::setMouseButtonPressBinding(const sf::Mouse::Button btn, const MethodPtr<Owner_T> methodPtr)
{
    this->mouseButtonPressControls[btn] = methodPtr;
}
template<typename Owner_T>
void ControlsScheme<Owner_T>::setMouseButtonReleaseBinding(const sf::Mouse::Button btn, const MethodPtr<Owner_T> methodPtr)
{
    this->mouseButtonReleaseControls[btn] = methodPtr;
}