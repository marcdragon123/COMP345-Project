#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Item.h"
#include "Dice.h"

using namespace std;

class Character {
    
    string name;	// Character Name
    string role;	// Character Class
    int level;		// Character Level
    int health;		// Character Hit Points
    int stats[9]; 	// [STR, DEX, CON, INT, WIS, CHA, AC, ATK, DMG]
    
    // Item Slots
    Item armor;
    Item helmet;
    Item boots;
    Item shield;
    Item weapon;
    Item ring;
    
public:
    Character(); 					    // default constructor
    Character(int, string, string);     // constructor w/ level
    ~Character(); 					    // deconstructor

    int * getStats();       // returns stats array
    
    void equip(Item&); 		// applies stat changes from items
    int mod(int); 			// calculates stat modifier
    int prof();				// calculates proficiency bonus
};

#endif /* Character_hpp */
