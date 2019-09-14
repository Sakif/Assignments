import scipy.constants as const
import os

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
print(f"{lbl:#^80}")

lbl = " a "
print(f"{lbl:=^80}")
fluxDensity = 0.6  # T
length = 8e-3  # m
mmf = fluxDensity * length
mmf /= const.mu_0
print(f"mmf: {mmf:.4} ")

lbl = " b "
print(f"{lbl:=^80}")
