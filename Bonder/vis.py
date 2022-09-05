import numpy as np
import matplotlib.pyplot as plt

def it(mu = 0):
    precision = 2
    range = (10**(precision + 1))/2 + mu
    array = []
    i = -range
    while i < range:
        x = i/(10**precision)
        b = normal(x,1,mu)
        array.append(b)
        print(i)
        print("b: " + str(b))
        i += (10**(-precision))
    plt.figure()
    plt.plot(array)
    plt.show()
    print(array)
    return


def normal(x, sigma = 1, mu = 0):
    level = (((x-mu)/sigma)**2)*(-0.5)
    exponential = np.exp(level)
    conjugate = 1/(sigma*np.sqrt(2*np.pi))
    return exponential*conjugate

print(np.exp(0.0049))
