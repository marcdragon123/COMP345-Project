#include "Builder.h"
#include "Display.h"

// LOAD MAP FROM FILE
void EditBuilder::buildMap(string filename, Campaign* camp)
{
    ifstream active;
    active.open("Save_Data/Campaigns/" + filename);

    int x, y;
    int dx, dy;
    int size, e;
    int lvl, en;
    string in, link, target;
    char t, t2;
    Character* choc;

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
                    active >> size;
                    for (int c = 0; c < size; c++)
                    {
                        active >> t2 >> e;
                        map->getCell(j, i).getContainer()->addItem(t2, e);
                    }
                    break;
                case 'e':
                    active >> target;
                    buildCharacter(target);
                    map->setCell(j, i, character);
                    character->setCharX(j);
                    character->setCharY(i);
                    map->addCharacter(character);
                    cout << "AAA" << endl;
                    cout << map->getCell(j, i).getType() << endl;
                    cout << map->getCell(j, i).getCharacter()->getName() << endl;;
                    break;
                case 'w':
                    map->setCell(j, i, 'w');
                    break;
                default:
                    break;
            }
        }
    }
    DisplayMap *display = new DisplayMap(map);
    map->Attach(display);

    active.close();
}

void PlayBuilder::buildMap(string filename, Character ch, Campaign* camp)
{
    ifstream active;
    active.open("Save_Data/Campaigns/" + filename);
    
    int x, y;
    int dx, dy;
    int size;
    int lvl, en;
    string in, link, target;
    char t, t2;
    Character* choc;
    
    active >> in >> y >> x;
    map = new Map(in, x, y);
    
    for (unsigned int i = 0; i < y; i++)
    {
        for (unsigned int j = 0; j < x; j++)
        {
            active >> t;
            switch (t)
            {
                case 'n':
                    map->setCell(j, i, t);
                    break;
                case 'd':
                    active >> link >> dx >> dy;
                    map->setCell(j, i, link, dx, dy);
                    break;
                case 'c':
                    map->setCell(j, i, 'c');
                    active >> size;
                    for (int c = 0; c < size; c++)
                    {
                        active >> t2 >> en;
                        en = ch.getLevel();
                        map->getCell(j, i).getContainer()->addItem(t2, en);
                    }
                    break;
                case 'e':
                    active >> target;
                    buildCharacter(target);
                    choc = character;
                    choc->setLevel(ch.getLevel());
                    choc->setEnchantments(ch.getLevel());
                    map->setCell(j, i, choc);
                    choc->setCharX(j);
                    choc->setCharY(i);
                    map->addCharacter(choc);
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

void Builder::buildCharacter(string filename)
{
    ifstream active;
    active.open("Save_Data/Characters/" + filename);
    
    string name, role, stop;
    char type, item;
    int lvl, cH, mH, s, sAB, dAB, enchant;
    
    active >> name >> role >> type;
    active >> lvl >> cH >> mH;
    character = new Character(lvl, role, name);
    character->setCurrent(cH);
    character->setMax(mH);
    character->setType(type);
        
    for (unsigned int i = 0; i < 7; i++)
    {
        active >> s;
        character->setStat(i, s);
    }
    
    active >> sAB >> dAB;
    Item it; 
    
    active >> enchant;
    it = Item('a', enchant);
    character->equip(it);
    active >> enchant;
    it = Item('h', enchant);
    character->equip(it);
    active >> enchant;
    it = Item('b', enchant);
    character->equip(it);
    active >> enchant;
    it = Item('s', enchant);
    character->equip(it);
    active >> enchant;
    it = Item('w', enchant);
    character->equip(it);
    active >> enchant;
    it = Item('r', enchant);
    character->equip(it);
    
    active.close();
}