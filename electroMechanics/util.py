import numpy as np


def phaserString(z):
    mag = np.absolute(z)
    phase = np.angle(z, deg=True)
    return f"{mag:.4}∠{phase:.4}°"
