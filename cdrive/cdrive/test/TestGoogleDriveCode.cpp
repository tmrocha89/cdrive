#include "TestGoogleDriveCode.h"

TestGoogleDriveCode::TestGoogleDriveCode(){}

TestGoogleDriveCode::~TestGoogleDriveCode(){}

void TestGoogleDriveCode::setUp(){}

void TestGoogleDriveCode::tearDown(){
    
}

void TestGoogleDriveCode::testGetCodeUrl(){

    std::regex re ("(https://accounts.google.com/ServiceLogin\\?passive=1209600&continue=https://accounts.google.com/o/oauth2/auth\\?scope%3Demail%2Bprofile%2Bhttps://www.googleapis.com/auth/drive%26response_type%3Dcode%26redirect_uri%3Durn:ietf:wg:oauth:2.0:oob%26client_id%3D1033063813595-jjl34819c76cd5jll6hg52kvq9qr4tf2.apps.googleusercontent.com%26hl%3D)([a-z]){2}-([A-Z]){2}(%26from_login%3D1%26as%3D-)([0-9a-z]+)(&ltmpl=nosignup&oauth=1&sarp=1&scc=1)(\r|\n)*");

    GoogleDriveCode gdc;
    std::string url = gdc.getCodeUrl();
 
    CPPUNIT_ASSERT_EQUAL(true,std::regex_match(url,re,std::regex_constants::match_not_eol));
    
}

void TestGoogleDriveCode::testRequestCredential(){
    /*
    GoogleDriveCode gdc;
    std::string url = gdc.getCodeUrl();
    std::string code;
    std::cout << "Code: ";std::cin >> code;
    Credential credential = gdc.requestCredential(code);
    */
    CPPUNIT_ASSERT_ASSERTION_FAIL(false);
}