
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



PYBIND11_MODULE(_mymod, m) {

    // Classes
    py::class_<Calculator>(m, "Calculator")
        .def(py::init<std::string>())
        .def("add", py::overload_cast<const std::int64_t, const std::int64_t>(&Calculator::add))
        .def("add", py::overload_cast<const std::vector<int64_t>&>(&Calculator::add))
        //https://github.com/pybind/pybind11/blob/3414c56b6c7c521d868c9a137ca2ace2e26b5b2e/tests/test_sequences_and_iterators.cpp#L536C5-L543C8
        .def("add_iter", [](Calculator& self, py::iterator& iter) -> int64_t {
            // convert py:iterator to std::vector<int64_t>::iterator and call self.add(iter)
            int64_t sum = 0;
            for (auto item: iter){
                sum += item.cast<int64_t>();
            }
            return sum;
        })
        ; // only semicolon here

}

