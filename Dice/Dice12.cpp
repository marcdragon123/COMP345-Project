#include "Dice.h"

//This class is the object of a twelve sided die.

int Dice12::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}

void Dice12::Roll()
{
	srand(time(NULL));
	setCurrentRoll(rand()%12+1);
}