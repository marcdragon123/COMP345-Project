#include "Observer.h"
#include "Display.h"

Observer::Observer() {};
Observer::~Observer() {};

DisplayCharacter::DisplayCharacter() {};

DisplayCharacter::DisplayCharacter(Character* s) {
	characterSubject = s;
}

DisplayCharacter::~DisplayCharacter() {
	characterSubject->Detach(this);
}
void DisplayCharacter::Update(string updateMessage) {
	displayCharacter(updateMessage);
}

void DisplayCharacter::displayCharacter(string updateMessage) {
	cout << "-----------------"<< updateMessage <<"-----------------" << endl;
	cout << "Character name: " << characterSubject->getName()<<endl;
	cout << "Character health: " << characterSubject->getHealth() << endl;
	cout << "Character role: " << characterSubject->getRole() << endl;
	cout << "Character level: " << characterSubject->getLevel() << endl;
	cout << "Character Health: " << characterSubject->getHealth() << endl;
	cout << "Character Strength: " << characterSubject->getStats()[0] << endl;
	cout << "Character Dexterity: " << characterSubject->getStats()[1] << endl;
	cout << "Character Con: " << characterSubject->getStats()[2] << endl;
	cout << "Character Intelligence: " << characterSubject->getStats()[3] << endl;
	cout << "Character wisdom: " << characterSubject->getStats()[4] << endl;
	cout << "Character charisma: " << characterSubject->getStats()[5] << endl;
	cout << "Character Armor Class: " << characterSubject->getStats()[6] << endl;
	cout << "Character Damage Bonus: " << characterSubject->getStats()[7] << endl;
	cout << "Character Armor: " << characterSubject->getArmor() << endl;
	cout << "Character Helmet: " << characterSubject->getHelmet()<< endl;
	cout << "Character Boots: " << characterSubject->getBoots() << endl;
	cout << "Character Shield: " << characterSubject->getShield() << endl;
	cout << "Character Weapon: " << characterSubject->getWeapon() << endl;
	cout << "Character Ring: " << characterSubject->getRing() << endl;
}

DisplayMap::DisplayMap() {}

DisplayMap::DisplayMap(Map * m)
{
    mapSubject = m;
}

DisplayMap::~DisplayMap()
{
    mapSubject->Detach(this);
}

void DisplayMap::Update(string updateMessage)
{
    displayMap(updateMessage);
}

void DisplayMap::displayMap(string updateMessage)
{
    cout << "Map Updated: " << updateMessage << endl;
    for (int y = mapSubject->getLength()-1; y >= 0; y--)
    {
        for (int i = 0; i < mapSubject->getWidth(); i++)
            cout << "--------";
        cout << "-" << endl;
        for (int x = 0; x < mapSubject->getWidth(); x++) {
            cout << "|";
            switch (mapSubject->getCell(x, y).getType()) {
                case 'n':
                    cout << "       ";
                    break;
                case 'd':
                    cout << "  |-|  ";
                    break;
                case 'c':
                    cout << "  ___  ";
                    break;
                case 'e':
                    cout << "  -E-  ";
                    break;
                case 'w':
                    cout << "|||||||";
                    break;
                case 'p':
                    cout << "  -P-  ";
                    break;
                default:
                    break;
            }
        }
        cout << "|" << endl;
        for (int x = 0; x < mapSubject->getWidth(); x++) {
            cout << "|";
            switch (mapSubject->getCell(x, y).getType()) {
                case 'n':
                    cout << "       ";
                    break;
                case 'd':
                    cout << "  |D|  ";
                    break;
                case 'c':
                    cout << " | C | ";
                    break;
                case 'e':
                    cout << "  / \\  ";
                    break;
                case 'w':
                    cout << "|||||||";
                    break;
                case 'p':
                    cout << "  / \\  ";
                    break;
                default:
                    break;
            }
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < mapSubject->getWidth(); i++)
        cout << "--------";
    cout << "-" << endl;
}