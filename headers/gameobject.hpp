#pragma once

#include <SFML/Graphics.hpp>

class gameObject{
public:
    gameObject();

    sf::Vector2<float> m_velocity;

    virtual void update() = 0;
    virtual void drawTo(sf::RenderWindow &window) = 0;
    virtual void restart() = 0;

};
