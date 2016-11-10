#include <iostream>
#include "Game.h"

int main() {

    Edit * game;
    game = new Edit();

    game->createCampaign();
    game->editCampaign();

    return 0;
}