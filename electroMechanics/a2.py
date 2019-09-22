import os

os.system("clear")

lbl = " A2Q1 "
print(f"{lbl:#^80}")

flux = 50e-6  # Wb
area = 1e-2 * 1e-2  # m^2
lengthC = (8e-2 - 0.5e-2) * 2 + 4e-2 - 1e-2  # m
print(f"length of C: {lengthC:.4} m")
lengthI = 4e-2
lengthGap = 0.5e-3
fluxDensity = flux / area
print(f"flux density: {fluxDensity:.4} T")
fieldIntensity = 350  # H

lbl = " A2Q1 "
print(f"{lbl:#^80}")
rotorDiameter = 18e-2  # m
rotorAxialLength = 10e-2  # m
poleAxialLength = 10e-2  # m
poleCircumferentialWidth = 8.5e-2  # m
poleHeight = 9e-2  # m
statorYokeMeanDiameter = 42e-2  # m
statorYokeCrossSection = 14e-2 * 6e-2  # m
airGapLength = 1.5e-3  # m
