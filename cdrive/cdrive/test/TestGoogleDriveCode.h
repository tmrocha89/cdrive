#ifndef __cdrive__TestGoogleDriveCode__
#define __cdrive__TestGoogleDriveCode__

#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include <regex>
#include "GoogleDriveCode.h"

class TestGoogleDriveCode : public CppUnit::TestFixture{
    
    
public:
    TestGoogleDriveCode();
    ~TestGoogleDriveCode();
    
    void setUp();
    void tearDown();
    
private:
    std::string jsonText;
    
    CPPUNIT_TEST_SUITE(TestGoogleDriveCode);
    CPPUNIT_TEST(testGetCodeUrl);
    CPPUNIT_TEST(testRequestCredential);
    CPPUNIT_TEST_SUITE_END();
    
    void testGetCodeUrl();
    void testRequestCredential();

};

CPPUNIT_TEST_SUITE_REGISTRATION(TestGoogleDriveCode);

#endif /* defined(__cdrive__TestGoogleDriveCode__) */
