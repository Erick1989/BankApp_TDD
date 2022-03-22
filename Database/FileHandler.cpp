#ifndef FILEHANDLER_CPP
#define FILEHANDLER_CPP

#include "FileHandler.hpp"

bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

void fileRemove(const char* filename){
    if(fileExists(filename)){
        std::remove(filename);
    }
}

#endif