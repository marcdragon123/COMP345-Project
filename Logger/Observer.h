#pragma once
/* 
 * File:   Observer.h
 * Author: Marc-Andre Dragon 
 *
 * Created on November 28, 2016, 3:15 PM. All Rights reserved
 */

#include "main.h"
#include "mainclasses.h"
#include "Logger.h"
#include "Enum.h"

#ifndef OBSERVER_H
#define OBSERVER_H
class Observer
{
public:
    virtual void Update(string pState, State pEnState)=0;
    inline Observer(){aLogObserver = new Logger();}
    virtual ~Observer(){delete(aLogObserver);}
    inline Logger* getLogger(){return aLogObserver;}
private:
    Logger* aLogObserver;
};

class ConcreteObserver : public Observer
{
public:
    void Update(string pState, State pEnState) override;
    ConcreteObserver():Observer(){}
    void openEvent();
    void openBattle();
};
#endif /* OBSERVER_H */