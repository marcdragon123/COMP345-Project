/* 
 * File:   Contrete Observee.cpp
 * Author: Marc-Andre Dragon 
 *
 * Created on November 6, 2016, 9:50 AM. All Rights reserved to Marc-Andre Dragon 
 */

#include "Observer.h"


bool ConcreteObserver::equals(ConcreteObserver* pObserver){
  if (this->getID() == pObserver->getID()) ? true : false;
};

ConcreteObserver::Update(){
    enStatus aState = this->getObserverState();
    //This is temporary until combined with the map
    switch (aState)
    {
        case PositionChanged:
            cout << "Map is being updated due to " << aState;
            break;
        case EnenmyKilled:
            cout << "Map is being updated due to " << aState;
            break;
        case NoUpdate:
            cout << "Map is being updated due to " << aState;
            break;
        case DoorUsed:
            cout << "Map is being updated due to " << aState;
            break;
        case ChestOpened:
            cout << "Map is being updated due to " << aState;
            break;
    }
}   


