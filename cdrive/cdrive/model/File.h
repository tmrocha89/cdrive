/**
 *
 *  @file File.h
 *
 *  @brief This classe will be a super classe.
 *  There should be another 2 classes, one for
 *  files stored remotely
 *
 *  @author TmRocha
 */

#ifndef __cdrive__File__
#define __cdrive__File__

#include <iostream>
namespace cdrive{
class File{
    
private:
    // ToDo: add more attributes
    std::string name;
    std::string filePath;

    
public:
    
    File(std::string name, std::string fpath);
    ~File();
    
    std::string getFileName() const;
    
};
}

#endif /* defined(__cdrive__File__) */
