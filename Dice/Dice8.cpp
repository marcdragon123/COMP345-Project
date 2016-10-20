#include "Dice.h"

//This is the class of an eight sided die.

void Dice8::Roll()
{
	srand(time(NULL));
	setCurrentRoll(rand()%8+1);
}

int Dice8::getCurrentRoll()
{
	return Dice::getCurrentRoll();
}