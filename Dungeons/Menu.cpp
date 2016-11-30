#include "Menu.h"

Menu::Menu() {
    game = new Edit();
    gameMode = 0;
}

Menu::~Menu() {};

void Menu::edit() {
    game = new Edit();

    ifstream directory;
    directory.open("Save_Data/Campaigns/Campaigns.txt");
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
        game->load("Save_Data/Campaigns/" + filename);
        game->editCampaign();
        directory.close();
        ofstream directory;
        directory.open("Save_Data/Campaigns/Campaigns.txt", std::ios_base::app);
        directory << "\n" << filename;
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

void Menu::character() {
    cE = new CharacterEditor();

    ifstream directory;
    directory.open("Save_Data/Characters/Characters.txt");
    int index = 1;
    string ls, filename, line;
    int active;
    int role;

    while (directory >> ls)
    {
        cout << index << ". " << ls << endl;
        index++;
    }
    cout << index << ". " << "Create new character" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Which Character would you like to edit? ";
    cin >> active;
    directory.clear();
    directory.seekg(0, ios::beg);
    if (active == index)
    {
        cout << "Enter a name for this Character: ";
        cin >> filename;
        while (cout << "Choose a class: " << endl
                    << "1. Bully" << endl << "2. Nimble" << endl
                    << "3. Tank" << endl)
        {
            cin >> role;
            if (role > 0 && role < 4)
                break;
            else cerr << " Invalid input, try again." << endl;
        }
        if (role == 1) line = "Bully";
        else if (role == 2) line = "Nimble";
        else line = "Tank";
        cE->createCharacter(line, filename);
        cE->loadCharacter("Save_Data/Characters/" + filename);
        cE->editCharacter();
        directory.close();
        ofstream directory;
        directory.open("Save_Data/Characters/Characters.txt", std::ios_base::app);
        directory << "\n" << filename;
        directory.close();
    }
    else if (active < index)
    {
        for (unsigned int i = 0; i < index; i++)
            directory >> filename;
        cE->loadCharacter("Save_Data/Characters/" + filename + ".txt");
        cE->editCharacter();
        directory.close();
    }//*/
    else cout << "Please enter a valid value" << endl;
}//*/

void Menu::play() {
    ifstream directory;
    int index = 1;
    string ls, filename, line;
    int active, role;

    while (1)
    {
        cout << "Select a Character:" << endl;
        directory.open("Save_Data/Characters/Characters.txt");
        while (directory >> ls)
        {
            cout << ls << endl;
            cout << pl->isNPC(ls) << endl;
            cout << "UH OH" << endl;
            if (!(pl->isNPC(ls)))
            {
                cout << index << ". " << ls << endl;
                index++;
            }
        }
        cout << index << ". Create new Character" << endl;
        cin >> active;
        directory.clear();
        directory.seekg(0, ios::beg);

        if (active == index)
        {
            cout << "Enter a name for this Character: ";
            cin >> filename;
            while (cout << "Choose a class: " << endl
                        << "1. Bully" << endl << "2. Nimble" << endl
                        << "3. Tank" << endl)
            {
                cin >> role;
                if ((role > 0) && (role < 4))
                    break;
                else cerr << " Invalid input, try again." << endl;
            }
            if (role == 1) line = "Bully";
            else if (role == 2) line = "Nimble";
            else line = "Tank";
            pl->createCharacter(line, filename);
            directory.close();
            ofstream directory;
            directory.open("Save_Data/Characters/Characters.txt", std::ios_base::app);
            directory << "\n" << filename;
            directory.close();
        }
        else if (active < index)
        {
            for (unsigned int i = 0; i < index; i++)
                directory >> filename;
            pl->loadCharacter("Save_Data/" + filename + ".txt");
            directory.close();
            cout << "Which campaign would you like to play?" << endl;
            directory.open("Save_Data/Campaigns/Campaigns.txt");
            while (directory >> ls)
            {
                cout << index << ". " << ls << endl;
                index++;
            }
            if (active < index)
            {
                for (unsigned int i = 0; i < index; i++)
                    directory >> filename;
                pl->createCampaign(filename);
                pl->load("Save_Data/Campaigns/" + filename + ".txt");
                pl->playCampaign();
                directory.close();
                break;
            }
            else cout << "Invalid input" << endl;
            break;
        }
        else cout << "Invalid input" << endl;
    }
}//*/

void Menu::mainMenu() {

    while (1)
    {
        cout << "**** WELCOME TO DUNGEONS & DRAGONS ****" << endl;
        cout << "     1. PLAY" << endl;
        cout << "     2. EDIT" << endl;
        cout << "     3. CHARACTERS" << endl;
        cout << "     4. QUIT" << endl;
        cout << "----------------------------------------" << endl;
        cout << "What would you like to do? ";
        cin >> gameMode;

        if (gameMode == 1) play();
        else if (gameMode == 2) edit();
        else if (gameMode == 3) character();
        else if (gameMode == 4) break;
    }

}
