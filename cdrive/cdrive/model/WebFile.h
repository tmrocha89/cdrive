
/**
 *  @file WebFile
 *
 *  @brief
 *
 *
 */
#ifndef __cdrive__WebFile__
#define __cdrive__WebFile__

#include <iostream>
#include "File.h"

class WebFile : public cdrive::File{
    
private:
    
    
public:
    WebFile(std::string name, std::string filePath);
    ~WebFile();
    
};

#endif /* defined(__cdrive__WebFile__) */
