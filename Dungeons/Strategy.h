//////////////////////////////////////////////////////////
/// GAME RULES: Every turn, players can choose to move,///
/// attack enemies in range, or take free actions.     ///
/// similarly, enemies can attack players, and will    ///
/// move towards the player character when they can    ///
/// see them, attacking other NPCs that block their    ///
/// path. Allies will move towards the player if they  ///
/// can see them, and will become hostile if attacked. ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// DESIGN:       The Concrete strategy classes        ///
/// implement 3 functions each. The move function that ///
/// updates characters' location variables, the attack ///
/// that calculates attack rolls, damage rolls, applies///
/// damage, and changes character states if a friendly ///
/// is hit, and the open action that cannot be         ///
/// aimplemented until the container/inventory are     ///
/// finalized.                                         ///
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
/// LIBRARIES USED:                                    ///
/// iostream: As with other sections, important to     ///
///           communicate what is happening, and       ///
///           display the map.                         ///
/// string:   Vital in this case to allow the program  ///
///           to track different NPCs and the player   ///
///           through their name.                      ///
//////////////////////////////////////////////////////////

#ifndef STRATEGY_H
#define STRATEGY_H

#include "Container.h"
#include "Dice.h"

class Character;

class Strategy
{
protected:
    Dice * dice;
public:
    Strategy();

    virtual void move(int, int, Character *) = 0;
    virtual void attack(Character *, Character *) = 0;
    virtual void open(Container *, Character *) = 0;
};

class HumanPlayerStrategy : public Strategy
{
    void move(int, int, Character *);
    void attack(Character *, Character *);
    void open(Container *, Character *);
};

class AggressorStrategy : public Strategy
{
    void move(int, int, Character *);
    void attack(Character *, Character *);
    void open(Container *, Character *);
};

class FriendlyStrategy : public Strategy
{
    void move(int, int, Character *);
    void attack(Character *, Character *);
    void open(Container *, Character *);
};


#endif /* STRATEGY_H */

