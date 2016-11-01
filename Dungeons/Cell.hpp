//////////////////////////////////////////////////////////
/// GAME RULES: A map in DnD comprises a grid of cells ///
/// that each has a certain type. That is to say, each ///
/// cell can be occupied by a character, an enemy, a   ///
/// container, a door, or a wall. The "type" of cell   ///
/// determines whether or not a player can move to or  ///
/// interact with this space.                          ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// DESIGN:    Cell is effectively a container used to ///
/// track what is contained per block. This allows the ///
/// user to set or switch what is contained in each    ///
/// block. The type determines whether or not a Cell   ///
/// can be passed (like a door, or enemy) or not (like ///
/// a wall or container). The Types are labeled as:    ///
/// w: WALL, c: CONTAINER, n: EMPTY, d: DOOR, e: ENEMY ///
/// p: PLAYER                                          ///
/// Cell also contains the "flagged" attribute, which  ///
/// is used when testing the Map object for a viable   ///
/// path.                                              ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// LIBRARIES USED:                                    ///
/// iosteam: The only library used, it's purpose is to ///
///          allow the user to see and interact with   ///
///          the objects, to better understand what is ///
///          happening.                                ///
//////////////////////////////////////////////////////////

#ifndef MAP_CELL_H
#define MAP_CELL_H

#include <iostream>

using namespace std;

class Type
{
    char obj;
    bool blocked;

public:
    Type();
    Type(int);

    bool isBlocked() const;
    char getObj() const;
};

class Cell
{
    bool flagged;
    Type type;

public:
    Cell();
    Cell(Type);

    // Access functions
    bool isFlagged() const;
    Type getType() const;

    // Path testing functions
    void flag();
    void unFlag();

    // Attribute modifier functions
    void setType(int);
    void removeType();
};

#endif //MAP_CELL_H