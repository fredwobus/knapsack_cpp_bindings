import pyknapsack
import numpy as np


if __name__ == "__main__":
    W = 40
    profit = [60, 90, 120, 80]
    weight = np.array([10, 20, 30, 15])
    print(f"profit: {profit}")
    print(f"weight: {weight}")
    print(f"Max value that can be put into the knapsack of size {W}:")
    res = pyknapsack.knapSack(W, weight, profit)
    print(f"{res}")
