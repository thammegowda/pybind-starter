#include<string>
#include<iostream>
#include<iterator>
#include<vector>
#include<memory>

namespace mymod {



    // this is java like iterator: no operator overloading, no pointers
    template <typename T>
    class Iterator {
    public:
        virtual bool has_next() = 0;
        virtual T next() = 0;
    };

    // this is c++ iterator with operator overloading
    class FibIter {
    private:
        int64_t _n;
        int64_t _a = 0;
        int64_t _b = 1;
    public:
        FibIter(int64_t n) : _n(n) {}
        // copy and move
        FibIter(const FibIter&) = default;
        FibIter(FibIter&&) = default;

        bool operator==(const FibIter& other) {
            return _n == other._n;  // used for comparing the end
        }

        int64_t operator*() {
            return _a;
        }

        FibIter* operator++() {
            if (_n > 0) {
                int64_t c = _a + _b;
                _a = _b;
                _b = c;
                _n--;
            }
            return this;
        }
    };



    class Calculator {

    private:
        std::string _owner;   // some state

    public:
        Calculator() : _owner("UNKNOWN") {}
        Calculator(std::string owner) : _owner(owner) {}

        auto add(const int64_t a, const int64_t b) -> int64_t {
            return a + b;
        }

        auto add(const std::vector<int64_t>& arr) -> int64_t {
            /**
             * An example to recieve a list and return the sum of all elements
            */
            int64_t sum = 0;
            for (auto it : arr) {
                sum += it;
            }
            return sum;
        }

        auto add(Iterator<int64_t>& iter) -> int64_t {
            /**
             * An example to receive an iterator and return the sum of all elements
            */
            int64_t sum = 0;
            while (iter.has_next()) {
                sum += iter.next();
            }
            return sum;
        }

        std::pair<FibIter, FibIter> fibonacci(int64_t n) {
            /**
             * An example to return an iterator: returns a pair: iterator and sentinel
            */
            return std::pair<FibIter, FibIter>(FibIter(n), FibIter(0));
        }
    };
}
