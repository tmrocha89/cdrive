#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <string.h>
#include "GoogleDriveCode.h"


#ifdef DEBUG
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <stdexcept>
#endif

const std::string URL_GOOGLE = "https://www.googleapis.com/drive/v2";
const std::string CLIENT_ID = "1033063813595-jjl34819c76cd5jll6hg52kvq9qr4tf2.apps.googleusercontent.com";
const std::string CLIENT_KEY = "6VA4krRe6qj4waIz6HMbzbyV";
const std::string AUTH_URI = "https://accounts.google.com/o/oauth2/auth";
const std::string TOKEN_URI = "https://accounts.google.com/o/oauth2/token";

/**
 Write description of function here.
 The function should follow these comments.
 Use of "brief" tag is optional. (no point to it)
 
 The function arguments listed with "param" will be compared
 to the declaration and verified.
 
 @param[in]     ptr Description of first function argument.
 @param[out]    size Description of second function argument.
 @param[in,out] nmemb Description of third function argument.
 @return Description of returned value.
 */
/*
size_t getUrlCode(void *ptr, size_t size, size_t nmemb, void *userdata){
    std::string url ((char*)ptr);
    size_t s = url.find("Location");
    if(s != std::string::npos){
        url.erase(0, strlen("Location: "));
        std::cout << url << std::endl;
    }
    return size * nmemb;
}
*/

/**
 * @file main.cpp
 * Esta e' a minha descricao deste ficheiro
 */
int main(int argc, const char * argv[]) {
    
#ifdef DEBUG
    CPPUNIT_NS::TestResult controller;
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);
    
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);
    
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);
    
    CPPUNIT_NS::CompilerOutputter output(&result, std::cerr);
    output.write();
#endif
    
  //  std::ostringstream postStream;
 //  postStream << "scope=email profile https://www.googleapis.com/auth/drive&redirect_uri=urn:ietf:wg:oauth:2.0:oob&response_type=code&client_id=" << CLIENT_ID;
 //   std::string postFields = postStream.str();
    
    try {
        GoogleDriveCode gdc;
        std::string url(gdc.getCodeUrl());
        
        std::string code;
        std::cout << "Please, enter the code:";
        std::cin >> code;
        
        Credential credential(gdc.requestTokens(code));
    } catch (int ex) {
        std::cerr << ex << std::endl;
    }
    
    
    
    
  //  CURL* curl;
  //  CURLcode resCode;
 
    
 //   curl = curl_easy_init();
 //   if(curl){
        /*
         * 'Launch' google popup
         */
   //     curl_easy_setopt(curl, CURLOPT_URL, AUTH_URI.c_str());
   //     curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str() );
   //    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
   //     curl_easy_setopt(curl, CURLOPT_HEADER, 1);
   //     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getUrlCode);
   //     resCode = curl_easy_perform(curl);
   //     curl_easy_cleanup(curl);
        
        
   //     curl = NULL;
   //     if (!(curl = curl_easy_init())) {
   //         std::cerr << "Nao foi possivel" << std::endl;
   //         exit(1);
   //     }
        /*
         * Read Code from user
         */
    //    std::string code;
    //    std::cout << "Please, enter the code:";
    //    std::cin >> code;
        
        /*
         * Get Tokens
         */
     //   std::ostringstream postStreamTokens;
        
     //   postStreamTokens << "client_id=" << CLIENT_ID << "&client_secret=" << CLIENT_KEY << "&redirect_uri=urn:ietf:wg:oauth:2.0:oob&grant_type=authorization_code&code=" << code;
        
     //   std::string postFiledsToken = postStreamTokens.str();
      //  std::cout << "codigo a utilizar: " << postFiledsToken << std::endl;
      //  curl_easy_setopt(curl, CURLOPT_URL, TOKEN_URI.c_str());
      //  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFiledsToken.c_str());
      //  resCode = curl_easy_perform(curl);
      //  std::cout << resCode << std::endl;
        
     //  curl_easy_cleanup(curl);
        
//    }else
//        std::cout << "opps" << std::endl;
    
    return 0;
}
