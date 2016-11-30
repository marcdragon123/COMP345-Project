#include "Map.h"

Map::Map()
{
    width = 10;
    length = 10;
    name = "Empty Map";

    grid = new Cell*[length]();
    for (unsigned int i = 0; i < length; i++)
        grid[i] = new Cell[width];
    done = false;
} // End default constructor

Map::Map(string in, int x, int y)
{
    width = x;
    length = y;
    name = in;

    grid = new Cell*[length]();
    for (unsigned int i = 0; i < length; i++)
        grid[i] = new Cell[width];
    done = false;
}

Map::~Map()
{
//    for (unsigned int i = 0; i < length; i++)
//        delete [] grid[i];
}

Cell Map::getCell(int x, int y) { return grid[x][y]; }
int Map::getWidth() const { return width; }
int Map::getLength() const { return length; }
string Map::getName() const { return name; }

void Map::setName(string in)
{
    name = in;
} // End function setName

void Map::setCell(int x, int y, char c)
{
    grid[x][y].setType(c);
    Notify("Cell Set");
} // End function setCell

void Map::setCell(int x1, int y1, string name, int x2, int y2)
{
    grid[x1][y1].setType(name, x2, y2);
    Notify("Cell Set");
} // Door Set Cell

void Map::setCell(int x, int y, int lvl, string cls, string name)
{
    grid[x][y].setType(lvl, cls, name);
    Notify("Cell Set");
} // Character setCell

void Map::setCell(int x, int y, Character * c)
{
    grid[x][y].setType(c);
}

void Map::clearFlags()
{
    for (unsigned int i = 0; i < length; i++)
        for (unsigned int j = 0; j < width; j++)
            if (grid[i][j].isFlagged()) grid[i][j].unFlag();
} // End function clearFlags

bool Map::checkPath(int x, int y)
{
    if ((grid[x][y].getType() == 'd') && !(grid[x][y].isFlagged()))
        return true;
    else {
        grid[x][y].flag();    // Mark current cell as visited
        if (y + 1 < length)
            if (!(grid[x][y + 1].isFlagged()) && !(grid[x][y + 1].isBlocked()))
                if (checkPath(x, y + 1)) return true;   // Checks Cell above current location
        if (x + 1 < width)
            if (!(grid[x + 1][y].isFlagged()) && !(grid[x + 1][y].isBlocked()))
                if (checkPath(x + 1, y)) return true;   // Checks Cell to right of current location
        if (x - 1 >= 0)
            if (!(grid[x - 1][y].isFlagged()) && !(grid[x - 1][y].isBlocked()))
                if (checkPath(x - 1, y)) return true;   // Checks Cell to left of current location
        if (y - 1 >= 0)
            if (!(grid[x][y - 1].isFlagged()) && !(grid[x][y - 1].isBlocked()))
                if (checkPath(x, y - 1)) return true;   // Checks Cell below current location
    }
    return false;   // If not adjacent Cells are viable (terminates function if reached at root Cell)
} // End function checkPath

bool Map::verify()
{
    for (unsigned int i = 0; i < width; i++)
        for (unsigned int j = 0; j< length; j++)
        {
            clearFlags();
            if (grid[i][j].getType() == 'd')
            {
                grid[i][j].flag();
                if (checkPath(i, j)) return true;
            }
        }
    return false;
} // End function test

int Map::getStartX() const
{
    for (unsigned int i = 0; i < length; i++)
        for (unsigned int j = 0; j < width; j++)
        {
            if (grid[i][j].getDoor()->getLink() == "CAMPAIGN_START")
                return j;
        }
    return 0;
}

int Map::getStartY() const
{
    for (unsigned int i = 0; i < length; i++)
        for (unsigned int j = 0; j < width; j++)
        {
            if (grid[i][j].getDoor()->getLink() == "CAMPAIGN_START")
                return i;
        }
    return 0;
}

void Map::print()
{
    for (int y = length-1; y >= 0; y--)
    {
        for (int i = 0; i < width; i++)
            cout << "--------";
        cout << "-" << endl;
        for (int x = 0; x < width; x++) {
            cout << "|";
            switch (grid[x][y].getType()) {
                case 'n':
                    cout << "       ";
                    break;
                case 'd':
                    cout << "  |-|  ";
                    break;
                case 'c':
                    cout << "  ___  ";
                    break;
                case 'e':
                    cout << "  -E-  ";
                    break;
                case 'w':
                    cout << "|||||||";
                    break;
                case 'p':
                    cout << "  -P-  ";
                    break;
                default:
                    break;
            }
        }
        cout << "|" << endl;
        for (int x = 0; x < width; x++) {
            cout << "|";
            switch (grid[x][y].getType()) {
                case 'n':
                    cout << "       ";
                    break;
                case 'd':
                    cout << "  |D|  ";
                    break;
                case 'c':
                    cout << " | C | ";
                    break;
                case 'e':
                    cout << "  / \\  ";
                    break;
                case 'w':
                    cout << "|||||||";
                    break;
                case 'p':
                    cout << "  / \\  ";
                    break;
                default:
                    break;
            }
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < width; i++)
        cout << "--------";
    cout << "-" << endl;
}//*/

