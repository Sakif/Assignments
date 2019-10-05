import numpy as np


def ShannonEntropy(p=[1]):
    s = np.sum(p)
    if (s != 1):
        print("Probability does not sum to 1.")
        pass
    else:
        H = 0
        for i in p:
            H += i * np.log2(i)
        return -H
