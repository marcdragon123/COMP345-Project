//
// Created by marc on 08/10/16.
//
#include "main.h"
#ifndef GAME_PROJECT_MAINCLASSES_H
#define GAME_PROJECT_MAINCLASSES_H
using namespace std;
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
