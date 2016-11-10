#ifndef OBSERVER_H
#define OBSERVER_H

#pragma once
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Observer.h
 * Author: Marc-Andre Dragon
 *
 * Created on October 31, 2016, 2:22 PM. All Rights reserved
 */

#include "Map.hpp"
#include "main.h"



class Observer
{
public:
    virtual void Update()=0;
    inline Observer(){aObservee = nullptr;}
    inline Observer(Observee* pObservee){aObservee = pObservee;}
    virtual ~Observer();
    virtual bool equals(Observer* pObserver)=0;
    inline int getID(){return aID;}
    void setID(int pID){aID = pID;}
    inline Observee* getObservee(){return aObservee;}
private:
    Observee* aObservee;
    int aID;
};

class Observee
{
public:
    Observee();
    Observee(Map* pMap);
    virtual ~Observee();
    virtual void Attach(Observer* pObserver)=0;
    virtual void Detach(Observer* pObserver)=0;
    virtual void Notify()=0;
    list<Observer*> getObserver(){return aObserver;}
    void setObserver(Observer* pObserver){aObserver = pObserver;}
    
private:
    Map* aMap;
    enStatus aStatus;
    list<Observer*> aObserver;
    //65 Observee's hard coded
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver();
    ~ConcreteObserver();
    enStatus Update() override;
    bool equals(ConcreteObserver* pObserver) override;
    inline enStatus getObserverState(){return aObserverState;}
    inline void setObserverState(enStatus pStatus){aObserverState = pStatus;}
private:
    enStatus aObserverState;
};

inline ConcreteObserver::ConcreteObserver(ConcreteObservee* pObservee)
{
    Observer::Observer(pObservee);
};

class ConcreteObservee : public Observee
{
public:
    ConcreteObservee();
    ConcreteObservee(Map* aMap);
    ~ConcreteObservee();
    enStatus getState();
    inline void setState(enStatus pState){aSubjectStatus = pState;}
    void Attach(ConcreteObserver* aObserver) override;
    void Detach(ConcreteObserver* aObserver)override;
    void Notify() override;
private:
    enStatus aSubjectStatus;
};

inline ConcreteObservee::ConcreteObservee(Map* aMap)
{
    Observee::Observee(aMap);
};

enum enStatus
{
    PositionChanged,
    EnenmyKilled,
    NoUpdate,
    DoorUsed,
    ChestOpened
};

class ObserverThread : public thread
{
public:
    ObserverThread();
    ObserverThread(ConcreteObserver* aOb);
private:
    ConcreteObserver* aObserverObject;
    
};

inline ObserverThread::ObserverThread(ConcreteObserver* aOb)
{
    aObserverObject = &aOb;
}

#endif /*OBSERVER_H */

