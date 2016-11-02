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
/// 0: WALL, 1: CONTAINER, 2: EMPTY, 3: DOOR, 4: ENEMY ///
/// 5: PLAYER                                          ///
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

class Door
{
    string link;
    int x,y;

public:
    Door();
    Door(string, int, int);

    void setLink(string, int, int);

    string getLink() const;
    int getX() const;
    int getY() const;
};

class Type
{
    char obj;
    Door * door;
    bool blocked;

public:
    Type();
    Type(char);
    Type(string, int, int);

    char getObj() const;
    Door * getDoor() const;
    bool isBlocked() const;

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
    bool isBlocked() const;
    char getType() const;
    Door * getDoor() const;

    // Path testing functions
    void flag();
    void unFlag();

    // Attribute modifier functions
    void setType(char);
    void setType(string, int, int);
    void removeType();
};

#endif //MAP_CELL_H