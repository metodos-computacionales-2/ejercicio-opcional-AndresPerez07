import numpy as np
import matplotlib.pyplot as plt

#%%

logistic = np.loadtxt("logistic.dat")
tent = np.loadtxt("tent.dat")
sin_map = np.loadtxt("sin.dat")

fig = plt.figure(figsize=(15,5))
ax = fig.add_subplot(1,3,1)
ax.semilogy(logistic[:,0], np.abs(logistic[:,1] - logistic[:,2]), marker="+")
ax.set_title("Logistic map")
ax2 = fig.add_subplot(1,3,2)
ax2.semilogy(tent[:,0], np.abs(tent[:,1] - tent[:,2]), marker="+")
ax2.set_title("tent map")
ax3 = fig.add_subplot(1,3,3)
ax3.semilogy(sin_map[:,0], np.abs(sin_map[:,1] - sin_map[:,2]), marker="+")
ax3.set_title("sin map")
plt.savefig("Lyapunov.png")
