# Pybind11 Starter Template

This project has two goals:
1. Debugging Python and C++ binding issues: This project is kept minimal to compile-test-iterate quickly. 
2. A starter template for python and C++ combo using pybind11. Correctly setting them is complicated and takes time, especially if you are new. This project is meant to serve as a starter, so we can start by fork/copy -ing this repo.

## Requirements

> All these are installed automatically (see Build section).

Under the hood, we have these:

* cmake -- C++ builder
* skbuild -- builder for python which also invokes cmake
* pybind11 -- glue layer between C++ and Python


## Organization

* C++: source code is in `src/` directory. See `CMakeLists.txt` for how it is built
  * `libmymod` -- native lib
  * `mymod` -- an executable binary 
* Python: 
  * `_mymod` package is created by pybind11. See pybind.cpp and CMakeLists.txt. 
  * `mymod` package, located under `python/mymod`. Meant to wrap `_mymod` and offers flexibility for including pure python utils in the wheel package



## Build 

```bash
pip install -v .

# Example for customizing CMAKE_ARGS; here use g++-9
CMAKE_ARGS="-DCMAKE_CXX_COMPILER=g++-9" pip install -v .
```

## Test

```bash
# pip install pytest  # if pytest is missing
pytest -vs python/tests
```


# Credits 
This template is extracted out of [Pymarian](https://github.com/marian-nmt/marian-dev/pull/1013) 
