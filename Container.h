//////////////////////////////////////////////////////////
/// GAME RULES: A container serves the purpose of      ///
/// storing items, whether in a chest, backpack, or    ///
/// worn items.                                        ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// DESIGN: A container is an object that has a dynam- ///
/// array containing items, and an integer keeping     ///
/// track of its size, capped at 64 by default.        ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// LIBRARIES USED:                                    ///
/// iosteam: The only library used, it's purpose is to ///
///          allow the user to see and interact with   ///
///          the objects, to better understand what is ///
///          happening.                                ///
/// string:  It is used to search the items with       ///
///          strings.                                  ///
//////////////////////////////////////////////////////////

#ifndef Container_hpp
#define Container_hpp

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Container
{
    Item * itemList;        // List of items
    int items;              // Size of item list
    
public:
    Container();            // Default Constructor
    ~Container();           // Destructor
    
    void addItem(Item);     // Add item to container
    Item getItem(string);   // Get Item from container based on name
};

#endif /* Container_hpp */
