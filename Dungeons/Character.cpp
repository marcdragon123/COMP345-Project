
#include "stdafx.h"
#include "Character.h"
#include "Observer.h"
#include <list>
#include <sstream>

Subject::Subject() {
	_observers = new list<Observer*>;
}
Subject::~Subject() {
	delete _observers;
}
void Subject::Attach(Observer* o) {
	_observers->push_back(o);
};
void Subject::Detach(Observer* o) {
	_observers->remove(o);
};
void Subject::Notify(string messageUpdate) {
	list<Observer *>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i) {
		(*i)->Update(messageUpdate);
	}
		
};


Character::Character()
{
    name = "placeholder";
    role = "fighter";
    level = 1;
	Dice d = Dice();
	int temp[9] = { 12, 12, 12, 12, 12, 12, 0, 0};	// default stat distribution
	for (unsigned int i = 0; i < 9; i++) {
		stats[i] = temp[i];
	}
	updateCharacter();//set currentHealth, armor class, damage bonus, and attack bonuses
	currentHealth = maxHeath;
} // end default constructor

Character::Character(int lvl, string n)
{
    name = n;
    role = "fighter";
    level = lvl;
    
    Dice d = Dice();
    
    for (unsigned int i = 0; i < 6; i++)
    {
        stats[i] = d.roll(3, 6);  // randomly allocates skill points
    }
	updateCharacter(); //set currentHealth, armor class, damage bonus, and attack bonuses
	currentHealth = maxHeath;
} // end constructor

void Character::updateCharacter() {
	maxHeath = 10 + this->mod(stats[2]) + level;		// HP = base + constitution modifier
	stats[6] = 10 + this->mod(stats[1]);	// AC = base + dex modifier							
	stats[7] = this->mod(stats[0]);				// damage bonus = strength modifier
	updateAttackBonuses();
}

//! Equips an item to the character. 
void Character::equip(Item &gear)
{
    switch (gear.getType())					// case for each type of equippable item
    {
        case 'h':
        {
			
            for (unsigned int i = 0; i < 9; i++)
            {
                stats[i] -= helmet.getEnhancement()[i];	// removes stat bonus from currently equipped item
                stats[i] += gear.getEnhancement()[i];	// adds new stat bonus
            }
            helmet = gear;		
			// replaces old item with new item
            break;
        }
        case 'a':
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                stats[i] -= armor.getEnhancement()[i];	// removes stat bonus from currently equipped item
                stats[i] += gear.getEnhancement()[i];	// adds new stat bonus
            }
            armor = gear;
            break;
        }
        case 'b':
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                stats[i] -= boots.getEnhancement()[i];	// removes stat bonus from currently equipped item
                stats[i] += gear.getEnhancement()[i];	// adds new stat bonus
            }
            boots = gear;
            break;
        }
        case 's':
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                stats[i] -= shield.getEnhancement()[i];	// removes stat bonus from currently equipped item
                stats[i] += gear.getEnhancement()[i];	// adds new stat bonus
            }
            shield = gear;
            break;
        }
        case 'r':
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                stats[i] -= ring.getEnhancement()[i];	// removes stat bonus from currently equipped item
                stats[i] += gear.getEnhancement()[i];	// adds new stat bonus
            }
            ring = gear;
            break;
        }
        case 'w':
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                stats[i] -= weapon.getEnhancement()[i];	// removes stat bonus from currently equipped item
                stats[i] += gear.getEnhancement()[i];	// adds new stat bonus
            }
            weapon = gear;
            break;
        }
        default: cout << "INVALID ITEM" << endl;
    }
	updateCharacter();
	Notify("Character equipped item");
} // end function equip

  //! Implementation of the verification of a newly created Character
  //! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool Character::validateNewCharacter()
{
	for (int i = 0; i <= 5; i++)
		if (stats[i]<3 || stats[i]>18)
			return false;
	return true;
}

//! Reduces the characters current health, by the damage. 
void Character::hit(int damage) {
	currentHealth = currentHealth - damage;
	Notify("Character recieved damage");
}

int* Character::getStats() { return stats;}

//!Returns the modifier of an ability. 
int Character::mod(int skillPoints)
{
	if (skillPoints % 2 == 1)
		return (skillPoints - 11) / 2; //odd skillpoints need to be rounded down
	else
		return (skillPoints - 10) / 2;//even skillpoints don't need to be rounded down
} // end function mod

//!Change the character's level to the given value. 
void Character::setLevel(int newLevel) {
	level = newLevel;
	updateCharacter();
	Notify("Character level set to "+ std::to_string(level));
}

//! Increases the character's level by 1. Additionally this method updates, the character's stats.
void Character::levelUp() {
	level++;
	updateCharacter();
	Notify("Character leveled up. New level is " + std::to_string(level));
}

//! Returns an array of the melle attack bonuses. Each element is an attack turn. 
//  There can be up to 4 attack turns. The number of attack turns is based on the 
//	character's level. 
int * Character::getMeleeAttackBonuses() {
	return attackBonusesMelee;
}

//! Returns an array of the range attack bonuses. Each element is an attack turn. 
//  There can be up to 4 attack turns. The number of attack turns is based on the 
//	character's level. 
int * Character::getRangeAttackBonuses() {
	return attackBonusesRange;
}

//! This method updates the attack bonuses, becuase the ability stats have changed. 
void Character::updateAttackBonuses() {
	setBaseAttackBonuses(); //need to set the base attack bonus for a fighter character first.
	setRangeAttackBonuses(); //Range Attacks = Base attack bonus + Dexterity modifier
	setMeleeAttackBonuses(); //Melee Attacks = Base attack bonus + Strength modifier
}

//! Melee Attacks = Base attack bonuses + Strength modifier
void Character::setMeleeAttackBonuses() {
	for (int index = 0; index < 4; index++) {
		attackBonusesMelee[index] = baseAttackBonuses[index] + stats[0];
	}
}

//! Range Attack = Base attack bonus + Dexterity modifier
void Character::setRangeAttackBonuses() {
	for (int index = 0; index < 4; index++) {
		attackBonusesRange[index] = baseAttackBonuses[index] + stats[1];
	}
}

//! Sets the attack bonuses for a fighter character. A character may be able to attack more than once depending on level. 
void Character::setBaseAttackBonuses() {
	//depending on the level, the fighter character can attack more than once. 
	baseAttackBonuses[0] = level;
	if (level > 5) {
		baseAttackBonuses[1] = level - 5;
		if (level > 10) {
			baseAttackBonuses[2] = level - 10;
			if (level > 15) {
				baseAttackBonuses[3] = level - 15;
			}
		}
	}
}
