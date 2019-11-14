# from scipy.constants import mu_0
from os import system

system("clear")

lbl = " A3Q2 "
print(f"{lbl:#^80}")

motorVoltage = 230  # V
nominalCurrent = 62  # A
shuntFieldResistance = 115  # Ω
armatureResistance = 0.15  # Ω

BackEMF = motorVoltage - nominalCurrent * armatureResistance
print(f"Back EMF: {BackEMF:.4} V")
powerArmature = BackEMF * nominalCurrent
print(f"Power supplied to the armature: {powerArmature/1e3:.4} kW")
