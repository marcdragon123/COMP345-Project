#pragma once
/* 
 * File:   Subject.h
 * Author: Marc-Andre Dragon 
 *
 * Created on November 28, 2016, 3:38 PM. All Rights reserved
 */

#include "main.h"
#include "mainclasses.h"
#include "Logger.h"
#include "Observer.h"
#include "Enum.h"

#ifndef SUBJECT_H
#define SUBJECT_H
class Subject
{
public:
    inline Subject(){aLog = nullptr; aObservers =  new list<ConcreteObserver*>();}
    inline Subject(Logger* pLog){aLog = pLog; aObservers = new list <ConcreteObserver*>();}
    virtual void Attach(ConcreteObserver* pObserver)=0;
    virtual void Detach(ConcreteObserver* pObserver)=0;
    virtual void Notify()=0;
    inline void SetState(string pState){aState = pState;}
    inline string GetState(){return aState;}
    inline list<ConcreteObserver*>* getObservers(){return aObservers;}    
    virtual ~Subject(){delete(aLog);delete(aObservers);}
    inline void setNormal(){enState = Updated;}
    inline void setBattle(){enState = Battle;}
    inline void setEvent(){enState = Event;}
    inline State getState(){return enState;}
private:
    Logger* aLog;
    list<ConcreteObserver*>* aObservers;
    string aState;
    State enState = Updated;
};

class ConcreteSubject : public Subject
{
public:
    inline ConcreteSubject():Subject(){}
    inline ConcreteSubject(Logger* pLog):Subject(pLog){}
    void Attach(ConcreteObserver* pObserver) override;
    void Detach(ConcreteObserver* pObserver) override;
    void Notify() override;
};
#endif /* SUBJECT_H */