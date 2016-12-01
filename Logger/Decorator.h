#pragma once
/* 
 * File:   Decorator.h
 * Author: Marc-Andre Dragon 
 *
 * Created on November 30, 2016, 11:41 AM. All Rights reserved
 */
#include "main.h"
#include "mainclasses.h"
#include "Logger.h"

#ifndef DECORATOR_H
#define DECORATOR_H
class Decorator
{
public:
    Decorator();
    virtual ~Decorator();
    void LogBattle(string pEvents);
    void LogEvents(string pEvents);
private:
    Logger* aLog;
};

#endif /* DECORATOR_H */

inline Decorator::Decorator()
{
    aLog = new Logger();
}

inline Decorator::~Decorator()
{
    delete(aLog);
}
