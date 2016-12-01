/* 
 * File:   Logger.cpp
 * Author: Marc-Andre Dragon 
 *
 * Created on November 23, 2016, 9:42 AM. All Rights reserved to Marc-Andre Dragon 
 */
#include <string.h>
#include <memory>

#include "Logger.h"

using namespace std;

int Logger::Log(string pString)
{
    if(aLog.is_open())
    {
        using namespace std;
        time_t time = std::time(nullptr);
        string now = ctime(&time);
        aLog << pString << std::endl;
        aLog << now << std::endl;
    }
    return 0;
}

void Logger::open(string pfile)
{
    if (!aLog.is_open())
    {
        aLog = fstream(pfile, ios_base::out|ios_base::app);
    }
}

void Logger::openRead(string pFile)
{
    if(!aLog.is_open())
    {
        aLog = fstream(pFile,ios_base::in);
    }
}

void Logger::close()
{
    if (aLog.is_open())
    {
        aLog.close();
    }
}

list<string>* Logger::Read(string pRead)
{
    shared_ptr<list<string>> strings (new list<string>());
    
    
    if(aLog.is_open())
    {
        string line;
        while(getline(aLog,line))
        {
            if(line.find(pRead)!=string::npos)
            {
                strings.get()->insert(strings.get()->cend(),line);
            }
        }
    }
    
    list<string>* p1 = strings.get();
    
    strings.reset();
    
    return p1;
}

list<string> Logger::ReadAll(string pRead) {
    list<string>* strings = this -> Read(pRead);
    list<string> strings1 = *strings;
    return strings1;
}

string Logger::ReadFirst(string pRead) {
    list<string> strings = *(this -> Read(pRead));
     return strings.front();
}

string Logger::ReadLast(string pRead) {
    list<string> strings = *(this -> Read(pRead));
    return strings.back();
}


