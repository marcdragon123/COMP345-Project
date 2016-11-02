#include "Cell.h"

/////////////////////////////////////
/////// TYPE MEMBER FUNCTIONS ///////
/////////////////////////////////////

Type::Type()
{
    obj = 'n';
    blocked = false;
} //End default constructor

Type::Type(char in)
{
    if (in == 'w') blocked = true;
    else blocked = false;

    obj = in;
} //End Constructor

Type::Type(string in, int a, int b)
{
    door = new Door(in, a, b);
    blocked = false;

    obj = 'd';
}

char Type::getObj() const { return obj; }
Door * Type::getDoor() const { return door; }
bool Type::isBlocked() const { return blocked; }

/////////////////////////////////////
/////// DOOR MEMBER FUNCTIONS ///////
/////////////////////////////////////

Door::Door()
{
    link = "";
    x = 0;
    y = 0;
}

Door::Door(string name, int a, int b)
{
    link = name;
    x = a;
    y = b;
}

void Door::setLink(string name, int inx, int iny)
{
    link = name;
    x = inx;
    y = iny;
}

string Door::getLink() const { return link; }
int Door::getX() const { return x; }
int Door::getY() const { return y; }

/////////////////////////////////////
/////// CELL MEMBER FUNCTIONS ///////
/////////////////////////////////////

Cell::Cell()
{
    flagged = false;
} // End default constructor

Cell::Cell(Type in)
{
    flagged = false;
    type = in;
} // End constructor

bool Cell::isFlagged() const { return flagged; }
bool Cell::isBlocked() const { return type.isBlocked(); }

void Cell::flag() { flagged = true; }
void Cell::unFlag() { flagged = false; }

void Cell::setType(char in) { type = Type(in); } // End function setType
void Cell::setType(string name, int x, int y)
{
    type = Type(name, x, y);
}
void Cell::removeType() { type = NULL; } // End function removeType

char Cell::getType() const { return type.getObj(); }
Door * Cell::getDoor() const
{
    if (type.getObj() == 'd')
        return type.getDoor();
    else
        return new Door;
}