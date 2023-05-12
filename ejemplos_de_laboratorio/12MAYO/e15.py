import matplotlib.pyplot as plt
import mumpy as np

fig, ax= plt.subplots(facecolor='w', edgecolor='k')
ax.plot(x, x, marker='x', color='b', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y= x")

plt.title("Funcion lineal")
plt.show()