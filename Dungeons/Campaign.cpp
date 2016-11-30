#include "Character.h"
#include "Strategy.h"

Character::Character()
{
    name = "DEFAULT";
    role = "fighter";
    level = 1;
    attackNum = 1;
    Dice d = Dice();
    int temp[7] = { 12, 12, 12, 12, 12, 12, 0};	// default stat distribution
    for (unsigned int i = 0; i < 7; i++) {
        stats[i] = temp[i];
    }
    updateCharacter();//set currentHealth, armor class, damage bonus, and attack bonuses
    currentHealth = maxHealth;
    setType('e');
} // end default constructor

Character::Character(int lvl, string n)
{
    name = n;
    role = "fighter";
    level = lvl;
    attackNum = 0;

    for (unsigned int i = 1; i <= level; i+=5)
        attackNum += 1;

    Dice d = Dice();
    int r[4];

    for (unsigned int i = 0; i < 6; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
            r[j] = d.roll(1, 6);
        int temp;
        for (unsigned int j = 0; j < 4; j++)
            for (unsigned int k = 1; k < 4; k++)
            {
                if (r[j] < r[k])
                {
                    temp = r[k];
                    r[k] = r[j];
                    r[j] = temp;
                }
            }
        stats[i] = r[0] + r[1] + r[3];  // randomly allocates skill points
    }
    updateCharacter(); //set currentHealth, armor class, damage bonus, and attack bonuses
    currentHealth = maxHealth;
    setType('e');
} // end constructor

Character::Character(int lvl, string cls, string n)
{
    name = n;
    role = cls;
    level = lvl;
    attackNum = 0;

    for (unsigned int i = 1; i <= level; i+=5)
        attackNum += 1;

    Dice d = Dice();
    int r[4];
    int tempstat[6];

    for (unsigned int i = 0; i < 6; i++)
    {
        for (unsigned int j = 0; j < 4; j++)
            r[j] = d.roll(1, 6);
        int temp;
        for (unsigned int j = 0; j < 4; j++)
            for (unsigned int k = 1; k < 4; k++)
            {
                if (r[j] < r[k])
                {
                    temp = r[k];
                    r[k] = r[j];
                    r[j] = temp;
                }
            }
        tempstat[i] = r[0] + r[1] + r[3];  // randomly allocates skill points
    }

    sort(tempstat, tempstat + 6);

    if (role == "Bully")
    {
        stats[0] = tempstat[5];
        stats[2] = tempstat[4];
        stats[1] = tempstat[3];
        stats[3] = tempstat[2];
        stats[5] = tempstat[1];
        stats[4] = tempstat[0];
    }
    else if (role == "Nimble")
    {
        stats[1] = tempstat[5];
        stats[2] = tempstat[4];
        stats[0] = tempstat[3];
        stats[3] = tempstat[2];
        stats[5] = tempstat[1];
        stats[4] = tempstat[0];
    }
    else if (role == "Tank")
    {
        stats[2] = tempstat[5];
        stats[1] = tempstat[4];
        stats[0] = tempstat[3];
        stats[3] = tempstat[2];
        stats[5] = tempstat[1];
        stats[4] = tempstat[0];
    }
    updateCharacter();              //set currentHealth, armor class, damage bonus, and attack bonuses
    currentHealth = maxHealth;	// AC = base + dex modifier
    setType('e');
} // end constructor

void Character::updateCharacter() {
    maxHealth = 10 + this->mod(stats[2]) + level;   // HP = base + constitution modifier
    stats[6] = 10 + this->mod(stats[1]);            // AC = base + dex modifier
    updateAttackBonuses();
}


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
    Notify("Character received damage");
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

void Character::setRole(Character *me, int role)
{
    cout << "AA" << endl;
    switch (role)
    {
        case 1:
            me = new Character(me->getLevel(), "Bully", me->getName());
            break;
        case 2:
            me = new Character(me->getLevel(), "Nimble", me->getName());
            break;
        case 3:
            cout << "BB" << endl;
            me = new Character(me->getLevel(), "Tank", me->getName());
            cout << "CC" << endl;
            break;
        default:
            break;
    }
}

