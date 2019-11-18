from os import system
import numpy as np

system("clear")

lbl = " A4Q1 "
print(f"{lbl:#^80}")
lbl = "- a -"
print(f"{lbl:^80}")
freq = 50  # Hz
phase = 6
sMagField = 120 * freq / phase
print(f"speed of magnetic field without slip: {sMagField} rpm")

lbl = "- b -"
print(f"{lbl:^80}")
slip = 3.5e-2
n_m = (1 - slip) * sMagField
print(f"speed of magnetic field with slip: {n_m} rpm")

lbl = "- c -"
print(f"{lbl:^80}")
slipSpeed = slip * sMagField
print(f"Slip speed: {slipSpeed} rpm")

lbl = "- d -"
print(f"{lbl:^80}")
rotorFreq = slipSpeed * phase / 120
print(f"Rotor frequency: {rotorFreq} rpm")

lbl = " A4Q2 "
print(f"\n{lbl:#^80}")
power = 50e3  # W
voltage = 460  # V
frequency = 50  # Hz
poles = 2
slip = 5e-2
lossFrictionWindage = 700  # W
lossCore = 600  # W

lbl = "- a -"
print(f"{lbl:^80}")
sMagField = 120 * freq / poles
n_m = (1 - slip) * sMagField
print(f"Shaft speed: {n_m:.4} rpm")

lbl = "- b -"
print(f"{lbl:^80}")
print(f"Output power: {power*1e-3} kW")

lbl = "- c -"
print(f"{lbl:^80}")
loadTroque = power / n_m
loadTroque /= 2 * np.pi / 60
print(f"Load torque: {loadTroque:.4} N m")

lbl = "- d -"
print(f"{lbl:^80}")
convPower = power + lossCore + lossFrictionWindage
print(f"power conv: {convPower*1e-3:.4} kW")
inducedTorque = convPower / n_m
inducedTorque /= 2 * np.pi / 60
print(f"Induced torque: {inducedTorque:.4} N m")

lbl = "- e -"
print(f"{lbl:^80}")
rotorFreq = slip * frequency
print(f"rotor frequency: {rotorFreq} Hz")
