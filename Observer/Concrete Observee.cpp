/* 
 * File:   Concrete Observee.cpp
 * Author: Marc-Andre Dragon 
 *
 * Created on November 6, 2016, 9:50 AM. All Rights reserved to Marc-Andre Dragon 
 */

#include "Observer.h"

Observee::Observee()
{
    aMap = nullptr;
};

Observee::Observee(Map* pMap)
{
    aMap = &pMap;
};

ConcreteObservee::getState(){
    return aSubjectStatus;
};

ConcreteObservee::setState(enStatus aState){
    aSubjectStatus = aState;
};

ConcreteObservee::Attach(Observer* pObserver){
    this->getObserver().insert(this->getObserver().back(), pObserver);
}

ConcreteObservee::Detach(Observer* pObserver){
    for(Observer* fObserver : this->getObserver())
    {
        if(fObserver.equals(pObserver))
        {
            this->getObserver().remove(pObserver);
        }
    }
};

ConcreteObservee::Notify(){
    for(Observer* fObserver : this->getObserver())
    {
        fObserver->Update();   
    }
}