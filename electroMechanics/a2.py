from scipy.constants import mu_0
import numpy as np
from os import system
from util import parallelImpedance

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

lbl = " A2Q4 "
print(f"{lbl:#^80}")
mu_r = 2500
mmf = 800
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

rMiddle = lMiddle
rMiddle /= mu_r * mu_0 * area
print(f"reluctance middle: {rMiddle:.4} H^-1")

lLeft = 2 * (60 + 60) + 100 + 100 - 60
lLeft *= 1e-3
print(f"length left: {lLeft:.4} m")

lRight = lLeft + 1e-3
print(f"length right: {lRight:.4} m")

rLeft = lLeft
rLeft /= mu_r * mu_0 * area
print(f"reluctance left: {rLeft:.4} H^-1")

rRight = lRight
rRight /= mu_r * mu_0 * area
print(f"reluctance right: {rRight:.4} H^-1")

rEq = parallelImpedance([rGapLeft + rLeft, rGapRight + rRight])
print(f"reluctance equivalent: {rEq:.4} H^-1")

phi = mmf
phi /= rEq + rMiddle
print(f"phi: {phi:.3e} Wb")
flux = rLeft + rGapLeft
flux /= rRight + rGapRight + rLeft + rGapLeft
flux *= phi
print(f"flux right: {flux:.3e} Wb")

lbl = " A2Q1 "
print(f"{lbl:#^80}")
flux = 50e-6  # Wb
lengthI = 4e-2  # m
lengthGap = 0.5e-3  # m

area = 1e-2 * 1e-2  # m^2
print(f"area: {area} m^2")

lengthC = (8 - 0.5) * 2 + 4 - 1
lengthC *= 1e-2  # m
print(f"length of C: {lengthC:.4} m")

fluxDensity = flux / area
print(f"flux density: {fluxDensity:.4} T")

fieldIntensity = 350  # H
mmf = fieldIntensity
mmf *= lengthC + lengthI
print(f"mmf: {mmf:.4} A")

lbl = " A2Q3 "
print(f"{lbl:#^80}")
fluxDensityI = 0.6  # T
fluxDensityS = 1  # T
mmf = 410  # A
flux = 0.35e-3  # Wb
mu_i = 4e-4
mu_s = 4.348e-3
reluctance = mmf / flux
print(f"reluctance: {reluctance:.4} H^-1")

width1 = flux / fluxDensityI
print(f"width1: {width1:.3e}")

width2 = flux / fluxDensityS
print(f"width2: {width2:.3e}")

t = []
t.append(8 * 3)
t[0] /= mu_i * width1

t.append(2 / mu_i)

t.append(8)
t[-1] /= mu_s * width2

t.append(width1)
t[-1] /= mu_s * width2

roots = [t[1] + t[-1], t[0] + t[2] - reluctance]
d = roots[0] / -roots[1]
print(f"d: {d:.4} m")

lbl = " A2Q2 "
print(f"{lbl:#^80}")
rotorDiameter = 18e-2  # m
rotorAxialLength = 10e-2  # m
poleAxialLength = 10e-2  # m
poleCircumferentialWidth = 8.5e-2  # m
poleHeight = 9e-2  # m
statorYokeMeanDiameter = 42e-2  # m
statorYokeCrossSection = 14e-2 * 6e-2  # m
airGapLength = 1.5e-3  # m
mu_cast = 1500
mu_sheet = 3800

rotorArea = rotorDiameter * rotorAxialLength
poleArea = poleCircumferentialWidth * poleAxialLength

statorReluctance = statorYokeMeanDiameter * np.pi / 4
statorReluctance /= mu_0 * mu_cast * statorYokeCrossSection
print(f"stator reluctance: {statorReluctance:.4} H^-1")

rotorReluctance = rotorDiameter
rotorReluctance /= mu_0 * mu_sheet * (np.pi / 4) * rotorArea
print(f"rotor reluctance: {rotorReluctance:.4} H^-1")

gapReluctance = airGapLength
gapReluctance /= mu_0 * poleArea
print(f"gap reluctance: {gapReluctance:.4} H^-1")

poleReluctance = poleHeight
poleReluctance /= mu_0 * mu_sheet * poleArea
print(f"pole reluctance: {poleReluctance:.4} H^-1")

flux = 0.9 * poleArea
print(f"flux: {flux:.4} Wb")

mmf = poleReluctance + gapReluctance
mmf += rotorReluctance / 4
mmf += statorReluctance / 4
mmf *= flux
print(f"mmf: {mmf:.6} A")

system("clear")
lbl = " A2Q5 "
print(f"{lbl:#^80}")
mu_rotor, mu_stator = 3500, 1800
dOut, dIn = 1, 0.72
rLenght = .7
rWidth = .1
gapLength = 1e-2
axiallength = 1
mmf = 10e3

gapArea = rWidth * axiallength
statorArea = (dOut - dIn) * axiallength

gapReluctance = gapLength
gapReluctance /= mu_0 * gapArea
print(f"gap reluctance: {gapReluctance:.4} H^-1")

meanStatorLength = (dOut + dIn) / 2
meanStatorLength *= np.pi

statorReluctance = meanStatorLength
statorReluctance /= mu_stator * mu_0 * statorArea
print(f"stator reluctance: {statorReluctance:.4} H^-1")

rotorReluctance = rLenght
rotorReluctance /= mu_rotor * mu_0 * gapArea
print(f"rotor reluctance: {rotorReluctance:.4} H^-1")

reluctance = 2 * gapReluctance + rotorReluctance
reluctance += statorReluctance / 2
print(f"reluctance {reluctance:.4} H^-1")

flux = mmf / reluctance
print(f"flux: {flux:.4} Wb")

fluxDensity = flux / gapArea
print(f"B gap: {fluxDensity:.4} T")
