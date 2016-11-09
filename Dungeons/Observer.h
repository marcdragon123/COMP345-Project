/* @file Observer.h
*  @brief The Observer is an abstract class which is inherited
*		  by the DisplayCharacter class. The Observer's method
*		  update is called by the subject, which is the Character 
*		  class whenever Character calls the notify method. 
*		  The DisplayCharacter class overrides the update method. 
*/
#pragma once
#include <string>
using namespace std;

class Observer {
public:
	~Observer();
	virtual void Update(string) = 0;
protected:
	Observer();
};

