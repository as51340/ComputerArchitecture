#include <iostream>
#include "Timer.h"

void withEndl() {
    Timer timer;
    for(int i = 0; i < 100000; i++) {
        std::cout << std::endl;
    }
}

void withoutEndl() {
    Timer timer;
    for(int i = 0; i < 100000; i++) {
        std::cout << "\n";
    }
}

int main() {
    //std::cout << "With endl: " << std::endl;
    //withEndl();
    //std::cout << std::endl;
    std::cout << "Without endl: " << std::endl;
    withoutEndl();
    
}
