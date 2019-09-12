import scipy.constants as const

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
reluctance1 /= relativePermeability * const.mu_0 * area1
print(f"Reluctance 1: {reluctance1:.4} H^-1")

lenght2 = 30 * 3 + 15 * 2 + 10
lenght2 *= 1e-2
area2 = 15 * 10
area2 *= pow(1e-2, 2)
reluctance2 = lenght2
reluctance2 /= relativePermeability * const.mu_0 * area2
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
reluctanceCore /= relativePermeability * const.mu_0 * areaCore
print(f"Core reluctance: {reluctanceCore:.4} H^-1")

reluctanceGap = lengthGap
reluctanceGap /= const.mu_0 * areaGap
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
reluctanceStator /= relativePermeability * const.mu_0 * area
print(f"Reluctance stator: {reluctanceStator:.4} H^-1")

reluctanceRotor = lengthRotor
reluctanceRotor /= relativePermeability * const.mu_0 * area
print(f"Reluctance rotor: {reluctanceRotor:.4} H^-1")

reluctanceGap = lengthGap
reluctanceGap /= const.mu_0 * areaGap
print(f"Reluctance gap: {reluctanceGap:.4} H^-1")

eqReluctance = reluctanceRotor + reluctanceStator + 2 * reluctanceGap
print(f"Equivalent reluctance: {eqReluctance:.4} H^-1")

mmf = turns * current
fluxDensity = mmf / eqReluctance
print(f"Flux density: {fluxDensity:.4} Wb")
