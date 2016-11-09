#include "Observer.h"
#include "DisplayCharacter.h"

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
	cout << "Character Streangth: " << characterSubject->getStats()[0] << endl;
	cout << "Character Dexterity: " << characterSubject->getStats()[1] << endl;
	cout << "Character Con: " << characterSubject->getStats()[2] << endl;
	cout << "Character Intelligence: " << characterSubject->getStats()[3] << endl;
	cout << "Character wisdon: " << characterSubject->getStats()[4] << endl;
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