#ifndef __cdrive__WebDriver__
#define __cdrive__WebDriver__

#include <iostream>
#include "File.h"
#include "Credential.h"

class WebDriver{
    
private:
    Credential credential;
    
public:
    WebDriver(const Credential& );
    ~WebDriver();
    
    cdrive::File* getFile();
    
    
};


#endif /* defined(__cdrive__WebDriver__) */
