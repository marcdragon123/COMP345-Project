#include "Menu.h"

Menu::Menu() {
    game = new Edit();
    gameMode = 0;
}

Menu::~Menu() {};

void Menu::edit() {
    game = new Edit();

    ifstream directory;
    directory.open("Save_Data/Campaigns.txt");
    int index = 1;
    string ls, filename;
    int active;

    while (directory >> ls)
    {
        cout << index << ". " << ls << endl;
        index++;
    }
    cout << index << ". " << "Create new campaign" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Which Campaign would you like to edit? ";
    cin >> active;
    directory.clear();
    directory.seekg(0, ios::beg);
    if (active == index)
    {
        cout << "Enter a name for this campaign: ";
        cin >> filename;
        game->createCampaign(filename);
        game->load("Save_Data/" + filename);
        game->editCampaign();
        directory.close();
    }
    else if (active < index)
    {
        for (unsigned int i = 0; i < index; i++)
            directory >> filename;
        game->createCampaign(filename);
        game->load("Save_Data/" + filename + ".txt");
        game->editCampaign();
        directory.close();
    }
    else cout << "Please enter a valid value" << endl;

}

void Menu::mainMenu() {

    while (1)
    {
        cout << "**** WELCOME TO DUNGEONS & DRAGONS ****" << endl;
        cout << "     1. PLAY (NOT IMPLEMENTED)" << endl;
        cout << "     2. EDIT" << endl;
        cout << "     3. QUIT" << endl;
        cout << "----------------------------------------" << endl;
        cout << "What would you like to do? ";
        cin >> gameMode;

        //if (gameMode == 1) play();
        if (gameMode == 2) edit();
        else if (gameMode == 3) break;
    }

}
