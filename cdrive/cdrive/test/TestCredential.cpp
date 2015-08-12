#include "TestCredential.h"
#include "Credential.h"

TestCredential::TestCredential(){}

TestCredential::~TestCredential(){}

void TestCredential::setUp(){
    jsonText  = "{\"access_token\" : \"ya29.ywFKZHlOuJI2YhtvuX-VGX88gi3JDbf6QIiP53qAndUvO1yMkWaAGmxLPSIyK_F9cA43\",\"token_type\" : \"Bearer\",\"expires_in\" : 3600,\"id_token\" : \"eyJhbGciOiJSUzI1NiIsImtpZCI6IjAxNDEzNzUxMDMxYzNlODZmZGUzNDBiZjk3NDkzOTMxYTI5NzY4MTAifQ.eyJpc3MiOiJhY2NvdW50cy5nb29nbGUuY29tIiwiYXRfaGFzaCI6Ii1yS2dSbFVrNk9uMG4xQ1FzSU85M2ciLCJhdWQiOiIxMDMzMDYzODEzNTk1LWpqbDM0ODE5Yzc2Y2Q1amxsNmhnNTJrdnE5cXI0dGYyLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwic3ViIjoiMTA0NDEyMDg2OTc0Mjg1Njc5Mjk4IiwiZW1haWxfdmVyaWZpZWQiOnRydWUsImF6cCI6IjEwMzMwNjM4MTM1OTUtampsMzQ4MTljNzZjZDVqbGw2aGc1Mmt2cTlxcjR0ZjIuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJlbWFpbCI6InRtcm9jaGE4OUBnbWFpbC5jb20iLCJpYXQiOjE0MzkxNjg5MTcsImV4cCI6MTQzOTE3MjUxN30.cFacYR_XpUiGBB63NZx8VI6qvjei6fjdcxsJe6n_YA3YZH-rG55Tumm2xRB7Ro7ohX9YFocVdMcp7sdXdqC_OrItxDH5gNe6yJmwJkt5VYY3EKaNX-ts5Me7cA7f4t7_ZGQsTh0cuwxfcizAOItfGbgpx530Tr5aQO2Etw5AOiQ3END-7dp9yZ-K_QLNPs4EhCpZlykspdjxcHflOUrb8mJa5RDjWOIJXjlnV4Vh3BWyYgfrIbLAnHXJshyI_ImWl0Lo_JnoUPdDyTi2t5D6X_vAZH8cPAmpcqwDxlxStXfvn6rHcuChaY4tolSbDCRBcyVaJ1xbXhIaHggVy93orQ\",\"refresh_token\" : \"1/F8irUyVsEbu-JQH734NdhunZHPtRWHwNVH38XWlVVEs\"}";
}


void TestCredential::tearDown(){
    
}


void TestCredential::testConstructor(){
    
    Credential credential(jsonText);
}

void TestCredential::testConstructorCopy(){
    
    Credential c1(jsonText);
    Credential c2(c1);
    
    CPPUNIT_ASSERT_EQUAL(true, c1==c2);
}

void TestCredential::testGetToken(){
    std::string expRes = "ya29.ywFKZHlOuJI2YhtvuX-VGX88gi3JDbf6QIiP53qAndUvO1yMkWaAGmxLPSIyK_F9cA43";
    Credential c(jsonText);
    CPPUNIT_ASSERT_EQUAL(0, expRes.compare(c.getToken()));
}

void TestCredential::testGetRefreshToken(){
    std::string expRes = "1/F8irUyVsEbu-JQH734NdhunZHPtRWHwNVH38XWlVVEs";
    Credential c(jsonText);
    CPPUNIT_ASSERT_EQUAL(0, expRes.compare(c.getRefreshToken()));
}

