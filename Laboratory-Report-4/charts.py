import os
import glob
import sys
import matplotlib
import matplotlib.pyplot as plt
import numpy as np

# to run - python charts.py tests/

if len(sys.argv) < 1:
    print('You must pass the path with time measuring files')
    exit()

directory_path = sys.argv[1]
# Получаем список всех файлов с расширением .txt в указанной директории
txt_files = glob.glob(os.path.join(directory_path, '*.txt'))


fig, ax = plt.subplots()

legends = []
ax.set_title('T(n), T - time in ms., n - array size')
ax.set_xlabel('n')
ax.set_ylabel('ms.')
for file in txt_files:
    fname = file.split('.txt')[0]
    fname = fname.split('\\')[1]
    search = fname.split('_')[0]
    data_type = fname.split('_')[1]
    legends.append(f'{search} {data_type}')

    data = np.loadtxt(file, delimiter=';')
    x = data[:, 0]
    y = data[:, 1]

    ax.plot(x, y,)
ax.legend(legends)
plt.show()
