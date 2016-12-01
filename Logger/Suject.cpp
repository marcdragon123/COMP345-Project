/* 
 * File:   Suject.cpp
 * Author: Marc-Andre Dragon 
 *
 * Created on November 28, 2016, 4:28 PM. All Rights reserved to Marc-Andre Dragon 
 */

#include "main.h"
#include "mainclasses.h"
#include "Subject.h"

void ConcreteSubject::Notify()
{
    for (_List_iterator<ConcreteObserver*> index = this->getObservers()->begin(); index!= this->getObservers()->end(); advance(index,1))
    {  
        ConcreteObserver* index1 = index.operator *() ;
        index1->Update(this->GetState(),this->getState());
    }
}

void ConcreteSubject::Attach(ConcreteObserver* pObserver) {
    this->getObservers()->insert(this->getObservers()->cend(), pObserver);
}

void ConcreteSubject::Detach(ConcreteObserver* pObserver) {
    this->getObservers()->remove(pObserver);
}

