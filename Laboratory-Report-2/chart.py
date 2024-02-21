import matplotlib
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots(2, 2, figsize=(15, 7))


data = np.loadtxt('double_test_1.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]
ax[0, 0].set_title('double, T(n), T - time in ms, n - array size')
ax[0, 0].set_xlabel('n')
ax[0, 0].set_ylabel('ms.')
ax[0, 0].plot(x, y)

data = np.loadtxt('float_test_1.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]
ax[0, 1].set_title('float, T(n), T - time in ms, n - array size')
ax[0, 1].set_xlabel('n')
ax[0, 1].set_ylabel('ms.')
ax[0, 1].plot(x, y)

data = np.loadtxt('int_test_1.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]
ax[1, 0].set_title('int, T(n), T - time in ms, n - array size')
ax[1, 0].set_xlabel('n')
ax[1, 0].set_ylabel('ms.')
ax[1, 0].plot(x, y)

data = np.loadtxt('short_test_1.txt', delimiter=';')
x = data[:, 0]
y = data[:, 1]
ax[1, 1].set_title('short, T(n), T - time in ms, n - array size')
ax[1, 1].set_xlabel('n')
ax[1, 1].set_ylabel('ms.')
ax[1, 1].plot(x, y)


plt.show()
