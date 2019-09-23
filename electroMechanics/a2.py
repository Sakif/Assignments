import os
from scipy.constants import mu_0

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

lbl = " A2Q6 "
print(f"{lbl:#^80}")
mmf1 = 4000  # A
mmf2 = mmf1
mu_r = 2000
lengthGap = 2e-3  # m

mainArea = 20e-3 * 20e-3  # m^2
print(f"main area: {mainArea:.3e} m^2")

lengthMain = 20 + 35 + 10 + 65  # horizontal mm
lengthMain += 40 + 20  # vertical mm
lengthMain *= 2 * 1e-3  # convert to m and account for top,bottom left,right
print(f"length of main part: {lengthMain} m")

areaRib = 10e-3 * 20e-3  # m^2
print(f"rib area: {areaRib:.3e} m^2")

lengthRib = 40e-3 + 20e-3 - lengthGap  # m
print(f"rib length: {lengthRib:.3e} m")

reluctanceMain = lengthMain
reluctanceMain /= mu_r * mu_0 * mainArea
print(f"reluctance main: {reluctanceMain:.4} H^-1")

reluctanceRib = lengthRib
reluctanceRib /= mu_r * mu_0 * areaRib
print(f"reluctance rib: {reluctanceRib:.4} H^-1")

reluctanceGap = lengthGap
reluctanceGap /= mu_0 * areaRib
print(f"reluctance gap: {reluctanceGap:.4} H^-1")
