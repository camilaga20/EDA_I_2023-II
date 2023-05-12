import matplotlib.pyplot as plt
import mumpy as np

x = np.linspace(0, 50, 50)

fig, ax= plt.subplots(facecolor='w', edgecolor='k')
ax.plot(x, np.log(x), marker='x', color='b', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y= log(x)")

plt.title("Funcion logaritmo")
plt.show()