#include "File.h"

using namespace cdrive;

File::File(std::string name, std::string filePath){
    File::name = name;
    File::filePath = filePath;
}

File::~File(){}


std::string File::getFileName()const{
    return name;
}