#pragma once

#include <vector>
#include "stdint.h"

#include <SFML/Window/Keyboard.hpp>


constexpr uint8_t KEYS_NUMBER{ 105 };

template<typename Owner_T>
using MethodPtr = void (Owner_T::*)(void);

template<typename Owner_T>
class ControlsScheme
{
public:
    ControlsScheme(const MethodPtr<Owner_T> dummyMethodPtr);
    ~ControlsScheme();

    void setKeyBinding(const sf::Keyboard::Key, const MethodPtr<Owner_T>);
    const MethodPtr<Owner_T> getKeyBinding(const sf::Keyboard::Key) const;

private:
    std::vector<MethodPtr<Owner_T>> controls;
    static uint64_t instantiationsCount;
    const uint64_t id;
};
template<typename Owner_T> uint64_t ControlsScheme<Owner_T>::instantiationsCount{ 0 };

//============================================================================================================

template<typename Owner_T>
ControlsScheme<Owner_T>::ControlsScheme(const MethodPtr<Owner_T> dummyMethodPtr) :
    controls(KEYS_NUMBER, dummyMethodPtr),
    id(ControlsScheme::instantiationsCount++)
{
}

template<typename Owner_T>
ControlsScheme<Owner_T>::~ControlsScheme()
{
}

template<typename Owner_T>
void ControlsScheme<Owner_T>::setKeyBinding(const sf::Keyboard::Key key, const MethodPtr<Owner_T> MethodPtr)
{
    this->controls[key] = MethodPtr;
}

template<typename Owner_T>
const MethodPtr<Owner_T> ControlsScheme<Owner_T>::getKeyBinding(const sf::Keyboard::Key key) const
{
    return this->controls[key];
}