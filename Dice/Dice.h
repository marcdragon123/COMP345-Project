#include "main.h"

//This main header incorporates all the implementations of the class dice and the abstact class dice.

using namespace std;

struct Dice {
private:
	 int CurrentRoll;
protected:
public:
	virtual int getCurrentRoll()=0;
	virtual void Roll()=0;
	void setCurrentRoll(int roll);
	Dice();
	~Dice();
};

class Dice20 : public Dice {
public:
	void Roll();
	int getCurrentRoll();
};

class Dice8 : public Dice
{
public: 
	void Roll();
	int getCurrentRoll();

};

class Dice6 : public Dice
{
public:
	void Roll();
	int getCurrentRoll();
};

class Dice4 : public Dice
{
public:
	void Roll();
	int getCurrentRoll();
};

class Dice100 : public Dice
{
public:
	void Roll();
	int getCurrentRoll();
};

class Dice10 : public Dice
{
public :
	void Roll();
	int getCurrentRoll();
};

class Dice12 : public Dice
{
public :
	void Roll();
	int getCurrentRoll();
};