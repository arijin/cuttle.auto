import numpy as np


def linestr(key, value):
    label = f"{key}:"
    if isinstance(value, int) or isinstance(value, float) or isinstance(value, str):
        label = f"{label}{value}\n"
        return label
    elif isinstance(value, list) or isinstance(value, tuple):
        length = len(value)
    elif type(value) is np.ndarray:
        value = value.reshape(-1)
        length = value.shape[0]
    else:
        label = f"{label} \n"
        return label
    if length == 0:
        label = f"{label} \n"
        return label
    for i in range(length-1):
        label = f"{label}{value[i]} "
    label = f"{label}{value[-1]}\n"
    return label
