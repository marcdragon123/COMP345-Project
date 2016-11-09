///////////////////////////////////////////////////////////
/// GAME RULES: Menu is the very top level of the game. ///
/// It is where the player decides what they want to    ///
/// do and when they want to stop playing.              ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// DESIGN: The Menu class contains a Game object, and  ///
/// functions to prompt the user with different game    ///
/// modes. Their input is then used to determine how    ///
/// the game will be initialized, and pass commands to  ///
/// lower-level classes.                                ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// LIBRARIES USED:                                     ///
/// IOSTREAM: used to allow the user to communicate     ///
///           with the game. Vital to let them pick     ///
///           different functionalities.                ///
/// STRING:   used to simplify the naming procedure for ///
///           objects, as well as saving/loading.       ///
///////////////////////////////////////////////////////////

#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu
{
    Edit * game;
    int gameMode;

public:
    Menu();
    ~Menu();

    void edit();
    void play();
    void mainMenu();
};


#endif /* MENU_H */