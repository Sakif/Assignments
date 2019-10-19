import os
from scipy.constants import mu_0
import numpy as np

os.system("clear")

lbl = " A1Q1 "
print(f"{lbl:#^80}")

lbl = " a "
print(f"{lbl:=^80}")

length = 2  # m
velocity = 60  # km h^-1
velocity /= 3.6  # m s^-1
print(f"velocity: {velocity:.4} m s^-1")
fluxDensity = 0.6  # T
emf = length * velocity * fluxDensity
print(f"emf: {emf:.4} V")

lbl = " b "
print(f"{lbl:=^80}")

turns = 200
iFlux = 3e-3  # Wb
fFlux = 1.2e-3  # Wb
time = 0.2  # s
emf = -turns * (fFlux - iFlux)
emf /= time
print(f"emf: {emf:.4} V")

lbl = " A1Q2 "
print(f"\n{lbl:#^80}")

lbl = " a "
print(f"{lbl:=^80}")
B = [0.2, 0.6, 0.7]
H = [500, 3000, 5000]
mu = []
for i in range(len(B)):
    mu.append(B[i] / H[i])
for m in mu:
    print(f"mu: {m:.3e}")
    mu_r = m / mu_0
    print(f"mu_r: {mu_r:.4}\n")

lbl = " a "
print(f"{lbl:=^80}")
fluxDensity = 0.6  # T
length = 8e-3  # m
mmf = fluxDensity * length
mmf /= mu_0
print(f"mmf: {mmf:.4} ")

lbl = " b "
print(f"{lbl:=^80}")

lbl = " A1Q3 "
print(f"{lbl:#^80}")
momentOfInertia = 4
torque = 6
t = 5

angularAcceleration = torque / momentOfInertia
print(f"α: {angularAcceleration:.4} rad s^-2")

angularVelocity = angularAcceleration * t
print(f"ω: {angularVelocity:.4} rad s^-1")
angularVelocity *= 60  # s to min
angularVelocity /= 2 * np.pi  # rad to rev
print(f"ω: {angularVelocity:.4} rpm")

lbl = " A1Q5 "
print(f"\n{lbl:#^80}")
radius = 25e-2  # m
area = 3 * pow(1 / 100, 2)  # cm^2
turns = 600
current = 1.5  # A
rPermability = 1500

lbl = " a "
print(f"{lbl:=^80}")
meanLength = 2 * np.pi * radius
print(f"mean length: {meanLength:.4} m")
reluctance = meanLength
reluctance /= rPermability * mu_0 * area
print(f"reluctance: {reluctance:.4} H^-1")

lbl = " b "
print(f"{lbl:=^80}")
mmf = turns * current
print(f"mmf: {mmf:.4} A")
fieldIntensity = mmf / meanLength
print(f"magnetic field intensity: {fieldIntensity:.4} A m^-1")

lbl = " c "
print(f"{lbl:=^80}")
flux = mmf / reluctance
print(f"flux: {flux:.3e} Wb")
fluxDensity = flux / area
print(f"flux density: {fluxDensity:.4} T")

lbl = " A1Q6 "
print(f"\n{lbl:#^80}")
turn1 = 600
turn2 = 200
current1 = 0.5  # A
current2 = 1  # A
rPermability = 1200
depth = 15e-2  # m
width = 15e-2  # m
area = depth * width
innerL = 50e-2  # m
print(f"area: {area:.4} m^2")
meanLength = (innerL + width) * 4
print(f"length: {meanLength:.4} m")
reluctance = meanLength
reluctance /= rPermability * mu_0 * area
print(f"reluctance: {reluctance:.4} H^-1")
mmf1 = current1 * turn1
print(f"mmf1: {mmf1} A")
mmf2 = current2 * turn2
print(f"mmf2: {mmf2} A")
mmf = mmf1 + mmf2
print(f"mmf: {mmf} A")
flux = mmf / reluctance
print(f"flux: {flux:.3e} Wb")

lbl = " A1Q7 "
print(f"\n{lbl:#^80}")
rPermability = 10000
thickness = 2e-2  # m
turns = 400
current1 = 1.0  # A
current2 = 1.2  # A
H = 2e-2  # m
V = 3e-2  # m
gapLength = 0.2e-2  # m
height = 10e-2  # m
width = 14e-2  # m

areaH = thickness * H
print(f"area left,right: {areaH:.3e} m^2")

areaV = thickness * V
print(f"area up,down: {areaV:.3e} m^2")

lengthH = (width - V) * 2 - gapLength
print(f"left,right length: {lengthH:.4} m")

lengthV = (height - H) * 2
print(f"up,down length: {lengthV:.4} m")

reluctanceH = lengthH
reluctanceH /= rPermability * mu_0 * areaH
print(f"reluctance left,right: {reluctanceH:.4} H^-1")

reluctanceV = lengthV
reluctanceV /= rPermability * mu_0 * areaV
print(f"reluctance up,down: {reluctanceV:.4} H^-1")

reluctanceGap = gapLength
reluctanceGap /= mu_0 * areaH
print(f"gap reluctance: {reluctanceGap:.4} H^-1")

reluctance = reluctanceH + reluctanceV + reluctanceGap
print(f"reluctance: {reluctance:.4} H^-1")

mmf1 = turns * current1
print(f"mmf1: {mmf1} A")

mmf2 = turns * current2
print(f"mmf2: {mmf2} A")

mmf = mmf1 + mmf2
print(f"mmf: {mmf} A")

flux = mmf / reluctance
print(f"flux: {flux:.3e} Wb")
