//
//  Map.hpp
//  Map
//
//  Created by Garrison Blair on 2016-10-02.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Cell.hpp"

class Cell;

class Map
{
    string name;
    string description;
    int width, height;
    int start, finish;
    
    Cell * cellList[1024];
    int cells;
    
public:
    Map();
    Map(int, int);
    
    string getName() const;
    string getDescription() const;
    int getWidth() const;
    int getHeight() const;
    int getsize() const;
    int getStart() const;
    int getFinish() const;
    
    void setName(string);
    void setDescription(string);
    void setStart(int);
    void setFinish(int);
    Cell getCell(int);
    Cell getCell(int, int);
    void setBorders();
    bool checkPath(int);
};

#endif /* Map_hpp */
