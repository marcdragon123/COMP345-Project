#ifndef Builder_h
#define Builder_h

#include <iostream>
#include <fstream>
#include "Campaign.h"
#include "Map.h"

class Builder
{

protected:
    Map * map;
    Character * character;
public:
    Map * getMap() {return map;}
    Character * getCharacter() {return character;}
    virtual void buildMap(string, Campaign*) = 0;
    virtual void buildMap(string, Character, Campaign*) = 0;
    void buildCharacter(string);
};

class EditBuilder : public Builder
{

public:
    void buildMap(string, Campaign*);
    void buildMap(string, Character, Campaign*) {}
};

class PlayBuilder : public Builder
{

public:
    void buildMap(string, Campaign*) {}
    void buildMap(string, Character, Campaign*);
};

class CharacterBuilder : public Builder
{
    
public:
    void buildMap(string, Campaign*) {}
    void buildMap(string, Character, Campaign*) {}
    void buildCharacter(string);
};
#endif /* Builder_h */