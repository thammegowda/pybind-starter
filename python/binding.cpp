
#include <iostream>
#include <vector>
// for vscode, run "python -m pybind11 --includes" and add them in include path
// we need two paths, one for Python.h and other for pybind11
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include <pybind11/stl_bind.h>
#include "pybind11/pytypes.h"
#include "../src/mymod.hpp"

#define PYBIND11_DETAILED_ERROR_MESSAGES

namespace py = pybind11;
using namespace mymod;

// c++ code in mymod.hpp doesnt assume pybind11
// So here we write wrappers; example PyIterator,  

PYBIND11_MODULE(_mymod, m) {

    // Classes
    py::class_<Calculator>(m, "Calculator")
        .def(py::init<std::string>())
        .def("add", py::overload_cast<const std::int64_t, const std::int64_t>(&Calculator::add))
        .def("add", py::overload_cast<const std::vector<int64_t>&>(&Calculator::add))
        // read an iterator from python
        //https://github.com/pybind/pybind11/blob/3414c56b6c7c521d868c9a137ca2ace2e26b5b2e/tests/test_sequences_and_iterators.cpp#L536C5-L543C8
        .def("add_iter", [](Calculator& self, py::iterator& iter) -> int64_t {
            // convert py:iterator to our own iterator and call self.add(iter)
           
            class PyIterator: public Iterator<int64_t>{
                private:
                    py::iterator _iter;
                public:
                    PyIterator(py::iterator iter)
                        : _iter(iter) {}
                    
                    bool has_next(){
                        return _iter != py::iterator::sentinel();
                    }

                    int64_t next(){
                        return (*_iter++).cast<int64_t>();
                    }
            };
                    
            PyIterator pyiter(iter);
            return self.add(pyiter);
        })

        // return an iterator from cpp to python
        .def("fibonacci", [](Calculator& self, int n) {
            std::pair<FibIter, FibIter> cpp_iter = self.fibonacci(n);
            FibIter begin = cpp_iter.first;
            FibIter end = cpp_iter.second;
            // TIP: FibIter::operator=() should return true when arg is "end"
            return py::make_iterator(begin, end);
        })
        ; // only semicolon here at the end

}

