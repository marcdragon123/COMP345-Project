//
//  Interaction.hpp
//  Map
//
//  Created by Garrison Blair on 2016-10-02.
//  Copyright © 2016 Garrison Blair. All rights reserved.
//

#ifndef Interaction_hpp
#define Interaction_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Character;
class Container;

class Interaction {
    string name;
    string description;
    char type;      // A, O, C, D, W
    bool blocks;
    
    Character person;
    Container chest;
    
public:
    Interaction();
    Interaction(char);
    Interaction(Interaction &);
    
    string getName() const;
    string getDescription() const;
    char getType() const;
    bool block();
    Character getCharacter();
    Container getContainer();
    
    void setName(string);
    void setDescription(string);
    void setType(char);
    void setCharacter(Character);
    void setContainer(Container);
};

#endif /* Interaction_hpp */
