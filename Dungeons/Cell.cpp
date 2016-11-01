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

bool Type::isBlocked() const { return blocked; }
char Type::isObj() const {return obj; }


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

void Cell::flag() { flagged = true; }
void Cell::unFlag() { flagged = false; }

void Cell::setType(int in) { type = Type(in); } // End function setType
void Cell::removeType() { type = NULL; } // End function removeType

Type Cell::getType() const { return type; }