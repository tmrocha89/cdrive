#ifndef __cdrive__WebDriver__
#define __cdrive__WebDriver__

#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include "File.h"
#include "Credential.h"

class WebDriver{
    
private:
    Credential credential;
    
public:
    WebDriver(const Credential& );
    ~WebDriver();
    
    void listFiles();
    
    
};


#endif /* defined(__cdrive__WebDriver__) */
