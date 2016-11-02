#include "Campaign.h"


// CONSTRUCTOR
Campaign::Campaign()
{
    campaign = new Map[64];
    name = "DEFAULT";
}

// DESTRUCTOR
Campaign::~Campaign()
{
    delete [] campaign;
}

// SETS ACTIVE MAP
void Campaign::accessMap(int in)
{
    current = in;
}

// USER ADD MAP TO CAMPAIGN
void Campaign::createMap()
{
    int x, y;
    string name;
    cout << "Input map width: ";
    cin >> x;
    cout << "Input map length: ";
    cin >> y;
    cout << "Enter map name: ";
    cin >> name;
    campaign[pos] = Map(name, x, y);
    cout << "Map generated" << endl;
    if (pos == 0)
    {
        cout << "Enter the coordinates of the start: " << endl;
        cin >> x;
        cin >> y;
        campaign[pos].setCell(x-1, y-1, "CAMPAIGN_START", 0, 0);
    }
    pos++;
}

// USER EDIT EXISTING MAP
void Campaign::editMap()
{
    int x1, y1, x2, y2, type, map;
    char end;
    do
    {
        campaign[current].print();
        cout << "Enter coordinates of cell to modify (row, column): " << endl;
        cin >> y1;
        cin >> x1;
        x1--;
        y1--;

        cout << "What would you like this cell to be?" << endl;
        cout << "1. Wall" << endl << "2. Container" << endl;
        cout << "3. Empty" << endl << "4. Door" << endl;
        cout << "5. Enemy" << endl;
        cin >> type;

        switch (type)
        {
            case 1:
                campaign[current].setCell(x1, y1, 'w');
                break;
            case 2:
                campaign[current].setCell(x1, y1, 'c');
                break;
            case 3:
                campaign[current].setCell(x1, y1, 'n');
                break;
            case 4:
                for (unsigned int i = 0; i < pos; i++)
                    cout << i+1 << ". " << campaign[i].getName() << endl;
                cout << "Select a map to link to: ";
                cin >> map;
                campaign[map-1].print();
                cout << "Enter the coordinates the door should link to: ";
                cin >> x2;
                cin >> y2;
                x2--;
                y2--;
                campaign[map-1].setCell(x2, y2, campaign[current].getName(), x1, x2);
                campaign[current].setCell(x1, y1, campaign[map-1].getName(), x2, y2);
                break;
            case 5:
                campaign[current].setCell(x1, y1, 'e');
                break;
            default:
                break;
        }
        cout << "Current Map: " << endl;
        campaign[current].print();

        cout << "Continue editing map? (y/n): ";
        cin >> end;
        if ((end == 'n') || (end == 'N'))
        {
            if (campaign[current].verify())
                break;
            else
            {
                cout << "This map does not have a valid exit" << endl;
                cout << "Are you sure you want to exit? (y/n): ";
                cin >> end;
                if ((end == 'y') || (end == 'Y')) break;
            }
        }
    } while (1);
    saveMap();
}

// SAVE MAP TO FILE
void Campaign::saveMap() const
{
    string target;
    target = campaign[current].getName();
    target += ".txt";

    ofstream active;
    active.open(target);

    active << campaign[current].getName() << '\n';

    active << campaign[current].getLength() << ' ';
    active << campaign[current].getWidth() << '\n';

    for (unsigned int i = 0; i < campaign[current].getLength(); i++)
        for (unsigned int j = 0; j < campaign[current].getWidth(); j++)
        {
            active << campaign[current].getCell(j, i).getType();
            switch (campaign[current].getCell(j, i).getType())
            {
                case 'n':
                    active << '\n';
                    break;
                case 'd':
                    active << ' ' << campaign[current].getCell(j, i).getDoor()->getLink();
                    active << ' ' << campaign[current].getCell(j, i).getDoor()->getX();
                    active << ' ' << campaign[current].getCell(j, i).getDoor()->getY();
                    active << '\n';
                    break;
                case 'c':
                    active << '\n';
                    break;
                case 'e':
                    active << '\n';
                    break;
                case 'w':
                    active << '\n';
                    break;
                default:
                    break;
            }
        }
    cout << "Map saved to " << target << endl;
    active.close();
}

// ADDS EXISTING MAP
void Campaign::addMap(Map & loaded)
{
    campaign[pos] = loaded;
    pos++;
}

// ACCESS MAP
Map Campaign::getMap(int x) const
{
    return campaign[x];
}

// ACCESS LAST MAP
int Campaign::getPos() const
{
    return pos;
}

// LIST MAPS
void Campaign::print() const
{
    unsigned int i = 0;
    for (; i < pos; i++)
        cout << i << ". " << campaign[i].getName() << endl;
    cout << i << ". New Map" << endl;
}