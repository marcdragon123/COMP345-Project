#include "Dice.h"

//This class is the object of a ten sided die.

int Dice10::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}

void Dice10::Roll()
{
	srand(time(NULL));
	int currentRoll = rand() % 10 + 1;
	setCurrentRoll(currentRoll);
}