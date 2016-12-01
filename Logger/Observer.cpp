/* 
 * File:   Observer.cpp
 * Author: Marc-Andre Dragon 
 *
 * Created on November 28, 2016, 4:28 PM. All Rights reserved to Marc-Andre Dragon 
 */
#include "Observer.h"

void ConcreteObserver::Update(string pState, State pEn) {
    string string1;
    list<string> strings;
    switch(pEn)
    {
        case Battle:
            this->openBattle();
            string1 = this->getLogger()->ReadLast(pState);
            this ->getLogger()->close();
            break;
        case Event:
            this->openEvent();
            string1 = this->getLogger()->ReadLast(pState);
            this ->getLogger()->close();
            break;
        case All:
            if(pState.find("attack")!=string::npos)
            {
                this->openBattle();
                strings = this->getLogger()->ReadAll(pState);
                this->getLogger()->close();
            }
            else
            {
                this->openEvent();
                strings = this->getLogger()->ReadAll(pState);
                this->getLogger()->close();
            }
        case Updated:
            cout<< "Nothing to Update" << std::endl;
            break;
    }
    
    if(strings.empty())
    {
        cout << string1 << std::endl;
    }
    else
    {
       for(_List_iterator<string> index = strings.begin(); index!=strings.end(); index++)
       {
           string thestring = *(index.operator ->());
           cout << thestring << std::endl;
       }
    }
}

void ConcreteObserver::openBattle() {
    this->getLogger()->openRead("Battle.log");
}

void ConcreteObserver::openEvent() {
    this->getLogger()->openRead("Events.log");
}

