//
//  Cell.cpp
//  Map
//
//  Created by Garrison Blair on 2016-10-02.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#include "Cell.hpp"


// CONSTRUCTORS

Cell::Cell()
{
    empty = true;
    flagged = false;
    int temp[4] = {bNorth, bEast, bSouth, bWest};
    for (unsigned int i = 0; i < 4; i++) {
        borders[i] = temp[i];
    }
} // End of Default Constructor

Cell::Cell(const Cell &c)
{
    empty = c.empty;
    flagged = c.flagged;
    for (unsigned int i = 0; i < 4; i++) {
        borders[i] = c.borders[i];
    }
    bNorth = c.bNorth;
    bSouth = c.bSouth;
    bEast = c.bEast;
    bWest = c.bWest;
    if (c.empty == false) inter = c.inter;
} // End of Copy Constructor

Cell::Cell(Interaction in)
{
    inter = in;
    empty = true;
    flagged = false;
    int temp[4] = {bNorth, bEast, bSouth, bWest};
    for (unsigned int i = 0; i < 4; i++) {
        borders[i] = temp[i];
    }
} // End of Constructor


// BOOLEAN STATE CHECKS

bool Cell::isEmpty()    // Cell is empty
{
    if (empty == true) return true;
    else return false;
} // End of isEmpty function

bool Cell::isOpen()     // Cell can be moved into
{
    if (open == true) return true;
    else return false;
} // End of isOpen function

bool Cell::isflagged()  // Cell has been visited
{
    if (flagged == true) return true;
    else return false;
} // End of isFlagged function


// ATTRIBUTE ACCESSORS

int Cell::getN() const {return bNorth;}
int Cell::getS() const {return bSouth;}
int Cell::getE() const {return bEast;}
int Cell::getW() const {return bWest;}
Interaction Cell::getInter() {return inter;}


// ATTRIBUTE EDITORS

void Cell::setNorth(int b) {bNorth = b;}
void Cell::setSouth(int b) {bSouth = b;}
void Cell::setEast(int b) {bEast = b;}
void Cell::setWest(int b) {bWest = b;}

void Cell::flag() {flagged = true;}
void Cell::unflag() {flagged = false;}

void Cell::addInter(Interaction in)
{
    if (empty == true) {
        inter = in;
        empty = false;
        if (inter.block() == true) open = false;
    }
    else cout << "Could not add interaction" << endl;
} // End of addInter function

void Cell::removeInter()
{
    empty = true;
} // End of removeInter function
