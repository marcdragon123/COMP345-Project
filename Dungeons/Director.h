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

    Character * getCharacter()
    {
        return builder->getCharacter();
    }

    void constructMap(string f, Campaign* ca)
    {
        builder->buildMap(f, ca);
    }

    void constructMap(string f, Character ch, Campaign* ca)
    {
        builder->buildMap(f, ch, ca);
    }

    void constructCharacter(string f)
    {
        builder->buildCharacter(f);
    }
};

#endif /* Director_h */

