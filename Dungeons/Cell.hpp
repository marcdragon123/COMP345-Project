//
//  Cell.hpp
//  Map
//
//  Created by Garrison Blair on 2016-10-02.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include <iostream>
#include "Interaction.hpp"

using namespace std;
class Interaction;

class Cell
{
    bool empty;
    bool open;
    bool flagged;
    int borders[4];
    int bNorth, bSouth, bEast, bWest;
    Interaction inter;      // Character, Opponent, Chest, Wall, Door
    
public:
    Cell();
    Cell(const Cell &);
    Cell(Interaction);
    
    bool isEmpty();
    bool isOpen();
    bool isflagged();
    int getN() const;
    int getS() const;
    int getE() const;
    int getW() const;
    int * getBorders();
    Interaction getInter();
    
    void setNorth(int);
    void setSouth(int);
    void setEast(int);
    void setWest(int);
    void flag();
    void unflag();
    
    void addInter(Interaction);
    void removeInter();
};

#endif /* Cell_hpp */
