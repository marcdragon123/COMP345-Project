/* 
 * File:   Decorator.cpp
 * Author: Marc-Andre Dragon 
 *
 * Created on November 30, 2016, 12:12 PM. All Rights reserved to Marc-Andre Dragon 
 */

#include "Decorator.h"

void Decorator::LogEvents(string pEvents) {
    aLog -> open("Events.log");
    aLog -> Log(pEvents);
    aLog -> close();
}

void Decorator::LogBattle(string pEvents) {
    aLog -> open("Battle.log");
    aLog -> Log(pEvents);
    aLog -> close();
}
