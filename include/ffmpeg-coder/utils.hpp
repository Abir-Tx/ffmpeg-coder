#if !defined(UTILS_H)
#define UTILS_H

#include "rang.hpp"
#include <iostream>


//A function for clearing screen (Cross Platform)
void clear_screen()
{
#ifdef _WIN32
    // do something for windows like include <windows.h>
    system("cls");
#elif defined __unix__
    // do something for unix like include <unistd.h>
    system("clear");
#endif
}

// Function for dynamically decorating a text
void decorateMe(std::string textToDecor){
    using namespace rang;
    int chars = textToDecor.capacity();
    int counter = 0;
    std::cout<<std::endl;
    std::cout<<fg::red;
    for (int i =0 ; i<(chars*2); i++){
        std::cout<<"_";
    }
    std::cout<<fg::reset;
    std::cout<<std::endl;
    std::cout<<fg::blue<<style::bold<<textToDecor<<style::reset<<fg::reset;
    std::cout<<std::endl;
    std::cout<<fg::red;
    for (int i =0 ; i<(chars*2); i++){
        std::cout<<"_";
    }
    std::cout<<fg::reset;
    std::cout<<std::endl;
    std::cout<<std::endl;
    
}

#endif // UTILS_H
