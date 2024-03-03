import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()

data = np.loadtxt('output.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]

ax.set_title('T(n), T - time in ms., n - array size')
ax.set_xlabel('n')
ax.set_ylabel('ms.')

ax.plot(x, y,)
plt.show()
