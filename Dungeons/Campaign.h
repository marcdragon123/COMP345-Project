/*! @file Character.cpp
*	@brief The Character class is a subclass of Subject. It attaches observers and notifies them
*		Implementation:
*		The Character class is implemented in such a way so that it follows the observer pattern.
*		The character class is a subject and will notify the DisplayCharacter class whenever changes
*		are made to the character class.
*
*		Game rules:
*		This class implements the character's abilities, current health, max health, damage bonus,
*		equipped items and attack bonus. There are two attack bonuses. One for melee and the other
*		for range. Based on the character's level, the character may be able to attack more than once.
*		As a reuslt the attack bonuses are stored in an array. Each element represent's an attack
*		turn. A fighter can attack up to 4 times depending on their level. The abilities, armor class
*		and danage bonuses are stored in the stats array. The first 5 elements represent the abilities,
*		while the last 2 elements are for armor class and damage bonus.
*
*/
#pragma once
#include "Subject.h"
#include "Item.h"
#include "Dice.h"
#include <iostream>
#include <list>
#include <string>

class Strategy;

class Character : public Subject{

    string name;            // Character Name
    string role;            // Character Class
    int level;              // Character Level
    int currentHealth;      // Character Hit Points
    int maxHealth;          //the max health for a character
    int stats[7];           // [STR, DEX, CON, INT, WIS, CHA, AC]
    int attackNum;          // Number of attacks
    int strAttackBonus;     //the attack bonuses for melee
    int dexAttackBonus;     //the attack bonuses for range
    void setStrAttackBonus();   //sets the attack bonuses for melee
    void setDexAttackBonus();   //sets the attack bonuses for range
    void updateCharacter();     //updates all of the character's stats when a change is made

    // Item Slots
    Item armor;
    Item helmet;
    Item boots;
    Item shield;
    Item weapon;
    Item ring;

    // Position Variables
    int charX;
    int charY;
    Strategy * strategy;
    char type;

public:
    Character(); 					    // default constructor
    Character(int, string);                                 // constructor w/ level
    Character(int, string, string);
    ~Character(); 					    // destructor

    void hit(int);                                          // character takes damage
    void levelUp();                                         //increase the characters level
    void setName(string n) {name = n;}
    void setRole(Character *,int);
    void setLevel(int);                                     //set the characters level
    void updateAttackBonuses();                             //sets the attack bonuses for the character

    string getArmor() const { return armor.getName(); }
    string getHelmet() const { return helmet.getName(); }
    string getBoots() const { return boots.getName(); }
    string getShield() const{ return shield.getName(); }
    string getWeapon() const { return weapon.getName(); }
    string getRing() const { return ring.getName(); }

    int getAValue() const { return armor.getEnchantment(); }
    int getHValue() const { return helmet.getEnchantment(); }
    int getBValue() const { return boots.getEnchantment(); }
    int getSValue() const { return shield.getEnchantment(); }
    int getWValue() const { return weapon.getEnchantment(); }
    int getRValue() const { return ring.getEnchantment(); }

    int getStrAttackBonus();                           //returns an array of the melee attack bonuses
    int getDexAttackBonus();                           //returns an array of the range attack bonuses
    int getAtkNum() const {return attackNum; }
    bool validateNewCharacter();                            //test method to test if character is valid
    int * getStats();                                       // returns stats array
    string getName() const;                                 //returns name
    string getRole() const { return role; }                 //returns role
    int getLevel() const { return level; }                  //returns level
    int getHealth() const { return currentHealth; }         //returns health
    int getMax() const { return maxHealth; }
    void setCurrent(int c) {currentHealth = c;}
    void setMax(int m) {maxHealth = m;}

    //void equip(Item&);                                    // applies stat changes from items
    int mod(int);                                           // calculates stat modifier
    void setStat(int, int);
    int getStat(int);
    Item getItem(char) const;
    string getClass() const;
    void equip(Item);

    int getCharX() const { return charX; }
    int getCharY() const { return charY; }
    char getType() const { return type; }
    void setCharX(int x) { charX = x; }
    void setCharY(int y) { charY = y; }
    void setType(char);
    void setEnchantments(int);

    void setStrategy(Strategy *);
    void move(int, int);
    void attack(Character *);
};


