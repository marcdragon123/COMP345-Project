/* @file DisplayCharacter.h
*  @brief This class observers the character class and displays
*			The character's stats. This class is an observer 
*			and it observers the subject Character.
*/
#pragma once

#include "Character.h"
#include "Observer.h"

class DisplayCharacter :public Observer {
private:
	Character *characterSubject;
public:
	DisplayCharacter();
	DisplayCharacter(Character* s);
	~DisplayCharacter();
	void Update(string);
	void displayCharacter(string);
};
