///////////////////////////////////////////////////////////
/// GAME RULES: When a map is loaded from a text file   ///
/// it must be built by the director using such file,   ///
/// calling the builder class.				            ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// DESIGN: The director class contains a pointer to a  ///
/// builder object which it uses to call its public     ///
/// member functions in order to build the map. It can  ///
/// then return the built map.							///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// LIBRARIES USED:                                     ///
/// IOSTREAM: used to display information so that users ///
///           can see what is happening.                ///
/// STRING:   used to simplify the tracking of campaign ///
///           and map names.                            ///
///////////////////////////////////////////////////////////

#ifndef Director_h
#define Director_h

#include <iostream>
#include "Builder.h"

class Director
{
    Builder * builder;

public:
    void setBuilder(Builder* mb)
    {
        builder = mb;
    }

    Map * getMap()
    {
        return builder->getMap();
    }

    void constructMap(string f)
    {
        builder->buildMap(f);
    }
};

#endif /* Director_h */