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
print(f"Rotor frequency: {rotorFreq} Hz")

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

system("clear")
lbl = " A4Q3 "
print(f"{lbl:#^80}")
inputV = 440  # V
power = 50
phase = 3
pole = 6
frequency = 60
R2 = 0.12
R1 = 0.1
Gc = 6.2e-3  # S
Xtot = 0.75j
Bm = 0.07  # S


def phasor(c):
    mag = np.abs(c)
    ang = np.angle(c, deg=True)
    return f"{mag:.4}\u2220{ang:.4}\u00B0"


lbl = "- a -"
print(f"{lbl:^80}")
current2p = inputV / np.sqrt(3)
current2p /= (R1 + R2 / 0.03) + Xtot
print(f"I2': {phasor(current2p)}")

Rc = 1 / Gc
print(f"core resistance: {Rc:.4} ohm")
Xm = 1 / Bm
Xm *= 1j
print(f"middle impedence: {Xm:.4} ohm")
Vi = inputV / np.sqrt(3)
Io = Vi / Rc + Vi / Xm
print(f"Io: {phasor(Io)}")
lineI = Io + current2p
print(f"line current: {phasor(lineI)} A")
powerFactor = np.cos(np.angle(lineI))
print(f"Power factor: {powerFactor:.4}")

lbl = "- b -"
print(f"{lbl:^80}")
Pcore = 3 * pow(Vi, 2) / Rc
print(f"Power: {Pcore*1e-3:.4} kW")

Pin = 3 * Vi * np.abs(lineI) * powerFactor
print(f"Pin: {Pin*1e-3:.4} kW")

Pc = 3 * inputV * np.abs(current2p) * powerFactor
print(f"P: {Pc:.4} W")
