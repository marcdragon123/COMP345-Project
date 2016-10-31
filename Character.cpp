#include "Character.h"

Character::Character()
{
    name = "placeholder";
    role = "fighter";
    level = 1;
    int temp[9] = {12, 12, 12, 12, 12, 12, 0, 0};	// default stat distribution
    for (unsigned int i = 0; i < 9; i++) {
        stats[i] = temp[i];
    }
    
    stats[7] = this->prof() + this->mod(0); // attack bonus = proficiency bonus + strength modifier
    stats[8] = this->mod(0);				// damage bonus = strength modifier
    health = 10 + this->mod(stats[2]);		// HP = base + constitution modifier
    stats[6] = 10 + this->mod(stats[1]);	// AC = base + dex modifier
    
} // end default constructor

Character::Character(int lvl, string cls, string n)
{
    name = n;
    role = cls;
    level = lvl;
    
    Dice d = Dice();
    
    for (unsigned int i = 0; i < 6; i++)
    {
        stats[i] = d.roll(3, 6);                                    // randomly allocates skill points
    }
    
    stats[6] = 10 + d.roll(lvl-1, 10) + this->mod(stats[2]);        // HP = base + HP/lvl + constitution modifier
    stats[7] = 10 + this->mod(stats[1]);							// AC = base + dex modifier
} // end constructor

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
            helmet = gear;								// replaces old item with new item
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
    
} // end function equip

int* Character::getStats() { return stats;}

int Character::mod(int stat)
{
    int modifier = -5;								// assume lowest stat modifier
    for (unsigned int i = 0; i < 30; i += 2)
    {
        if (i >= stat) return modifier;				// increment by 2 until stat range is found
        else modifier++;
    }
    return modifier;
} // end function mod

int Character::prof()
{
    int proficiency = 2;							// assume base proficiency bonus
    for (unsigned int i = 4; i < 20; i += 4)
    {
        if (i >= level) return proficiency;			// increment by 4 until appropriate level is found
        else proficiency++;
    }
    return proficiency;
}// end function prof
