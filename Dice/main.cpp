#include "main.h"
#include "mainclasses.h"
#include "Dice.h"


int main()
{
    int aNumOfRolls, aType, aBonus;
    string Choices;
    int* array;

    cout << "Please input the sentence for your choices in the form of xdy[z]:";

    cin >> Choices;

    array = StringUtil::parser(Choices);

    aNumOfRolls = array[0];

    aType = array[1];

    aBonus = array[2];

    string temp3 = to_string(RollDiceTotal::getTotal(aNumOfRolls, aType, aBonus));

    cout << temp3 +"\n";
}

int* StringUtil::parser(string pString)
{
    int* aValues = new int[4];

    string temp = pString.substr(0, pString.find("d")-0);
    aValues[0] = stoi(temp);
    cout << temp + "\n";

    string temp1 = pString.substr(pString.find("d")+1, (pString.find("[")-(pString.find("d")+1)));
    aValues[1] = stoi(temp1);
    cout << temp1 + "\n";

    string temp2 = pString.substr(pString.find("[")+1, pString.find("]")-(pString.find("[")+1));
    aValues[2] = stoi(temp2);
    cout << temp2 + "\n";

    return aValues;
}

int RollDiceTotal::getTotal(int pNumOfRoles, int pTypeofDice, int Bonus)
{
     Dice* aDice = nullptr;
    //this switch is not working might want to think how to fix it.
    switch (pTypeofDice)
    {
        case 4:
            aDice = new Dice4();
            break;
        case 6:
            aDice = new Dice6();
            break;
        case 8:
            aDice = new Dice8();
            break;
        case 10:
            aDice = new Dice10();
            break;
        case 12:
            aDice = new Dice12();
            break;
        case 20:
            aDice = new Dice20();
            break;
        case 100:
            aDice = new Dice100();
            break;
        default:
            cout << "Sorry that dice value does not exist";
    }

    int total = 0;
    if (aDice != nullptr)
    {

        for(int i = 0; i < pNumOfRoles; i++)
        {
            aDice->Roll();
            total+= aDice ->getCurrentRoll();
        }

        return (total + Bonus);
    }
    else
    {
        return total;
    }
}