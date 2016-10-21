/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DiceTest.h
 * Author: marc
 *
 * Created on 21-Oct-2016, 2:07:38 AM
 */

#ifndef DICETEST_H
#define DICETEST_H

#include <cppunit/extensions/HelperMacros.h>

class DiceTest : public CPPUNIT::TestFixture {
    CPPUNIT_TEST_SUITE(DiceTest);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    DiceTest();
    virtual ~DiceTest();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif /* DICETEST_H */

