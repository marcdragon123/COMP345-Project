#include "Game.h"

// CONSTRUCTOR
Game::Game() { campaign = new Campaign(); }

// DESTRUCTOR
Game::~Game() { delete campaign; }

// ACCESS MAP
Map Game::getMap(int x) const
{
    return campaign->getMap(x);
}

Play::Play():Game() { player = new Character();}

// SAVE CURRENT CAMPAIGN
void Game::save()
{
    string target;
    target = campaign->getName() + ".txt";

    ofstream campfile;
    campfile.open("Save_Data/Campaigns/" + target);

    for (unsigned int i = 0; i < campaign->getPos(); i++)
    {
        campfile << campaign->getMap(i).getName() << ".txt" << '\n';
    }
}

// LOAD MAP TO CAMPAIGN
void Game::load(string target)
{
    // Initialize builder pattern objects
    Director * direct = new Director();
    Builder * build = new EditBuilder();

    // Load campaign file
    ifstream active;
    active.open(target);
    string line;

    // Read through each line
    // Loading map objects into campaign object
    while (active >> line)
    {
        direct->setBuilder(build);
        direct->constructMap(line, campaign);
        campaign->addMap(*direct->getMap());
    }
}

void Game::loadCharacter(string target)
{
    // Initialize builder pattern objects
    Director * direct = new Director();
    Builder * build = new CharacterBuilder();
    direct->setBuilder(build);
    direct->constructCharacter(target);
    player = direct->getCharacter();
    cout << "Character loaded" << endl;
}

//CONSTRUCTOR / DESTRUCTOR
Edit::Edit():Game() {}
Edit::~Edit() { delete campaign; }
CharacterEditor::CharacterEditor():Game() {}

// RESET CAMPAIGN
void Game::createCampaign(string name)
{
    campaign = new Campaign(name);
}

void Game::createCharacter(string role, string name)
{
    player = new Character(1, role, name);
}

// EDIT CAMPAIGN
void Edit::editCampaign()
{
    int active;
    char end;
    do
    {
        // List maps in campaign
        campaign->print();
        cout << "Which Map would you like to edit? " << endl;
        cout << "----------------------------------------" << endl;

        // Input target map
        cin >> active;
        active--;

        // Create new map
        if (active == campaign->getPos())
            campaign->createMap();

        // Modify existing
        if (active <= campaign->getPos())
        {
            campaign->accessMap(active);
            campaign->editMap();
        }
        else cout << "Please enter a valid number" << endl;

        cout << "Finish editing campaign(y/n): ";
        cin >> end;
        if ((end == 'y') || (end == 'Y')) break;

    } while (1);

    this->save();
    cout << "Saved campaign to " << campaign->getName() << ".txt" << endl;
}

void CharacterEditor::editCharacter()
{
    int option;
    string n;
    char c;
    int role;
    int ind;
    while  (cout << "What would you like to edit?" << endl
                 << "1. Name" << endl << "2. Class" << endl
                 << "3. Level" << endl << "4. Type" << endl
                 << "5. Stats" << endl << "6. Finish" << endl)
    {
        cin >> option;
        if (option > 0 && option < 6)
        {
            switch (option)
            {
                case 1:
                    cout << "Current name is: " << player->getName() << endl;
                    cout << "Please enter a new name: ";
                    cin >> n;
                    player->setName(n);
                    break;
                case 2:
                    cout << "Current class is: " << player->getClass() << endl;
                    while   (cout << "Choose a class: " << endl
                                  << "1. Bully" << endl << "2. Nimble" << endl
                                  << "3. Tank" << endl)
                    {
                        cin >> role;
                        if (role > 0 && role < 4)
                            break;
                        else cerr << " Invalid input, try again." << endl;
                    }
                    player->setRole(player, role);
                    break;
                case 3:
                    cout << "Current level is: " << endl;
                    cout << "Please enter a new level: ";
                    cin >> role;
                    player->setLevel(role);
                    break;
                case 4:
                    cout << "Current type is: " << player->getType() << endl;
                    cout << "Choose a type" << endl;
                    cout << "p. Player" << endl;
                    cout << "e. Enemy" << endl;
                    cout << "f. Friendly" << endl;
                    cin >> c;
                    cout << "A";
                    player->setType(c);
                    cout << "B" << endl;
                    break;
                case 5:
                    while (1)
                    {
                        cout << "Which stat would you like to change?" << endl;
                        cout << "1. Strength:     " << player->getStat(0) << endl;
                        cout << "2. Dexterity:    " << player->getStat(1) << endl;
                        cout << "3. Constitution: " << player->getStat(2) << endl;
                        cout << "4. Intelligence: " << player->getStat(3) << endl;
                        cout << "5. Wisdom:       " << player->getStat(4) << endl;
                        cout << "6. Charisma:     " << player->getStat(5) << endl;
                        cout << "7. Stop Editing " << endl;
                        cin >> ind;
                        if (ind == 7) break;
                        else
                        {
                            if (ind == 1)
                            {
                                cout << "Enter the new value for Strength:";
                                cin >> role;
                                if (role < 31 && role > 0)
                                    player->setStat(0, role);
                                else cout << "Value out of range" << endl;
                            }
                            else if (ind == 2)
                            {
                                cout << "Enter the new value for Dexterity:";
                                cin >> role;
                                if (role < 31 && role > 0)
                                    player->setStat(1, role);
                                else cout << "Value out of range" << endl;
                            }
                            else if (ind == 3)
                            {
                                cout << "Enter the new value for Constitution:";
                                cin >> role;
                                if (role < 31 && role > 0)
                                    player->setStat(2, role);
                                else cout << "Value out of range" << endl;
                            }
                            else if (ind == 4)
                            {
                                cout << "Enter the new value for Intelligence:";
                                cin >> role;
                                if (role < 31 && role > 0)
                                    player->setStat(3, role);
                                else cout << "Value out of range" << endl;
                            }
                            else if (ind == 5)
                            {
                                cout << "Enter the new value for Wisdom:";
                                cin >> role;
                                if (role < 31 && role > 0)
                                    player->setStat(4, role);
                                else cout << "Value out of range" << endl;
                            }
                            else if (ind == 6)
                            {
                                cout << "Enter the new value for Charisma:";
                                cin >> role;
                                if (role < 31 && role > 0)
                                    player->setStat(5, role);
                                else cout << "Value out of range" << endl;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        else
        {
            campaign->saveCharacter(player);
            break;
        }
    }
}

void Play::playCampaign()
{
    campaign->addCharacter(player);

    unsigned int i = 0;
    int x = 0;
    int y = 0;
    string next;
    char end;

    while (1)
    {
        campaign->accessMap(i);
        i = campaign->playMap();
        campaign->saveMap();

        if (i == -1)
        {
            cout << "Are you sure you want to quit? (y/n)" << endl;
            cin >> end;
            if ((end == 'Y') || (end == 'y')) break;
        }

    }
    this->save();
}

bool Game::isNPC(string target)
{
    string type;
    ifstream active;
    active.open("Save_Data/Characters/" + target + ".txt");
    for (unsigned int i = 0; i < 3 ; i++)
        active >> type;
    if (type != "p")
        return true;
    else return false;
}