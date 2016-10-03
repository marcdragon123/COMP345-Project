//
//  Map.cpp
//  Map
//
//  Created by Garrison Blair on 2016-10-02.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#include "Map.hpp"


// CONSTRUCTORS

Map::Map()  // Generates a 10x10 blank map
{
    name = "Default Map";
    description = "10x10";
    width = 10;
    height = 10;
    cells = 0;
    
    for (unsigned int i = 0; i < (width*height); i++)
    {
        cellList[i] = new Cell();
        cells++;
    }
    
    this -> setBorders();
} // End of Default Constructor

Map::Map(int w, int h)  // Generates a WxH blank map
{
    name = "Default Map";
    description = to_string(w) + "x" + to_string(h);
    width = w;
    height = h;
    cells = 0;
    
    for (unsigned int i = 0; i < (width*height); i++)
    {
        cellList[i] = new Cell();
        cells++;
    }
    
    this -> setBorders();
} // End of Constructor


// ATTRIBUTE ACCESSORS

string Map::getName() const {return name;}
string Map::getDescription() const {return description;}
int Map::getWidth() const {return width;}
int Map::getHeight() const {return height;}
int Map::getsize() const {return cells;}
int Map::getStart() const {return start;}
int Map::getFinish() const {return finish;}


// ATTRIBUTE EDITORS

void Map::setName(string n) {name = n;}
void Map::setDescription(string d) {description = d;}
void Map::setStart(int s) {start = s;}
void Map::setFinish(int f) {finish = f;}


// GET LOCATION OF CELLS

Cell Map::getCell(int c) {return *cellList[c];}

Cell Map::getCell(int x, int y)
{
    if (x > width || y > height) {
        throw "Coordinates do not apply to map";
    }
    try {
        int number = (y-1) * width;
        number += x;
        return this->getCell(number);   // (x, y) coordinates converted to linear
    } catch (Cell error) {
        return error;
    }
} // End of getCell function


// DEFINE AND SET CELL BORDERS

void Map::setBorders()
{
    for (unsigned int i = 0; i < cells; i++) {
        
        if (i % width == 0) {cellList[i]->setWest(i);}  // no western border
        else {cellList[i]->setWest(i-1);}
            
        if ((i+1) % width == 0) {cellList[i]->setEast(i);}  // no eastern border
        else {cellList[i]->setEast(i+1);}
        
        if (i > 0 && i < width) {cellList[i]->setNorth(i);} // no northern border
        else {cellList[i]->setNorth(i-width);}
        
        if (i > (width*height)-width && i < (width*height)) {cellList[i]->setSouth(i);} // no southern border
        else {cellList[i]->setSouth(i+width);}
    }
} // End of setBorders function


// CHECK MAP FOR VIABLE PATH FROM START TO FINISH

bool Map::checkPath(int st) // Infinite loop case to be resolved
{
    int direct[4];  // cell borders for current location
    
    direct[0] = this->getCell(st).getN();
    direct[1] = this->getCell(st).getE();
    direct[2] = this->getCell(st).getW();
    direct[3] = this->getCell(st).getS();
    
    for (unsigned int i = 0; i < 4; i++)
    {
        if (st == finish)                               // reach finish cell
        {
            return true;
        }
        else if (this->getCell(direct[i]).isflagged())  // avoids moving to already visited cell
        {
            this->getCell(st).flag();                   // flag current cell
            continue;                                   // move on to next option
        }
        else if (this->getCell(direct[i]).isOpen())     // finds open bordering cell
        {
            this->getCell(st).flag();                   // flag current cell before moving on
            checkPath(direct[i]);                       // recursion on next cell
        }
    }
    
    // no path is found
    return false;
    
} // End of checkPath function
