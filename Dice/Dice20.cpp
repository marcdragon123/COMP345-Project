#include "Dice.h"

//This is the class of a twenty sided die.

void Dice20::Roll()
{
	srand(time(NULL));
	setCurrentRoll(rand()%20+1);
}

int Dice20::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}