//////////////////////////////////////////////////////////
/// GAME RULES: A map consists of a rectangular grid   ///
/// that can be occupied by a wall, a character, an    ///
/// opponent, a door, a container, or nothing. Charac- ///
/// ters and NPCs can only move directly up, down,     ///
/// left, right. Moving diagonally is not permitted.   ///
/// Cells containing walls or containers cannot be     ///
/// moved through. All other spaces can be passed.     ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// DESIGN:       A map object consists of a 2D array  ///
/// initialized in the constructor. These arrays con-  ///
/// tain objects of type Cell, and are initialized to  ///
/// to empty. The Map itself only contains data about  ///
/// the size of the grid, the starting point, and the  ///
/// the ending point. It also contains functions that  ///
/// allow for a user to manually set the entry and ex- ///
/// it points, as well as setting individual Cells to  ///
/// contain a wall/character/etc. It also has a func-  ///
/// tion to verify that there is a path through the    ///
/// map.                                               ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// LIBRARIES USED:                                    ///
/// iostream: As with Cell, the only action the grid   ///
///           needed to be able to perform was to com- ///
///           municate with the user to provide in-    ///
///           formation about what was being done.     ///
///           Built-in arrays were used for simplicity ///
/// string:   The string library was used to simplify  ///
///           the creation and manipulation of the map ///
///           name. It is not mandatory, but helps to  ///
///           differentiate maps.                      ///
//////////////////////////////////////////////////////////

#ifndef MAP_MAP_H
#define MAP_MAP_H

#include "Cell.h"
#include <string>

class Map
{
    int width, length;
    string name;

    Cell ** grid;

public:
    Map();
    Map(int, int);
    ~Map();

    // Access functions
    Cell getCell(int, int);
    int getWidth() const;
    int getLength() const;
    string getName() const;

    // Attribute modifier functions
    void setName(string);

    // Path testing functions
    void setCell(int, int, char);
    void setCell(int, int, string, int, int);
    void clearFlags();
    bool checkPath(int, int);
    bool verify();

    void print();
};

#endif //MAP_MAP_H
