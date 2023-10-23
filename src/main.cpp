
#include<iostream>
#include "mymod.hpp"

// add main function with cli args
int main(int argc, char** argv){
    std::cout << "main method called. this is dummy!" << std::endl;
    auto calc = mymod::Calculator("main CLI");
    std::cout << calc.add(1, 2) << std::endl;
    return 0;
}