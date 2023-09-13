#include "../headers/game.hpp"

int Pipe::pipeCounter = 0;
float Pipe::gapSize = 200;
float Pipe::gapBetweenSize = 300;
float Pipe::x_speed = -2;

Pipe::Pipe()
{
    m_ID = Pipe::pipeCounter;
    Pipe::pipeCounter += 1;

    m_texture.loadFromFile("./graphics/pipe.png");

    m_sprite_up.setTexture(m_texture);
    m_sprite_up.setOrigin(m_texture.getSize().x/2, m_texture.getSize().y/2);

    m_sprite_down.setTexture(m_texture);
    m_sprite_down.setOrigin(m_texture.getSize().x/2, m_texture.getSize().y/2);

  //  m_sprite_down.setRotation(180);

    m_velocity.x = x_speed;

    setStartingPosition();
}

void Pipe::update()
{
    m_sprite_up.move(m_velocity);
    m_sprite_down.move(m_velocity);

   if (m_sprite_up.getPosition().x < -50) resolvePosition();
}

void Pipe::drawTo(sf::RenderWindow &window)
{
    window.draw(m_sprite_up);
    window.draw(m_sprite_down);
}

void Pipe::restart()
{
    setStartingPosition();
    m_velocity.x = x_speed;
    hasPoint = true;
}

sf::Sprite* Pipe::getSprite_up()
{
    return &m_sprite_up;
}


sf::Sprite* Pipe::getSprite_down()
{
    return &m_sprite_down;
}

float Pipe::getXPosition()
{
    return m_sprite_up.getPosition().x;
}



void Pipe::resolvePosition()
{
    hasPoint = true;
    m_sprite_up.setPosition(850, -250 + rand() % 200);
    m_sprite_down.setPosition(850, m_sprite_up.getPosition().y + m_texture.getSize().y + gapSize);
}

void Pipe::setStartingPosition()
{
    m_sprite_up.setPosition(650 + gapBetweenSize * m_ID, -250 + rand()%150);
    m_sprite_down.setPosition(650 + gapBetweenSize * m_ID, m_sprite_up.getPosition().y + m_texture.getSize().y + gapSize);
}


