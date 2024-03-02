import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()

data = np.loadtxt('double_test_2.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]

ax.plot(x,y,)
plt.show()
