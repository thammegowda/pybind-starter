#include<string>
#include<iostream>
#include<vector>

namespace mymod {
 



// convert py:iterator to std::vector<T>::iterator
template <typename T>
class Iterator: public std::vector<T>::iterator {
    
    protected:
        T current_;

    public:
        T operator*() const {
            std::cout << "*: dereference \n";
            return current_;
        }

        Iterator<T> operator++();

};


 class Calculator{

    private: 
        std::string _owner;   // some state

    public:
    Calculator(): _owner("UNKNOWN"){}
    Calculator(std::string owner): _owner(owner){}

    auto add(const int64_t a, const int64_t b) -> int64_t{
        return a + b;
    }

    auto add(const std::vector<int64_t>& arr) -> int64_t{
        /**
         * An example to recieve a list and return the sum of all elements
        */
        int64_t sum = 0;
        for(auto it : arr){
            sum += it;
        }
        return sum;
    }

    auto add(Iterator<int64_t>& iter) -> int64_t{
        /**
         * An example to receive an iterator and return the sum of all elements
        */
        int64_t sum = 0;
        for(auto it = iter; it != iter; ++it){
            sum += *it;
        }
        
        return sum;
    }
 };
}
