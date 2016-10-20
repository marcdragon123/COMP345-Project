#include "Dice.h"

//This class is the object of a four sided die.

int Dice4::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}

void Dice4::Roll()
{
	srand(time(NULL));
	setCurrentRoll(rand()%4+1);
}