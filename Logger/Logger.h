#pragma once
/* 
 * File:   Logger.h
 * Author: Marc-Andre Dragon 
 *
 * Created on November 23, 2016, 8:56 AM. All Rights reserved
 */
 
#include "main.h"
#include "mainclasses.h"
#ifndef LOGGER_H
#define LOGGER_H
class Logger
{   
public :
    int Log(string pString);
    void openRead(string pFile);
    void open(string pfile);
    void close();
    Logger();
    ~Logger();
    list<string>* Read(string pRead);
    list<string> ReadAll(string pRead);
    string ReadFirst(string pRead);
    string ReadLast(string pRead);
private:
    fstream aLog;    
};

inline Logger::Logger()
{
}

inline Logger::~Logger()
{
}
#endif /*LOGGER_H*/ 

