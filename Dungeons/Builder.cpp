#include "Builder.h"

// LOAD MAP FROM FILE
void EditBuilder::buildMap(string filename)
{
    ifstream active;
    active.open(filename);

    int x, y, dx, dy;
    string in, link;
    char t;

    active >> in >> y >> x;
    map = new Map(in, x, y);

    for (unsigned int i = 0; i < y; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            active >> t;
            switch (t) {
                case 'n':
                    map->setCell(j, i, t);
                    break;
                case 'd':
                    active >> link >> dx >> dy;
                    map->setCell(j, i, link, dx, dy);
                    break;
                case 'c':
                    map->setCell(j, i, 'c');
                    break;
                case 'e':
                    map->setCell(j, i, 'e');
                    break;
                case 'w':
                    map->setCell(j, i, 'w');
                    break;
                default:
                    break;
            }
        }
    }

    active.close();
}