//!Change the character's level to the given value.
void Character::setLevel(int newLevel) {
    if (newLevel > level)
        for (unsigned int i = level; i < newLevel; i++)
            this->levelUp();
    else
    {
        level = newLevel;
        updateCharacter();
        Notify("Character level set to "+ std::to_string(level));
    }
}

//! Increases the character's level by 1. Additionally this method updates, the character's stats.
void Character::levelUp() {
    if (level%5 == 0 && level > 0)
        attackNum++;        // Increase number of attack rolls every 5 levels

    level++;                // Level is increased
    Dice d = Dice();

    int consMod = -5;       // Constitution modifier
    int cons = stats[2];

    for (unsigned int i = 2; i < cons; i+=2)
        consMod++;

    maxHealth += d.roll(1, 10, consMod);    // Max health increased
    currentHealth = maxHealth;              // Current health set to max
    strAttackBonus++;           // Attack bonus increased (Strength)
    dexAttackBonus++;           // Attack bonus increased (Dexterity)
    updateCharacter();
    Notify("Character leveled up. New level is " + std::to_string(level));
}

//! Returns an array of the melle attack bonuses. Each element is an attack turn.
//  There can be up to 4 attack turns. The number of attack turns is based on the
//	character's level.
int Character::getStrAttackBonus() {
    return strAttackBonus;
}

//! Returns an array of the range attack bonuses. Each element is an attack turn.
//  There can be up to 4 attack turns. The number of attack turns is based on the
//	character's level.
int Character::getDexAttackBonus() {
    return dexAttackBonus;
}

//! This method updates the attack bonuses, becuase the ability stats have changed.
void Character::updateAttackBonuses() {
    setStrAttackBonus(); //Range Attacks = Base attack bonus + Dexterity modifier
    setDexAttackBonus(); //Melee Attacks = Base attack bonus + Strength modifier
}

//! Melee Attacks = Base attack bonuses + Strength modifier
void Character::setStrAttackBonus() {
    int temp = -4;      // base bonus (0 stat, 1 prof bonus);
    for (unsigned int i = 1; i < stats[0]; i += 2)
        temp += 1;      //stat bonus
    for (unsigned int i = 1; i <= level; i +=4)
        temp +=1;       //proficiency bonus
}

//! Range Attack = Base attack bonus + Dexterity modifier
void Character::setDexAttackBonus() {
    int temp = -4;      // base bonus (0 stat, 1 prof bonus);
    for (unsigned int i = 1; i < stats[1]; i += 2)
        temp += 1;      //stat bonus
    for (unsigned int i = 1; i <= level; i +=4)
        temp +=1;       //proficiency bonus
}

void Character::setStat(int i, int x) { stats[i] = x; }

int Character::getStat(int k) { return stats[k]; }

Item Character::getItem(char c) const
{
    try
    {
        switch (c)
        {
            case 'a':
                return armor;
            case 'h':
                return helmet;
            case 'b':
                return boots;
            case 's':
                return shield;
            case 'w':
                return weapon;
            case 'r':
                return ring;
            default:
                throw "No item of such type";
        }
    } catch (char const* error) {
        cout << error << endl;
    }
}
string Character::getClass() const { return role; }
void Character::equip(Item gear)
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
    Notify("Character equipped item");
} // end function equip

string Character::getName() const { return name; }

void Character::setType(char t)
{
    type = t;
    if (t == 'p')
        this->setStrategy(new HumanPlayerStrategy());
    else if (t == 'e')
        this->setStrategy(new AggressorStrategy());
    else
        this->setStrategy(new FriendlyStrategy());
}

void Character::setEnchantments(int e)
{
    armor.setEnchantment(e);
    helmet.setEnchantment(e);
    boots.setEnchantment(e);
    shield.setEnchantment(e);
    weapon.setEnchantment(e);
    ring.setEnchantment(e);
}

void Character::setStrategy(Strategy * strat)
{
    strategy = strat;
}

void Character::move(int x, int y)
{
    strategy->move(x, y, this);
}

void Character::attack(Character * them)
{
    strategy->attack(this, them);
}