import numpy as np
import matplotlib.pyplot as plot

print("Interpolate method")

x = np.array([0.2143,0.2572,0.3269,0.4282,0.5657,0.7756,1.0935])
y = np.array([4.3002,4.2037,4.0830,3.9946,4.0603,4.6388,6.8430])
e = 0.25

def lagranz(x,y,e):
    z=0
    for j in range(len(y)):
        p1=e; p2=e
        for i in range(len(x)):
            if i==j:
                p1=p1*1; p2=p2*1   
            else: 
                p1=p1*(e-x[i])
                p2=p2*(x[j]-x[i])
        z=z+y[j]*p1/p2
    return z
xnew=np.linspace(np.min(x),np.max(x),6)
ynew=[lagranz(x,y,i) for i in xnew]
plot.plot(x,y,'o',xnew,ynew)
plot.grid(True)
plot.show()


