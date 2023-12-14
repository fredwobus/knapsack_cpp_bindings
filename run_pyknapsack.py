import pyknapsack


if __name__ == "__main__":
    res = pyknapsack.knapSack(4, [60, 90, 120, 80], [10, 20, 30, 15], 50)
    print(f"knapSack result: {res}")
