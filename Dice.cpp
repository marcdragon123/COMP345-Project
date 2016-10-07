#include "Dice.h"

//This is the abstact class that the 20, 8 and 6 sided dies are going to implement.

using namespace std;
	
	Dice::Dice()
	{
		CurrentRoll = 1;
	}

	Dice::~Dice()
	{
		
	}

	int Dice::getCurrentRoll()
	{
		return CurrentRoll;
	}

	void Dice::Roll(int paramINTEGER)
	{
		CurrentRoll = rand() % paramINTEGER + 1;
	}