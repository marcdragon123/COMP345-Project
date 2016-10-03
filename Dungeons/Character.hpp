//
//  Character.hpp
//  dungeons1
//
//  Created by Garrison Blair on 2016-09-28.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Item.hpp"
#include "Dice.hpp"

using namespace std;

class Character {
    
    string name;	//Character Name
    string role;	//Character Class
    int level;		//Character Level
                    //	int attack; 	//Attack Bonus
                    //	int damage;		//Damage Bonus
    int health;		//Character Hit Points
                    //	int armor;		//Armor Class
    int stats[9]; 	//[STR, DEX, CON, INT, WIS, CHA, AC, ATK, DMG]
    
    // Item Slots
    
    Item armor;
    Item helmet;
    Item boots;
    Item shield;
    Item weapon;
    Item ring;
    
public:
    Character(); 					//default constructor
    Character(int, string, string); //constructor w/ level
    ~Character(); 					//deconstructor
    
    void equip(Item&); 		//applies stat changes from items
    int mod(int); 			//calculates stat modifier
    int prof();				//calculates proficiency bonus
};

#endif /* Character_hpp */
