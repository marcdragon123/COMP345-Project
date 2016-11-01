//////////////////////////////////////////////////////////
/// GAME RULES: An Item in DnD is an object that can   ///
/// be of varying type. It can be a Helmet, Armor, a   ///
/// Shield, a Ring, a Belt, Boots, or a Weapon. The    ///
/// item's type defines which of the characters        ///
/// attributes are affected by it's enchantment.       ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// DESIGN: Item is an object that has a type, defined ///
/// by a char, and an integer enchantment. It also has ///
/// an enhance array that affects the characters at-   ///
/// tributes, based on the type and enchantment.       ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// LIBRARIES USED:                                    ///
/// iosteam: It's purpose is allow the user to see and ///
///          interact with the objects, to better un-  ///
///          derstand what is happening.               ///
/// string:  It is used to name the items with strings ///
///          in order to easily access items.          ///
//////////////////////////////////////////////////////////

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include <string>

using namespace std;

class Item
{
    char type;              // h, a, s, r, c, b, w
    string name;            // Helmet, Armor, Shield, Ring, Belt, Boots, Weapon
    int enchantment;        // Enchantment associated to item
    // Enhancement on characters abilities
    int enhance[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};   // [STR, DEX, CON, INT, WIS, CHA, AC, ATK, DMG]
    
public:
    
    Item();                 // Default Constructor
    Item(char, int);        // Constructor with Type and Enchantment
    Item(const Item&);      // Copy Constructor

    // Attribute Accessors
    string getName() const;
    char getType() const;
    int getEnchantment() const;
    int * getEnhancement();

    void setName(string);   // Set specific name to item
};

#endif /* Item_hpp */
