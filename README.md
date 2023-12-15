# knapsack_cpp_bindings
> Demonstration of python/C++ bindings (based on `pybind11`) using a naive knapsack solver as an example.

<!-- TOC -->
* [knapsack_cpp_bindings](#knapsackcppbindings)
  * [1. Installation - Building the bindings and pyknapsack package (developers)](#1-installation---building-the-bindings-and-pyknapsack-package-developers)
    * [1.1 Prerequisites](#11-prerequisites)
    * [1.2 Create Python virtual environment (for developers)](#12-create-python-virtual-environment-for-developers)
    * [1.3 Compile the C++ library and C++/Python bindings](#13-compile-the-c-library-and-cpython-bindings)
    * [1.4 Run the python example (in the developer virtual env)](#14-run-the-python-example-in-the-developer-virtual-env)
    * [1.5. Run C++-native example](#15-run-c-native-example)
  * [2. Installation - Using the pyknapsack package (users)](#2-installation---using-the-pyknapsack-package-users)
    * [2.1 Create Python virtual environment (for users)](#21-create-python-virtual-environment-for-users)
    * [2.2 Run the python example (in the user virtual env)](#22-run-the-python-example-in-the-user-virtual-env)
<!-- TOC -->

## 1. Installation - Building the bindings and pyknapsack package (developers)

### 1.1 Prerequisites

Install **cmake**:
```shell
sudo apt install cmake
```

### 1.2 Create Python virtual environment (for developers)

```shell
python3.11 -m venv ~/venv/knapsack_cpp_bindings
source ~/venv/knapsack_cpp_bindings/bin/activate
pip install -r requirements.txt
```

### 1.3 Compile the C++ library and C++/Python bindings

```shell
cmake .
make
python3 setup.py install
```

### 1.4 Run the python example (in the developer virtual env)

```shell
source ~/venv/knapsack_cpp_bindings/bin/activate
python3 run_pyknapsack.py
```



### 1.5. Run C++-native example

This executable uses the `libknapsack.a` static library natively from C++:

```shell
./run_knapsack
```

## 2. Installation - Using the pyknapsack package (users)

Once the bindings have been compiled, they can be installed to a virtual environment that's suited to users of the pyknapsack package.

### 2.1 Create Python virtual environment (for users)

```shell
python3.11 -m venv ~/venv/pyknapsack
source ~/venv/pyknapsack/bin/activate
pip install numpy
python setup.py install
```

### 2.2 Run the python example (in the user virtual env)

```shell
source ~/venv/pyknapsack/bin/activate
python3 run_pyknapsack.py
```

