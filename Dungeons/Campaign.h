///////////////////////////////////////////////////////////
/// GAME RULES: A campaign is defined as a set of       ///
/// interconnected maps. Map adjacencies are defined    ///
/// with doors. Every door links two points, which      ///
/// can be on different maps or the same maps. Maps     ///
/// are therefore considered valid if there is an       ///
/// unobstructed path connecting two doors.             ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// DESIGN: The campaign class contains an array of     ///
/// maps. The order of these maps doesn't matter, since ///
/// doors will be used to navigate through them, but    ///
/// the campaign starts in the first map in the array.  ///
/// This object contains a function accessMap, which    ///
/// is used to set which map is currently being mod-    ///
/// ified. It also contains createMap: used to make a   ///
/// new, blank map, addMap: used to load an existing    ///
/// map, editMap: used to modify the accessed map, and  ///
/// saveMap: save a map to a file. All data is saved in ///
/// in a local 'SAVE_DATA' directory.                   ///
/// By default, the campaign array is of size 64, and   ///
/// a separate variable 'pos' is used to track how many ///
/// maps are loaded into it.                            ///
/// Finally, the print function lists all of the maps   ///
/// currently in the campaign.                          ///
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
/// LIBRARIES USED:                                     ///
/// IOSTREAM: used to display information so that users ///
///           can see what is happening.                ///
/// STRING:   used to simplify the tracking of campaign ///
///           and map names.                            ///
/// FSTREAM:  used to save maps to files, and to read   ///
///           them back.                                ///
///////////////////////////////////////////////////////////

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
    Campaign(string);
    ~Campaign();

    void accessMap(int);
    void createMap();
    void editMap();
    void saveMap() const;
    void addMap(Map &);

    string getName() const;
    Map getMap(int) const;
    int getPos() const;
    void print() const;

    bool checkPath(int, int);

};


#endif /* CAMPAIGN_H */




