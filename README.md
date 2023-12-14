# knapsack_cpp_bindings
> python bindings to a knapsack library with a naive knapsack solver as an example


## Create Python virtual environment

```shell
python3.11 -m venv ~/venv/knapsack_cpp_bindings
source ~/venv/knapsack_cpp_bindings/bin/activate
pip install -r requirements.txt
```

## Compile the C++ library and C++/Python bindings

```shell
cmake .
make
python3 setup.py build_ext
```

## Run the C++-native example

```shell
./run_knapsack
```

## Run the python example
```shell
python3 run_pyknapsack
```

