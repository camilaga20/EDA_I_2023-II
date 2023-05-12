import matplotlib.pyplot as plt
import mumpy as np

x = np.linspace(0, 5, 20)
print(x)

fig, ax= plt.subplots(facecolor='w', edgecolor='k')
ax.plot(x, np.cos(x), marker='x', color='b', linestyle='None')

ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.grid(True)
ax.legend("y= cos(x)")

plt.title("Funcion cosenoidal")
plt.show()