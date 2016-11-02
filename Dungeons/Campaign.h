#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include "Map.h"

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

    int getPos() const;
    void print() const;

};


#endif /* CAMPAIGN_H */

