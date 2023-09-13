#include "./headers/game.hpp"
#include "time.h"


int main()
{
    srand(time(NULL));
    Game mainGame;
    mainGame.run();
    return 0;
}
