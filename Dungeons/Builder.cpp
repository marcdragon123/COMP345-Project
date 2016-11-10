#include "Builder.h"

// LOAD MAP FROM FILE
void EditBuilder::buildMap(string filename)
{
    // Opening map file
    ifstream active;
    active.open(filename);

    int x, y;					// width and length of map
    int dx, dy;					// door x and y link positions
    int size;					// size of container
    int lvl, en;				// character level and enchantment
    string in, link, cls, name;	// map name, door link, character class and name
    char t, t2;					// cell type, item type

    active >> in >> y >> x;
    map = new Map(in, x, y);	// creating map object

    for (unsigned int i = 0; i < y; i++)	// go through y
    {
        for (unsigned int j = 0; j < x; j++)	// go through x
        {
            active >> t;
            switch (t)		// create cell based on type
            {
                // Empty cell
                case 'n':
                    map->setCell(j, i, t);
                    break;
                    // Door cell
                case 'd':
                    active >> link >> dx >> dy;
                    map->setCell(j, i, link, dx, dy);
                    break;
                    // Container cell
                case 'c':
                    map->setCell(j, i, 'c');
                    active >> size;
                    for (int c = 0; c < size; c++)	// go through container items
                    {
                        active >> t2 >> en;
                        map->getCell(j, i).getContainer()->addItem(t2, en);	// adding item to container
                    }
                    break;
                    // Enemy cell
                case 'e':
                    active >> lvl >> cls >> name >> en;
                    map->setCell(j, i, lvl, cls, name);
                    map->getCell(j, i).getCharacter()->equip(Item('w', en));
                    for (int k = 0; k < 9; k++)	// go through enemy stats
                    {
                        active >> en;
                        map->getCell(j, i).getCharacter()->setStat(k, en);	// setting enemy stats
                    }
                    break;
                    // Wall cell
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

void PlayBuilder::buildMap(string filename, Character ch)
{
    // Opening map file
    ifstream active;
    active.open(filename);

    int x, y;					// width and length of map
    int dx, dy;					// door x and y link positions
    int size;					// size of container
    int lvl, en;				// character level and enchantment
    string in, link, cls, name;	// map name, door link, character class and name
    char t, t2;					// cell type, item type

    active >> in >> y >> x;
    map = new Map(in, x, y);	// creating map object

    for (unsigned int i = 0; i < y; i++)	// go through y
    {
        for (unsigned int j = 0; j < x; j++)	// go through x
        {
            active >> t;
            switch (t)		// create cell based on type
            {
                // Empty cell
                case 'n':
                    map->setCell(j, i, t);
                    break;
                    // Door cell
                case 'd':
                    active >> link >> dx >> dy;
                    map->setCell(j, i, link, dx, dy);
                    break;
                    // Container cell
                case 'c':
                    map->setCell(j, i, 'c');
                    active >> size;
                    for (int c = 0; c < size; c++)
                    {
                        active >> t2 >> en;
                        en = ch.getLevel();
                        map->getCell(j, i).getContainer()->addItem(t2, en);	// adding item to container based on character level
                    }
                    break;
                    // Enemy cell
                case 'e':
                    active >> lvl >> cls >> name >> en;
                    lvl = ch.getLevel();
                    en = ch.getLevel();
                    map->setCell(j, i, lvl, cls, name);
                    map->getCell(j, i).getCharacter()->equip(Item('w', en)); // setting enemy stats based on character level
                    for (int k = 0; k < 9; k++)
                    {
                        active >> en;
                        map->getCell(j, i).getCharacter()->setStat(k, en);
                    }
                    break;
                    // Wall cell
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

