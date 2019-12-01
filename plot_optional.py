import numpy as np
import matplotlib.pyplot as plt

#%%

logistic = np.loadtxt("logistic.dat")
tent = np.loadtxt("tent.dat")
sin_map = np.loadtxt("sin.dat")

plt.semilogy(logistic[:,0], np.abs(logistic[:,1] - logistic[:,2]), marker="+")
plt.semilogy(tent[:,0], np.abs(tent[:,1] - tent[:,2]), marker="+")
plt.semilogy(sin_map[:,0], np.abs(sin_map[:,1] - sin_map[:,2]), marker="+")
