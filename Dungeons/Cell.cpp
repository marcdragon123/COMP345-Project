#include "Cell.h"

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
bool Type::isBlocked() const { return blocked; }


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