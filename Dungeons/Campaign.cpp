#include "Campaign.h"

Campaign::Campaign()
{
    campaign = new Map[64];
}

Campaign::~Campaign()
{
    delete [] campaign;
}

void Campaign::loadMap(int in)
{
    loaded = in;
}

void Campaign::createMap()
{
    int x, y;
    string name;
    cout << "Input map width: ";
    cin >> x;
    cout << "Input map length: ";
    cin >> y;
    campaign[pos] = Map(x, y);
    cout << "Enter map name: ";
    cin >> name;
    campaign[pos].setName(name);
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

void Campaign::editMap()
{
    int x1, y1, x2, y2, type, map;
    char end;
    do
    {
        campaign[loaded].print();
        cout << "Enter coordinates of cell to modify: " << endl;
        cin >> x1;
        cin >> y1;
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
                campaign[loaded].setCell(x1, y1, 'w');
                break;
            case 2:
                campaign[loaded].setCell(x1, y1, 'c');
                break;
            case 3:
                campaign[loaded].setCell(x1, y1, 'n');
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
                campaign[map-1].setCell(x2, y2, campaign[loaded].getName(), x1, x2);
                campaign[loaded].setCell(x1, y1, campaign[map-1].getName(), x2, y2);
                break;
            case 5:
                campaign[loaded].setCell(x1, y1, 'e');
                break;
            default:
                break;
        }
        cout << "Current Map: " << endl;
        campaign[loaded].print();

        cout << "Continue? (y/n): ";
        cin >> end;
        if ((end == 'n') || (end == 'N'))
        {
            if (campaign[loaded].verify())
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
}

int Campaign::getPos() const
{
    return pos;
}

void Campaign::print() const
{
    unsigned int i = 0;
    for (; i < pos; i++)
        cout << i << ". " << campaign[i].getName() << endl;
    cout << i << ". New Map" << endl;
}