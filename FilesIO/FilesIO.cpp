#include <iostream>
#include <fstream>
#include "../IO/Timer.h"

//reads one 1GB file with ifstream
// to create 1GB file run dd if=/dev/urandom of=file.txt bs=1048576 count=1024
void readFile() {
    std::ifstream input;
    input.open("../1GB.in");
    if(!input) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }
    std::string line;
    int lines = 0;
    while(getline(input, line)) {
        lines++;
    }
    std::cout << "Lines: " << lines << std::endl;
}


int main() {
    Timer timer;
    readFile();

}