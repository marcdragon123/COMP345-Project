#include "Item.h"

Item::Item()
{
    name = "Item";
    enchantment = 0;
    for (unsigned int i = 0; i < 9; i++) {
        enhance[i] = 0;
    }
    type = 'I';
} // end of Default Constructor

Item::Item(char type, int e)
{
    this->type = type;
    // Attributes assigned based on type
    // Enchantment applied to stats affected based on type of item
    switch (type) {
        // Helmet
        case 'h':
        {
            name = "Helmet";
            int temp[9] = {0, 0, 0, e, e, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
            // Armor
        case 'a':
        {
            name = "Armor";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
            // Shield
        case 's':
        {
            name = "Shield";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
            // Ring
        case 'r':
        {
            name = "Ring";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
            // Belt
        case 'c':
        {
            name = "Belt";
            int temp[9] = {e, 0, e, 0, 0, 0, 0, 0, 0,};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
            // Boots
        case 'b':
        {
            name = "Boots";
            int temp[9] = {0, e, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
            // Weapon
        case 'w':
        {
            name = "Weapon";
            int temp[9] = {0, 0, 0, 0, 0, 0, 0, e, e};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }

        default:
            break;
    } // end of switch statement

    enchantment = e;
} // end of Parametrized Constructor

inline bool Item::operator==(const Item& item) {
		return this->enchantment == item.enchantment
			&& this->getName() == item.getName() && this->getType() == item.getType();
}


Item::Item(const Item &item)
{
    type = item.type;
    name = item.name;
    enchantment = item.enchantment;
    for (unsigned int i = 0; i < 9; i++) {
        enhance[i] = item.enhance[i];
    }
} // end of Copy Constructor

string Item::getName() const { return name;} // end of getName()

char Item::getType() const { return type;} // end of getType()

int Item::getEnchantment() const { return enchantment;} // end of getEnchantment()

int* Item::getEnhancement() { return enhance;} // end of getEnhancement()

void Item::setName(string n) { name = n;} // end of setname()

void Item::printItem() {
    
    string enhancementsType = "";
    for (unsigned int i = 0; i < 7; i++)
    {
        if(enhance[i] == this->getEnchantment())
        {
            switch(i)
            {
                case 0:
                    enhancementsType.append(" STR,");
                    break;
                case 1:
                    enhancementsType.append(" DEX,");
                    break;
                case 2:
                    enhancementsType.append(" CON,");
                    break;
                case 3:
                    enhancementsType.append(" INT,");
                    break;
                case 4:
                    enhancementsType.append(" WIS,");
                    break;
                case 5:
                    enhancementsType.append(" CHA,");
                    break;
                case 6:
                    enhancementsType.append(" AC,");
                    break;   
            }
        }
    }
    cout  << " Name: " << name << " Enchantment: " << enchantment << " Type: " << type << " Skills: " << enhancementsType <<endl;
}