/**
 * @file TestCredential.h
 *
 * @brief This class test the json parse
 * and test the the getting of correct data
 *
 * @author TmRocha
 *
 */

#ifndef __cdrive__TestCredential__
#define __cdrive__TestCredential__

#include <iostream>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class TestCredential : public CppUnit::TestFixture{
    
    
public:
    TestCredential();
    ~TestCredential();
    
    void setUp();
    void tearDown();

private:
    std::string jsonText;
    
    CPPUNIT_TEST_SUITE(TestCredential);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testGetToken);
    CPPUNIT_TEST(testGetRefreshToken);
    CPPUNIT_TEST(testGetTokenID);
    CPPUNIT_TEST(testEqualObjects);
    CPPUNIT_TEST_SUITE_END();
    
    void testConstructor();
    void testGetToken();
    void testGetRefreshToken();
    void testGetTokenID();
    void testEqualObjects();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestCredential);


#endif /* defined(__cdrive__TestCredential__) */
