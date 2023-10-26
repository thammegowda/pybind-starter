
#include<iostream>
#include "mymod.hpp"



// an example of custom iterator
class MyIter: public mymod::Iterator<int64_t>{
    private:
        std::vector<int64_t> _arr;
        int64_t _index;
    public:
        MyIter(std::vector<int64_t> arr)
            : _arr(arr), _index(0) {}
        bool has_next(){
            return _index < _arr.size();
        }

        int64_t next(){
            return _arr[_index++];
        }
};


// add main function with cli args
int main(int argc, char** argv){
    std::cout << "main method called. this is dummy!" << std::endl;
    auto calc = mymod::Calculator("main CLI");
    std::cout << calc.add(1, 2) << std::endl;

    std::vector<int64_t> arr = {1, 2, 3, 4, 5};
    auto iter = MyIter(arr);
    std::cout << "iter sum:" << calc.add(iter) << "\n";

    return 0;
}