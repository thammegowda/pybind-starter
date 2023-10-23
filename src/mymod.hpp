#include<string>
#include<iostream>

namespace mymod {
 
 class Calculator{

    private: 
        std::string _owner;   // some state

    public:
    Calculator(): _owner("UNKNOWN"){}
    Calculator(std::string owner): _owner(owner){}

    auto add(const int64_t a, const int64_t b) -> int64_t{
        return a + b;
    }
 };
}
