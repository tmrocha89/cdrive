#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <string.h>
#include "GoogleDriveCode.h"
#include "WebDriver.h"

#ifdef DEBUG
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <stdexcept>
#endif


/**
 * @file main.cpp
 *
 * @brief This is where the magic happens
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
    

    
    try {
        GoogleDriveCode gdc;
        std::string url(gdc.getCodeUrl());
        
        std::cout << "Please, enter in this website and copy and paste the code here.\n"
                    << url << std::endl;
        
        std::string code;
        std::cout << "Please, enter the code:";
        std::cin >> code;
        
        Credential credential(gdc.requestCredential(code));
        WebDriver wd(credential);
        wd.listFiles();
    } catch (int ex) {
        std::cerr << ex << std::endl;
    }
    
    
    return 0;
}
