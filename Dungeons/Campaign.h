#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include "Map.h"
#include <string>
#include <fstream>

class Campaign
{
    Map * campaign;
    int pos;
    int current;
    string name;

public:
    Campaign();
    ~Campaign();

    void accessMap(int);
    void createMap();
    void editMap();
    void saveMap() const;
    void addMap(Map &);

    Map getMap(int) const;
    int getPos() const;
    void print() const;

    void verify();

};


#endif /* CAMPAIGN_H */



