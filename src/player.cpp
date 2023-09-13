#include "../headers/player.hpp"


Player::Player()
{
    m_texture.loadFromFile("./graphics/player.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(400, 350);
    m_sprite.setOrigin(m_texture.getSize().x/2, m_texture.getSize().y/2);
    m_velocity.x = 0.f;
    m_velocity.y = 5.f;
}

void Player::update()
{
    if (m_sprite.getPosition().y < 700 - m_sprite.getGlobalBounds().height)
    {
        m_sprite.move(m_velocity);
    }
    switch(m_velocity.y < 0)
        {
        case true:
            m_sprite.setRotation(-30);
            break;
        case false:
            m_sprite.setRotation(30);
            break;
        }
    if (m_velocity.y < 5) m_velocity.y +=1;
}


void Player::drawTo(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}


void Player::jump()
{
    m_velocity.y = -15;
}

void Player::restart()
{
    m_sprite.setPosition(400, 350);
    m_velocity.y = 0;
}


sf::Vector2<float> Player::getPosition()
{
    return m_sprite.getPosition();
}

sf::Sprite* Player::getSpritePointer()
{
    return &m_sprite;
}
