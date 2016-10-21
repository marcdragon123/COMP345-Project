/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DiceTest.cpp
 * Author: marc
 *
 * Created on 21-Oct-2016, 2:07:38 AM
 */

#include "DiceTest.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "Dice.h"
using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION(DiceTest);

DiceTest::DiceTest() {
}

DiceTest::~DiceTest() {
}

void DiceTest::setUp() {
}

void DiceTest::tearDown() {
}

void DiceTest::testMethod() {
    CPPUNIT_ASSERT(true);
}

void DiceTest::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}

