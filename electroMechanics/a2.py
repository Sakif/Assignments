from scipy.constants import mu_0
import numpy as np
from os import system

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

lbl = " A2Q6 "
print(f"{lbl:#^80}")
mmf1 = 4000  # A
mmf2 = mmf1
mu_r = 2000
lGap = 2e-3  # m

lLeft = 40 + 20 + 20 + 35 * 2 + 10
lLeft *= 1e-3
print(f"Length left: {lLeft:.4} m")

lRight = 10 + 65 * 2 + 20 + 20 + 40
lRight *= 1e-3
print(f"Length right: {lRight:.4} m")

lMiddle = 40 + 20 - lGap * 1e3
lMiddle *= 1e-3
print(f"Length middle: {lMiddle:.4} m")

aOuter = 20e-3 * 20e-3
print(f"Area outer: {aOuter:.4} m^2")

aMiddle = 20e-3 * 10e-3
print(f"Area middle: {aMiddle:.4} m^2")

rLeft = lLeft
rLeft /= mu_r * mu_0 * aOuter
print(f"Reluctance left: {rLeft:.4} H^-1")

rRight = lRight
rRight /= mu_r * mu_0 * aOuter
print(f"Reluctance right: {rRight:.4} H^-1")

rMiddle = lMiddle
rMiddle /= mu_r * mu_0 * aMiddle
print(f"Reluctance middle: {rMiddle:.4} H^-1")

rGap = lGap
rGap /= mu_0 * aMiddle
print(f"Reluctance gap: {rGap:.4} H^-1")

reluctance = np.array([[rLeft + rGap + rMiddle, -rGap - rMiddle],
                       [-rGap - rMiddle, rRight + rGap + rMiddle]])
print("Reluctance:")
for i in reluctance:
    print(f"[{i[0]:.4}, {i[1]:.4}]")
mmf = np.array([mmf1, mmf2])
flux = np.linalg.solve(reluctance, mmf)
print(f"flux 1: {flux[0]:.4} Wb")
print(f"flux 2: {flux[1]:.4} Wb")

fluxGap = flux[0] - flux[1]
print(f"Flus in gap: {fluxGap:.4} Wb")

system("clear")
lbl = " A2Q4 "
print(f"{lbl:#^80}")
area = 60e-3 * 50e-3
print(f"area: {area:.4} m^2")

lGapLeft = 2e-3
lGapRight = 1e-3
lMiddle = 100 + 100 + 2 - 60
lMiddle *= 1e-3
print(f"length middle: {lMiddle:.4} m")

rGapLeft = lGapLeft
rGapLeft /= mu_0 * area
print(f"reluctance left gap: {rGapLeft:.4} H^-1")

rGapRight = lGapRight
rGapRight /= mu_0 * area
print(f"reluctance right gap: {rGapRight:.4} H^-1")
