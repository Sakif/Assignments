from os import system
from scipy.constants import mu_0
import numpy as np

title = " Lecture 2 Page 5 "
print(f"{title:#^80}")

turns = 200
relativePermeability = 2500
current = 1
lenght1 = 30 + 15
lenght1 *= 1e-2
area1 = 10 * 10
area1 *= pow(1e-2, 2)
reluctance1 = lenght1
reluctance1 /= relativePermeability * mu_0 * area1
print(f"Reluctance 1: {reluctance1:.4} H^-1")

lenght2 = 30 * 3 + 15 * 2 + 10
lenght2 *= 1e-2
area2 = 15 * 10
area2 *= pow(1e-2, 2)
reluctance2 = lenght2
reluctance2 /= relativePermeability * mu_0 * area2
print(f"Reluctance 2: {reluctance2:.4} H^-1")

eqReluctance = reluctance1 + reluctance2
print(f"Equivalent reluctance: {eqReluctance:.4} H^-1")

mmf = turns * current
print(f"mmf: {mmf} A")

flux = mmf / eqReluctance
print(f"flux: {flux:.3e} Wb\n")

title = " Lecture 2 Page 7 "
print(f"{title:#^80}")

turns = 400
lenghtCore = 40e-2
lengthGap = 0.05e-2
areaCore = 12 * pow(1e-2, 2)
areaGap = areaCore * 1.05
relativePermeability = 4000
flux = 0.5

reluctanceCore = lenghtCore
reluctanceCore /= relativePermeability * mu_0 * areaCore
print(f"Core reluctance: {reluctanceCore:.4} H^-1")

reluctanceGap = lengthGap
reluctanceGap /= mu_0 * areaGap
print(f"Gap reluctance: {reluctanceGap:.4} H^-1")

eqReluctance = reluctanceCore + reluctanceGap
print(f"Equivalent reluctance: {eqReluctance:.4} H^-1")

current = flux * areaGap * eqReluctance
current /= turns
print(f"Current: {current:.4} A\n")

title = " Lecture 2 Page 9 "
print(f"{title:#^80}")

lengthStator = 50e-2
area = 12 * pow(1e-2, 2)
lengthRotor = 5e-2
lengthGap = 0.05e-2
areaGap = 14 * pow(1e-2, 2)
relativePermeability = 2000
turns = 200
current = 1

reluctanceStator = lengthStator
reluctanceStator /= relativePermeability * mu_0 * area
print(f"Reluctance stator: {reluctanceStator:.4} H^-1")

reluctanceRotor = lengthRotor
reluctanceRotor /= relativePermeability * mu_0 * area
print(f"Reluctance rotor: {reluctanceRotor:.4} H^-1")

reluctanceGap = lengthGap
reluctanceGap /= mu_0 * areaGap
print(f"Reluctance gap: {reluctanceGap:.4} H^-1")

eqReluctance = reluctanceRotor + reluctanceStator + 2 * reluctanceGap
print(f"Equivalent reluctance: {eqReluctance:.4} H^-1")

mmf = turns * current
fluxDensity = mmf / eqReluctance
print(f"Flux density: {fluxDensity:.4} Wb")

system("clear")
lbl = " Note 7 Page 2 "
print(f"{lbl:#^80}")

motorVoltage = 230  # V
armatureResistance = 0.2  # Ohm
armatureCurrent = 205  # A
backEmf = motorVoltage - armatureCurrent * armatureResistance
print(f"Back emf: {backEmf:.4} V")
powerArmature = backEmf * armatureCurrent
print(f"net power: {powerArmature*1e-3:.4} kW")
rotation = 1750  # rpm
rotationLoss = 1445  # W
outputPower = powerArmature - rotationLoss
print(f"Output power: {outputPower*1e-3:.4} kW")
torque = outputPower
torque /= 2 * np.pi / 60
torque /= rotation
print(f"torque: {torque:.4} N m")

lbl = " Note 7 Page 4 "
print(f"{lbl:#^80}")
motorPower = 5  # hp
motorVoltage = 240  # V
resistance = 0.6  # Ohm
power = 10 * 745.7  # W
Ia = pow(motorVoltage, 2) - power * 4 * resistance
Ia = motorVoltage - np.sqrt(Ia)
Ia /= 2 * resistance
print(f"Armeture Current: {Ia:.4} A")

Iam = motorVoltage
Iam /= 2 * resistance
print(f"Current in armature: {Iam:.4} A")

Pam = pow(motorVoltage, 2)
Pam /= 4 * resistance
print(f"p_am: {Pam:.4} W")
