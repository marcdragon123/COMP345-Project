#include "Dice.h"

//This class is the object of a six sided die.

int Dice6::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}

void Dice6::Roll()
{
	srand(time(NULL));
	setCurrentRoll(rand()%6+1);
}