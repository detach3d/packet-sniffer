#include <exception>
#include <iostream>
#include "socket_creation.h"


int main() {
    
    try{
        packet_handler();
    }catch(const std::exception& e){
        std::cout << e.what();
    }

    return 0;
}