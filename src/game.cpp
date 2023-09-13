#include "../headers/game.hpp"


Game::Game()
:m_mainWindow(sf::VideoMode(windowSize_x, windowSize_y), "Flappy Bird Clone", sf::Style::Close)
{
    m_mainWindow.setFramerateLimit(60);

    //Game objects init

    m_pipes.resize(3);
    for (Pipe &pipe : m_pipes)
    {
        p_objects.push_back(&pipe);
    }
    p_objects.push_back(&m_player);

    //Text init
    initializeText();
}

void Game::run()
{
    while(m_mainWindow.isOpen())
    {
     input();
     update();
     resolveGameLogic();
     render();
    }
}

void Game::initializeText()
{
    m_font.loadFromFile("arial.ttf");
    m_pointsText.setCharacterSize(40);
    m_pointsText.setFillColor(sf::Color::White);
    m_pointsText.setOutlineColor(sf::Color::Black);
    m_pointsText.setOutlineThickness(3);
    m_pointsText.setFont(m_font);
    m_pointsText.setPosition(m_mainWindow.mapPixelToCoords(sf::Vector2i(windowSize_x/2,0)));

    m_gameOverText.setCharacterSize(40);
    m_gameOverText.setFillColor(sf::Color::White);
    m_gameOverText.setOutlineColor(sf::Color::Black);
    m_gameOverText.setOutlineThickness(3);
    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("Press 'R' to restart");
    m_gameOverText.setPosition(m_mainWindow.mapPixelToCoords(sf::Vector2i(windowSize_x/2-m_gameOverText.getGlobalBounds().getSize().x/2,windowSize_y/2)));
}

void Game::input()
{
    while(m_mainWindow.pollEvent(m_mainEvent))
    {
        switch(m_mainEvent.type)
        {
            case sf::Event::Closed:
                m_mainWindow.close();
                break;
            case sf::Event::KeyPressed:
                if(m_mainEvent.key.code == sf::Keyboard::Space && m_currentState == RUNNING) m_player.jump();
                else if(m_mainEvent.key.code == sf::Keyboard::R) restart();
                break;
            default:
                break;
        }
    }
}

void Game::update()
{
    for (gameObject* object : p_objects)
    {
        object -> update();
    }
}

void Game::render()
{
    m_mainWindow.clear(sf::Color(50, 150, 200));

    for (gameObject* object : p_objects)
    {
        object -> drawTo(m_mainWindow);
    }
    m_mainWindow.draw(m_pointsText);
    if (m_currentState == OVER) m_mainWindow.draw(m_gameOverText);
    m_mainWindow.display();
}

void Game::resolveGameLogic()
{
    if (m_currentState != RUNNING) return;
    if (m_player.getPosition().y > windowSize_y || m_player.getPosition().y < 0) gameOver(); //Screen borders check
    for(sf::Sprite* sprite : getPipeSprites()) //Pipe hit check
    {
        if(m_player.getSpritePointer() -> getGlobalBounds().intersects(sprite->getGlobalBounds()))
                gameOver();
    }
    for(Pipe& pipe : m_pipes)
    {
        if (m_player.getPosition().x > pipe.getXPosition() && pipe.hasPoint)
        {
            pipe.hasPoint = false;
            m_points += 1;
            break;
        }
    }


    m_pointsText.setString(std::to_string(m_points));
}

void Game::restart()
{
    for (gameObject* object : p_objects)
    {
        object -> restart();
    }
    m_currentState = RUNNING;
    m_points = 0;
}

void Game::gameOver()
{
    m_currentState = OVER;
    m_player.m_velocity.y = 15;
    for(Pipe& pipe : m_pipes)
    {
        pipe.m_velocity.x = 0;
    }

}

std::vector<sf::Sprite*> Game::getPipeSprites()
{
    std::vector<sf::Sprite*> allPipeSprites;
    for (Pipe& pipe : m_pipes)
    {
        allPipeSprites.push_back(pipe.getSprite_down());
        allPipeSprites.push_back(pipe.getSprite_up());
    }
    return allPipeSprites;
}





