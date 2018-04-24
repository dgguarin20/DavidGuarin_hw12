import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('advection.txt')
dato1 = datos[:,0]
n = len(dato1)
dato1[np.isnan(dato1)] = 0
dato2 = datos[:,1]
dato2[np.isnan(dato2)] = 0
dato3 = datos[:,2]
dato3[np.isnan(dato3)] = 0
dato4 = datos[:,3]
dato4[np.isnan(dato4)] = 0
dato5 = datos[:,4]
dato5[np.isnan(dato5)] = 0

x = []
xv = -2
dx = 0.01
x.append(xv)
for i in range(0,n):
    xv = xv+dx
    x.append(xv)

x = np.asarray(x)


plt.plot(x,dato1)
plt.plot(x,dato2)
plt.plot(x,dato3)
plt.plot(x,dato4)
plt.plot(x,dato5)
plt.show()
