///*
#include "Dice.hpp"

Dice::Dice()
{
   srand(static_cast<unsigned int>(time(NULL)));
}

int Dice::roll(int num, int size)
{
    int result = 0;
    for (unsigned int i = 0; i < num; i++)
    {
        result += rand() % size + 1;
    }
    return result;
} // end function roll

int Dice::roll(int num, int size, int mod)
{
    int result = 0;
    for (unsigned int i = 0; i < num; i++)
    {
        result += rand() % size + 1;
    }
    return (result + mod);
} // end function roll


// Function to parse string of form x 'd' y '+' z
// where x is number of dice of size y
// z is optional modifier

int Dice::roll(string input)
{
    // Position of 'd' character
    int d = 0;
    while (1)
    {
        if (input[d] != 'd') d++;
        else break;
    }
    
    // Position of '+' character
    int mod = d;
    while (1)
    {
        if (input[mod] != '+') mod++;
        // Safety, in case no '+' character
        else break;
    }
    
    // Convert characters up until 'd' into an integer (number of dice to roll)
    string n = input.substr(0, d);
    int num = atof(n.c_str());
    
    // Convert characters between 'd' and '+' into an integer (size of dice to roll)
    string s = input.substr(d+1, input.size() - mod);
    int size = atof(s.c_str());
    
    // Convert characters from '+' until end into an integer (modifier)
    string m = input.substr(mod+1);
    int modif = atof(m.c_str());
    
    // Calculate sum of dice roll(s), returns that + modifier
    int result = 0;
    for (unsigned int i = 0; i < num; i++)
        result += (rand() % size + 1);
    
    cout << "Number of rolls: " << num << endl;
    cout << "Size of dice:    " << size << endl;
    cout << "Total rolled:    " << result << endl;
    cout << "Modifier:        " << modif << endl;
    
    return (result + modif);
} // end function roll
 //*/
