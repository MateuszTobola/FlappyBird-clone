#pragma once

#include "gameobject.hpp"



class Player : public gameObject
{
    public:
        Player();
        void update() override;
        void drawTo(sf::RenderWindow &window) override;
        void restart() override;

        void jump();

        sf::Vector2<float> getPosition();
        sf::Sprite* getSpritePointer();

    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;


};
