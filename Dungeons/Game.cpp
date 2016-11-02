
#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::save()
{

}

void Game::load()
{

}

void Game::newGame()
{

}

Edit::Edit():Game() { campaign = new Campaign(); }
Edit::~Edit() { delete campaign; }

void Edit::createCampaign()
{
    delete campaign;
    campaign = new Campaign();
}

void Edit::editCampaign()
{
    int active;
    char end;
    do
    {
        campaign.print();
        cout << "Which Map would you like to edit? ";
        cin >> active;
        if (active == campaign.getPos())
            campaign.createMap();
        else if (active <= campaign.getPos())
        {
            campaign.loadMap(active-1);
            campaign.editMap();
        }
        else cout << "Please enter a valid number" << endl;

        cout << "Done? (y/n): ";
        cin >> end;
        if ((end == 'n') || (end == 'N')) break;

    } while (1);

    this->save();
}