#include "Map.h"

Map::Map()
{
    width = 10;
    length = 10;
    startX = 0;
    startY = 0;
    endX = 10;
    endY = 10;
    name = "Empty Map";

    grid = new Cell*[length]();
    for (unsigned int i = 0; i < length; i++)
        grid[i] = new Cell[width];
} // End default constructor

Map::Map(int x, int y)
{
    width = x;
    length = y;
    name = "New Map";

    grid = new Cell*[length]();
    for (unsigned int i = 0; i < length; i++)
        grid[i] = new Cell[width];
}

Cell Map::getCell(int x, int y) { return grid[x][y]; }
int Map::getWidth() const { return width; }
int Map::getLength() const { return length; }

void Map::setStart(int x, int y)
{
    startX = x;
    startY = y;
} // End function getStart
void Map::setEnd(int x, int y)
{
    endX = x;
    endY = y;
} // End function setEnd
void Map::setName(string in)
{
    name = in;
} // End function setName

void Map::setCell(int x, int y, int c)
{
    grid[x][y].setType(c);
} // End function setCell

void Map::clearFlags()
{
    for (unsigned int i = 0; i < length; i++)
        for (unsigned int j = 0; j < width; j++)
            if (grid[i][j].isFlagged()) grid[i][j].unFlag();
} // End function clearFlags

bool Map::checkPath(int x, int y)
{
    grid[x][y].flag();                                  // Mark current cell as visited
    if ((x == endX) && (y == endY)) return true;        // Return true if path reaches end of map
    else {
        if (y + 1 < length)
            if (!(grid[x][y + 1].isFlagged()) && !(grid[x][y + 1].getType().isBlocked()))
                if (checkPath(x, y + 1)) return true;   // Checks Cell above current location
        if (x + 1 < width)
            if (!(grid[x + 1][y].isFlagged()) && !(grid[x + 1][y].getType().isBlocked()))
                if (checkPath(x + 1, y)) return true;   // Checks Cell to right of current location
        if (x - 1 >= 0)
            if (!(grid[x - 1][y].isFlagged()) && !(grid[x - 1][y].getType().isBlocked()))
                if (checkPath(x - 1, y)) return true;   // Checks Cell to left of current location
        if (y - 1 >= 0)
            if (!(grid[x][y - 1].isFlagged()) && !(grid[x][y - 1].getType().isBlocked()))
                if (checkPath(x, y - 1)) return true;   // Checks Cell below current location
    }
    return false;   // If not adjacent Cells are viable (terminates function if reached at root Cell)
} // End function checkPath


bool Map::verify()
{
    clearFlags();
    return checkPath(startX, startY);
} // End function test