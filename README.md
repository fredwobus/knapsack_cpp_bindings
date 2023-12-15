# knapsack_cpp_bindings
> Demonstration of python/C++ bindings (based on `pybind11`) using a naive knapsack solver as an example.

<!-- TOC -->
* [knapsack_cpp_bindings](#knapsackcppbindings)
  * [1. Software prerequisites](#1-software-prerequisites)
    * [1.1 Prerequisite installation on Ubuntu](#11-prerequisite-installation-on-ubuntu)
    * [1.2 Prerequisite installation on MacOS](#12-prerequisite-installation-on-macos)
  * [2. Installation of the pyknapsack Python package in a virtual environment](#2-installation-of-the-pyknapsack-python-package-in-a-virtual-environment)
  * [3. Run the python example](#3-run-the-python-example)
  * [4. Building/testing the native C++ knapsack code (for developers)](#4-buildingtesting-the-native-c-knapsack-code-for-developers)
    * [4.1 The native C++ code](#41-the-native-c-code)
    * [4.1 Compile the C++ library and C++/Python bindings](#41-compile-the-c-library-and-cpython-bindings)
    * [4.2 Run C++-native example](#42-run-c-native-example)
  * [5. The Python bindings built with `pybind11`](#5-the-python-bindings-built-with-pybind11)
<!-- TOC -->


## 1. Software prerequisites

### 1.1 Prerequisite installation on Ubuntu

Install python, compilers and cmake:
```shell
sudo apt-get update
sudo apt install python3.11 python3.11-dev build-essential cmake 
```

### 1.2 Prerequisite installation on MacOS

Python should already be installed on your Mac:
> The Apple-provided build of Python is installed in `/System/Library/Frameworks/Python.framework` and `/usr/bin/python`, respectively.

check if you have a compiler:
> Open the Terminal application: hit `Command+Space` and type "terminal"; select "Terminal" from the drop down. In the terminal window that pops up, type g++. If you do not have the necessary compiler files installed, you will be prompted to install Mac's Command Line Tools. Install those and you should be all set.

and for cmake:
> To install CMake, simply type `brew install cmake` in the terminal. Once you have installed CMake, type `cmake` in your terminal to check if it's installed.

## 2. Installation of the pyknapsack Python package in a virtual environment

```shell
python3.11 -m venv ~/venv/knapsack_cpp_bindings
source ~/venv/knapsack_cpp_bindings/bin/activate
pip install numpy
python setup.py install
```

## 3. Run the python example

```shell
source ~/venv/knapsack_cpp_bindings/bin/activate
python3 run_pyknapsack.py
```


## 4. Building/testing the native C++ knapsack code (for developers)

### 4.1 The native C++ code

The `knapsack` library consists of 
- `knapsack.cpp` - *C++ code of the knapsack library*
- `knapsack.hpp` - *C++ header file for the knapsack library*

This code is compiled into a static library, and can be manually linked to a C++ executable. When the python extension is compiled this code is statically linked into the dynamic library that is loaded by python.

and there is also some example code with a `main()` function that imports and runs the code for testing:
- `run_knapsack.cpp` - the example code that calls the library's solver with some sample input

### 4.1 Compile the C++ library and C++/Python bindings

The build step (cmake + make) is usually done by `setup.py` inside a `build` subdirectory if the code is compiled as part of the installation 
of the python package, but the code can be compiled manually if the native C++ needs be debugged/tested 
without any python wrapper.  

```shell
cmake .
make
```

These steps compile the following:
- `libknapsack.a` - *the static library*
- `run_knapsack` - *example executable which calls the knapsack solver with some sample input* 

### 4.2 Run C++-native example

This executable uses the `libknapsack.a` static library natively from C++:

```shell
./run_knapsack
```

## 5. The Python bindings built with `pybind11`

The code for the `pybind11`-style python bindings is in this C++ source file:
 - `pyknapsack.cpp`

See https://pybind11.readthedocs.io/en/stable/reference.html 
for more information on the workings of `pybind11`.

This code in `pyknapsack.cpp` does the following:
 - the `PYBIND11_MODULE` macro defines the entry point that will be invoked when the Python interpreter imports an extension module.
 - the function `py_knapSack()` provides the '*glue*' between the python call and the C++ function. The python datatypes (lists, numpy arrays) are converted to C++ data types and passed to the native C++ function. The output is received and passed back to the calling python code.   

This C++ file needs to be modified whenever the function interface of the C++ library changes. 
