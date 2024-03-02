import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()

data = np.loadtxt('n.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]
data = np.loadtxt('float_test_1.txt', delimiter=';')
x1 = data[:, 0]
y1 = data[:, 1]
data = np.loadtxt('int_test_1.txt', delimiter=';')
x2 = data[:, 0]
y2 = data[:, 1]
data = np.loadtxt('short_test_1.txt', delimiter=';')
x3 = data[:, 0]
y3 = data[:, 1]

ax.set_title('T(n), T - time in s., n - array size')
ax.set_xlabel('n')
ax.set_ylabel('s.')

ax.plot(x, y, x1, y1, x2, y2, x3, y3)
ax.legend(['Double T(n)','Float T(n)','Int T(n)','Short T(n)'])
plt.show()
