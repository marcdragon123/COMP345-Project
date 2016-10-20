#include "Dice.h"

//This class is the object of a one hundred sided die.

int Dice100::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}

void Dice100::Roll()
{
	srand(time(NULL));
	setCurrentRoll(rand()%100 +1);
}