#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

#include "player.hpp"
#include "pipe.hpp"

class Game
{
    public:
        Game();
        void run();
    private:

        //GAME

        enum state {RUNNING, OVER};
        state m_currentState = RUNNING;

        int m_points = 0;

        std::vector<gameObject *> p_objects;

        Player m_player;
        std::vector<Pipe> m_pipes;


        //WINDOW

        float windowSize_x = 800;
        float windowSize_y = 600;

        sf::RenderWindow m_mainWindow;
        sf::Event m_mainEvent;
        sf::View m_view;

        //Text

        sf::Font m_font;
        sf::Text m_gameOverText;
        sf::Text m_pointsText;



        //METHODS
        void initializeText();

        void input();
        void update();
        void render();
        void resolveGameLogic();

        void restart();

        void gameOver();

        std::vector<sf::Sprite*> getPipeSprites();

};
