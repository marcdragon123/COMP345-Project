#include "Strategy.h"
#include "Character.h"

Strategy::Strategy()
{
    dice = new Dice();
}

void HumanPlayerStrategy::move(int x, int y, Character *me)
{
    me->setCharX(x);
    me->setCharY(y);
    cout << "Character moved to " << x << ", " << y << endl;
}
void AggressorStrategy::move(int x, int y, Character *me)
{
    me->setCharX(x);
    me->setCharY(y);
    cout << "Character moved to " << x << ", " << y << endl;
}
void FriendlyStrategy::move(int x, int y, Character *me)
{
    me->setCharX(x);
    me->setCharY(y);
    cout << "Character moved to " << x << ", " << y << endl;  
}

void HumanPlayerStrategy::attack(Character *me, Character *them)
{
    for (unsigned int atk = 0; atk < me->getAtkNum(); atk++)
    {
        int attackroll = dice->roll(1, 20);
        int damageroll = 0;
        attackroll += me->getStrAttackBonus();
    
        if (attackroll >= them->getStat(6))
        {
            damageroll = dice->roll(1,6);
            int strBonus = -5;
            for (unsigned int i = 1; i < me->getStat(0); i += 2)
                strBonus++;
            damageroll += strBonus;
            them->hit(damageroll);
            cout << "You hit " << them->getName() << "for " << damageroll << " damage!" << endl;
            if (them->getType() == 'f')
                them->setType('e');
        }
        else cout << "Attack roll of " << attackroll << " missed!" << endl;
    }
}
void AggressorStrategy::attack(Character *me, Character *them)
{
        for (unsigned int atk = 0; atk < me->getAtkNum(); atk++)
        {
        int attackroll = dice->roll(1, 20);
        int damageroll = 0;
        attackroll += me->getStrAttackBonus();
    
        if (attackroll >= them->getStat(6))
        {
            damageroll = dice->roll(1,6);
            int strBonus = -5;
            for (unsigned int i = 1; i < me->getStat(0); i += 2)
                strBonus++;
            damageroll += strBonus;
            them->hit(damageroll);
            cout << me->getName() << " hit " << them->getName() << "for " << damageroll << " damage!" << endl;
        }
        else cout << "Attack roll of " << attackroll << " missed!" << endl;
    }
}
void FriendlyStrategy::attack(Character *me, Character *them)
{
    
}

void HumanPlayerStrategy::open(Container *it, Character *me)
{
    for(unsigned int visibleItem =0; visibleItem < it->getSize(); visibleItem++)
    {
        Item thething = it->getItem(visibleItem);
        cout << visibleItem +1 << ". " << thething.printItem(); 
    }
    
}
void AggressorStrategy::open(Container *it, Character *me)
{
    
}
void FriendlyStrategy::open(Container *it, Character *me)
{
    
}