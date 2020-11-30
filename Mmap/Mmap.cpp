#include <algorithm>
#include <iostream>
#include <cstring>
#include "../IO/Timer.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>


const char* mapFile(const char* fileName, int& length)
{
    int fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        std::cout << "Cannot open file!" << std::endl;
        exit(-1);
    }
    // obtain file size
    struct stat statbuffer;
    if (fstat(fd, &statbuffer) == -1) {
        std::cout << "Cannot obtain file size!" << std::endl;
    }

    length = statbuffer.st_size;

    const char* addr = static_cast<const char*>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0u));
    if (addr == MAP_FAILED) {
        std::cout << "Cannot map file!" << std::endl;
    }
    
    //munmap((char*)addr, length);
    
    return addr;
}


int main()
{
    Timer timer;
    int length;
    auto startingPointer = mapFile("../1GB.in", length);
    auto endingPointer = startingPointer + length;

    int lines = 0;
    while (startingPointer && startingPointer!=endingPointer)
        if ((startingPointer = static_cast<const char*>(memchr(startingPointer, '\n', endingPointer-startingPointer)))) {
            lines++;
            startingPointer++;
        }

    std::cout << "Lines: " << lines << std::endl;
}