#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>  // provides the array_t template
#include "knapsack.hpp"

namespace py = pybind11;

using namespace pybind11::literals;

int py_knapSack(int W, py::array_t<int> wt, py::array_t<int> val, int n) {
    py::buffer_info wt_buf = wt.request();
    py::buffer_info val_buf = val.request();
    auto wt_ptr = static_cast<int *>(wt_buf.ptr);
    auto val_ptr = static_cast<int *>(val_buf.ptr);

    return knapSack(W, wt_ptr, val_ptr, n);
}

PYBIND11_MODULE(pyknapsack, m) {
    m.doc() = "pybind11 knapsack plugin";
    m.def(
            "knapSack", [](int W, py::array_t<int> wt, py::array_t<int>val, int n) {
        return py_knapSack(W, wt, val, n);
    }
    );
}