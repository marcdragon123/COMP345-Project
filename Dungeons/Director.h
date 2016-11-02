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

