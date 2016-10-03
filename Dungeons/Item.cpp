//
//  Item.cpp
//  dungeons1
//
//  Created by Garrison Blair on 2016-09-28.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#include "Item.hpp"

Item::Item() {}

Item::Item(char type, int e)
{
    
    switch (type) {
        case 'h':
        {
            name = "Helmet";
            int temp[9] = {0, 0, 0, e, e, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        case 'a':
        {
            name = "Armor";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        case 's':
        {
            name = "Shield";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        case 'r':
        {
            name = "Ring";
            int temp[9] = {0, 0, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        case 'c':
        {
            name = "Belt";
            int temp[9] = {e, 0, e, 0, 0, 0, 0, 0, 0,};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
        case 'b':
        {
            name = "Boots";
            int temp[9] = {0, e, 0, 0, 0, 0, e, 0, 0};
            for (unsigned int i = 0; i < 9; i++) {
                enhance[i] = temp[i];
            }
            break;
        }
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
    }
    
}

Item::Item(const Item &item)
{
    name = item.name;
    enchantment = item.enchantment;
    for (unsigned int i = 0; i < 9; i++) {
        enhance[i] = item.enhance[i];
    }
}

string Item::getName() const { return name;}

char Item::getType() const { return type;}

int Item::getEnchantment() const { return enchantment;}
