#ifndef GAME_H
#define GAME_H

#include "Campaign.h"

class Game
{
public:
    Game();
    ~Game();

    void save();
    void load();
    void newGame();

    //virtual void print() = 0;
};

class Edit: public Game
{
    Campaign * campaign;
public:
    Edit();
    ~Edit();

    void createCampaign();
    void editCampaign();
    //void print();
};

class Play: public Game
{
    //Dice dice;
    //Character * player;
    //
public:
    Play();
    void play();
};

#endif /* GAME_H */