void TestCredential::testGetTokenID(){
    std::string expRes = "eyJhbGciOiJSUzI1NiIsImtpZCI6IjAxNDEzNzUxMDMxYzNlODZmZGUzNDBiZjk3NDkzOTMxYTI5NzY4MTAifQ.eyJpc3MiOiJhY2NvdW50cy5nb29nbGUuY29tIiwiYXRfaGFzaCI6Ii1yS2dSbFVrNk9uMG4xQ1FzSU85M2ciLCJhdWQiOiIxMDMzMDYzODEzNTk1LWpqbDM0ODE5Yzc2Y2Q1amxsNmhnNTJrdnE5cXI0dGYyLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwic3ViIjoiMTA0NDEyMDg2OTc0Mjg1Njc5Mjk4IiwiZW1haWxfdmVyaWZpZWQiOnRydWUsImF6cCI6IjEwMzMwNjM4MTM1OTUtampsMzQ4MTljNzZjZDVqbGw2aGc1Mmt2cTlxcjR0ZjIuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJlbWFpbCI6InRtcm9jaGE4OUBnbWFpbC5jb20iLCJpYXQiOjE0MzkxNjg5MTcsImV4cCI6MTQzOTE3MjUxN30.cFacYR_XpUiGBB63NZx8VI6qvjei6fjdcxsJe6n_YA3YZH-rG55Tumm2xRB7Ro7ohX9YFocVdMcp7sdXdqC_OrItxDH5gNe6yJmwJkt5VYY3EKaNX-ts5Me7cA7f4t7_ZGQsTh0cuwxfcizAOItfGbgpx530Tr5aQO2Etw5AOiQ3END-7dp9yZ-K_QLNPs4EhCpZlykspdjxcHflOUrb8mJa5RDjWOIJXjlnV4Vh3BWyYgfrIbLAnHXJshyI_ImWl0Lo_JnoUPdDyTi2t5D6X_vAZH8cPAmpcqwDxlxStXfvn6rHcuChaY4tolSbDCRBcyVaJ1xbXhIaHggVy93orQ";
    Credential c(jsonText);
    CPPUNIT_ASSERT_EQUAL(0, expRes.compare(c.getTokenID()));
}

void TestCredential::testEqualObjects(){
    Credential expected(jsonText);
    
    Credential result("ya29.ywFKZHlOuJI2YhtvuX-VGX88gi3JDbf6QIiP53qAndUvO1yMkWaAGmxLPSIyK_F9cA43",
                      "Bearer", "3600",
                      "eyJhbGciOiJSUzI1NiIsImtpZCI6IjAxNDEzNzUxMDMxYzNlODZmZGUzNDBiZjk3NDkzOTMxYTI5NzY4MTAifQ.eyJpc3MiOiJhY2NvdW50cy5nb29nbGUuY29tIiwiYXRfaGFzaCI6Ii1yS2dSbFVrNk9uMG4xQ1FzSU85M2ciLCJhdWQiOiIxMDMzMDYzODEzNTk1LWpqbDM0ODE5Yzc2Y2Q1amxsNmhnNTJrdnE5cXI0dGYyLmFwcHMuZ29vZ2xldXNlcmNvbnRlbnQuY29tIiwic3ViIjoiMTA0NDEyMDg2OTc0Mjg1Njc5Mjk4IiwiZW1haWxfdmVyaWZpZWQiOnRydWUsImF6cCI6IjEwMzMwNjM4MTM1OTUtampsMzQ4MTljNzZjZDVqbGw2aGc1Mmt2cTlxcjR0ZjIuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJlbWFpbCI6InRtcm9jaGE4OUBnbWFpbC5jb20iLCJpYXQiOjE0MzkxNjg5MTcsImV4cCI6MTQzOTE3MjUxN30.cFacYR_XpUiGBB63NZx8VI6qvjei6fjdcxsJe6n_YA3YZH-rG55Tumm2xRB7Ro7ohX9YFocVdMcp7sdXdqC_OrItxDH5gNe6yJmwJkt5VYY3EKaNX-ts5Me7cA7f4t7_ZGQsTh0cuwxfcizAOItfGbgpx530Tr5aQO2Etw5AOiQ3END-7dp9yZ-K_QLNPs4EhCpZlykspdjxcHflOUrb8mJa5RDjWOIJXjlnV4Vh3BWyYgfrIbLAnHXJshyI_ImWl0Lo_JnoUPdDyTi2t5D6X_vAZH8cPAmpcqwDxlxStXfvn6rHcuChaY4tolSbDCRBcyVaJ1xbXhIaHggVy93orQ",
                      "1/F8irUyVsEbu-JQH734NdhunZHPtRWHwNVH38XWlVVEs");
    
    CPPUNIT_ASSERT_ASSERTION_PASS(expected==result);
    
}


