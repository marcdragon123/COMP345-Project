#ifndef GAME_H
#define GAME_H

#include "Campaign.h"
#include "Director.h"

class Game
{
protected:
    Campaign * campaign;

public:
    Game();
    ~Game();

    void save();
    void load();
    void newGame();

    Map getMap(int) const;

    //virtual void print() = 0;
};

class Edit: public Game
{
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

