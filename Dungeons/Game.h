///////////////////////////////////////////////////////////
/// GAME RULES: This is the module that will allow users///
/// to interact with the game, whether it be by playing ///
/// or editing (Note that only the editor is currently  ///
/// implemented). When editing, a user should be able   ///
/// to select a campaign from a file, or create a whole ///
/// new campaign. The campaign should then be saved     ///
/// when editing is complete.                           ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// DESIGN: The Game class acts as a parent class to    ///
/// the Edit and Play classes. Which class is           ///
/// instantiated will be determined by the client.      ///
/// Game contains a Campaign object, and allows the     ///
/// user to save/load a campaign to/from a file. From   ///
/// there, it simply provides the user with prompts and ///
/// sends messages to other classes (director/campaign).///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// LIBRARIES USED:                                     ///
/// IOSTREAM: used to allow the program to communicate  ///
///           with the user, and demonstrate what is    ///
///           being done.                               ///
/// STRING:   used to simplify the naming procedure for ///
///           maps and campaigns. Also helps with file  ///
///           access.                                   ///
/// FSTREAM:  used to allow the program to read and     ///
///           save data.                                ///
///////////////////////////////////////////////////////////

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
    void load(string);
    void loadCampaign(string);
    void newGame();

    Map getMap(int) const;
};

class Edit: public Game
{
public:
    Edit();
    ~Edit();

    void createCampaign(string);
    void editCampaign();
    //bool verify() const;
    //bool checkPath(int, int, int) const;
};

class Play: public Game
{

public:
    Play();
    void play();
};

#endif /* GAME_H */