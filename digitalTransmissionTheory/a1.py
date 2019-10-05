from util import ShannonEntropy
from os import system
import numpy as np

system("clear")
p = np.array([0.04, 0.04, 0.06, 0.06, 0.1, 0.1, 0.2, 0.4])
H = ShannonEntropy(p)
print(f"Shannon Entropy: {H:.4} bits")
