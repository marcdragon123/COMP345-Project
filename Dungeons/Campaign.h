#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include "Map.h"
#include <fstream>

class Campaign
{
    Map * campaign;
    int pos;
    int loaded;

public:
    Campaign();
    ~Campaign();

    void loadMap(int);
    void createMap();
    void editMap();
    void saveMap() const;

    int getPos() const;
    void print() const;

    void verify();

};


#endif /* CAMPAIGN_H */

