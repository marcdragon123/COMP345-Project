/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DiceTestClass.cpp
 * Author: marc
 *
 * Created on 21-Oct-2016, 11:13:14 AM
 */

#include "DiceTestClass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(DiceTestClass);

void DiceTestClass::setUp() {
    
    aDice = new Dice20();
    
}

void DiceTestClass::tearDown() {
    
    delete(aDice);
    
}

void DiceTestClass::testDiceRoll() {
   
    aDice->Roll();
    if(aDice->getCurrentRoll() > 20 || aDice->getCurrentRoll() < 1 )
    {
        CPPUNIT_ASSERT(false);
    }
    else
    {
        CPPUNIT_ASSERT(true);
    }
}

