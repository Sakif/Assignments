import numpy as np


def parallelImpedance(impedance):
    zEq = 0
    for z in impedance:
        zEq += 1 / z
    return 1 / zEq


def phaserString(z):
    mag = np.abs(z)
    phase = np.angle(z, deg=True)
    return f"{mag:.4}∠{phase:.4}°"


def complexPower(v, i):
    return v * np.conj(i)


def powerFactor(v, i):
    phaseV = np.angle(v)
    phaseI = np.angle(i)
    return np.cos(phaseV - phaseI)


def realPower(v, i):
    return np.abs(v) * np.abs(i) * powerFactor(v, i)
