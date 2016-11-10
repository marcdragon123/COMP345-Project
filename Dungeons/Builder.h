///////////////////////////////////////////////////////////
/// GAME RULES: Given a file name, an identical copy of ///
/// the saved map must be created, either to play or to ///
/// edit.									            ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// DESIGN: The Builder class contains a pointer to a 	///
/// map object, and can return such pointer. It also 	///
///	contains a pure virtual function buildMap(string)	///
/// that is implemented in builders two inherited		///
///	classes ; EditBuilder and PlayBuilder.				///
///	They both create a map based on the maps text file, ///
/// reading from a file and accordingly building the 	///
/// world. In addition PlayBuilder, when building the 	///
/// map, levels it according to the player's level.		///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// LIBRARIES USED:                                     ///
/// IOSTREAM: used to display information so that users ///
///           can see what is happening.                ///
/// STRING:   used to simplify the tracking of campaign ///
///           and map names.                            ///
/// FSTREAM:  used to read maps to files				///
///////////////////////////////////////////////////////////

#ifndef Builder_h
#define Builder_h

#include <iostream>
#include <fstream>
#include "Map.h"

class Builder
{

protected:
    Map * map;
public:
    Map * getMap() { return map;}
    virtual void buildMap(string) = 0;
};

class EditBuilder : public Builder
{

public:
    void buildMap(string);
};

class PlayBuilder : public Builder
{

public:
    void buildMap(string, Character);
};

#endif /* Builder_h */