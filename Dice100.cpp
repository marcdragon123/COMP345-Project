#include "Dice.h"

//This class is the object of a one hundred sided die.

int Dice6::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}

void Dice6::Roll()
{
	Dice::Roll(100);
}