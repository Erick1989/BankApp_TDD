#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <sys/stat.h>
#include <string>

bool fileExists(const std::string& filename);

void fileRemove(const char* filename);

#endif
