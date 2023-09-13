#pragma once
#include "gameobject.hpp"


class Pipe : public gameObject
{
public:
    Pipe();
    void update() override;
    void drawTo(sf::RenderWindow &window) override;
    void restart() override;

    sf::Sprite* getSprite_up();
    sf::Sprite* getSprite_down();

    float getXPosition();

    bool hasPoint = true;

private:

    int m_ID;


    sf::Texture m_texture;
    sf::Sprite m_sprite_up, m_sprite_down;


    static float gapSize;
    static float gapBetweenSize;
    static float x_speed;
    void resolvePosition();
    void setStartingPosition();

    static int pipeCounter;

};
