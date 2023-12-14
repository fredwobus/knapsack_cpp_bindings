# knapsack_cpp_bindings
> python bindings to a knapsack library with a naive knapsack solver as an example


## Compile the C++ library and bindings

```shell
cmake .
make
```

## Create Python virtual environment

```shell
python3.11 -m venv ~/venv/knapsack_cpp_bindings
source ~/venv/knapsack_cpp_bindings/bin/activate
pip install -r requirements.txt
```

## Run the C++-native example

```shell
./run_knapsack
```

## Run the python example
```shell
python3 run_pyknapsack
```

