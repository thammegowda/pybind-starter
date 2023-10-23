#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include "mymod.hpp"

#define PYBIND11_DETAILED_ERROR_MESSAGES

namespace py = pybind11;
using namespace mymod;

PYBIND11_MODULE(_mymod, m) {

    // Classes
    py::class_<Calculator>(m, "Calculator")
        .def(py::init<std::string>())
        .def("add", py::overload_cast<const std::int64_t, const std::int64_t>(&Calculator::add));

}

