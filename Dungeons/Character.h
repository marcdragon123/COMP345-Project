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
#include "Observer.h"
#include "Item.h"
#include "Dice.h"
#include <iostream>
#include <list>
#include <string>

class Subject {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify(string);
	Subject();
	~Subject();
private:
	list<Observer*> *_observers;
};

class Character : public Subject{
    
    string name;	// Character Name
    string role;	// Character Class
    int level;		// Character Level
    int currentHealth;		// Character Hit Points
	int maxHeath; //the max health for a character
    int stats[8]; 	// [STR, DEX, CON, INT, WIS, CHA, AC, DMG]
	int baseAttackBonuses[4]; //the base attack bonuses for a fighter
	int attackBonusesMelee[4]; //the attack bonuses for melee 
	int attackBonusesRange[4]; //the attack bonuses for range 
	void setBaseAttackBonuses(); //sets the Base Attack Bonuses for a Fighter character
	void setMeleeAttackBonuses(); //sets the attack bonuses for melee
	void setRangeAttackBonuses(); //sets the attack bonuses for range
	void updateCharacter(); //updates all of the character's stats when a change is made
    // Item Slots
    Item armor;
    Item helmet;
    Item boots;
    Item shield;
    Item weapon;
    Item ring;
    
public:
    Character(); 					    // default constructor
    Character(int, string);     // constructor w/ level
    ~Character(); 					    // deconstructor
	void hit(int); // character takes damage
	void levelUp(); //increase the characters level 
	void setLevel(int); //set the characters level
	void updateAttackBonuses(); //sets the attack bonuses for the character
	string getArmor() const { return armor.getName(); };
	string getHelmet() const { return helmet.getName(); };
	string getBoots() const { return boots.getName(); };
	string getShield() const{ return shield.getName(); };
	string getWeapon() const { return weapon.getName(); };
	string getRing() const { return ring.getName(); };
	int* getMeleeAttackBonuses(); //returns an array of the melee attack bonuses
	int* getRangeAttackBonuses(); //returns an array of the range attack bonuses 
	bool validateNewCharacter(); //test method to test if character is valid
    int * getStats();       // returns stats array
	string getName() const { return name; }; //returns name
	string getRole() const { return role; }; //returns role
	int getLevel() const { return level; }; //returns level
	int getHealth() const { return currentHealth; }; //returns health
    void equip(Item&); 		// applies stat changes from items
    int mod(int); 			// calculates stat modifier
};

