//
// Created by marc on 08/10/16.
//
#include "main.h"
#ifndef GAME_PROJECT_MAINCLASSES_H
#define GAME_PROJECT_MAINCLASSES_H
using namespace std;

/*
 * These two classes are used in the driver to parse the string that gives the type of dice and the number of rolls and the bonus used in the calculation
 * The getTotal method will calculate the total value of the number of roles and the value of each roll plus the bonus.
 */
class StringUtil
{
public:
    static int* parser(string param);
};

class RollDiceTotal
{
public:
    static int getTotal(int pNumOfRoles, int pTypeofDice, int Bonus);
};
#endif //GAME_PROJECT_MAINCLASSES_H
