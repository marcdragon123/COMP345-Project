//
//  Item.hpp
//  dungeons1
//
//  Created by Garrison Blair on 2016-09-28.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Item
{
    char type;      // h, a, s, r, c, b, w
    string name;    // Helmet, Armor, Shield, Ring, Belt, Boots, Weapon
    int enchantment;
    int enhance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    
public:
    
    Item();
    Item(char, int);
    Item(const Item&);
    
    string getName() const;
    char getType() const;
    int getEnchantment() const;
    const int * getEnhancement() const;
    
};

#endif /* Item_hpp */
