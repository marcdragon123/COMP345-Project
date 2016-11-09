//! @file 
//! @brief Driver file which tests the observer pattern. A character is created and the display character observes the
// character. When the character calls the equipe method, the display character object displays the character's stats. 
#include "Character.h"
#include "DisplayCharacter.h"

int main(int argc, char* argv[])
{
	Character *character = new Character();
	DisplayCharacter *display = new DisplayCharacter(character);
	character->Attach(display);
	Item * item = new Item('h', 5);
	character->equip(*item);
	system("pause");
	return 0;
}