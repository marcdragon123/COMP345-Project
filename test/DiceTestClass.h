/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DiceTestClass.h
 * Author: marc
 *
 * Created on 21-Oct-2016, 11:13:13 AM
 */

#ifndef DICETESTCLASS_H
#define DICETESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../Dice.h"

class DiceTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(DiceTestClass);
        CPPUNIT_TEST(testDiceRoll);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

private:
    Dice* aDice;
    void testDiceRoll();
};

#endif /* DICETESTCLASS_H */

