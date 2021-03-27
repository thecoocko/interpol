import numpy as np
import matplotlib.pyplot as plot
import math

print("Interpolate method")

x = np.array([0.2143,0.2572,0.3269,0.4282,0.5657,0.7756,1.0935])
y = np.array([4.3002,4.2037,4.0830,3.9946,4.0603,4.6388,6.8430])
dx = (x[len(x)-1]-x[0])/6
e = 0.25
r=1
f=1; z=0; fp = 1; xi = np.array([0 for i in range(len(x))]);
for k in range(len(x)-1):
    xi[k+1] = xi[k]+dx
for j in range(len(y)):
    p1=1; p2=1
    for i in range(len(x)):
        if i==j:
            p1=p1*1; p2=p2*1;   
        else: 
            p1=p1*(e-x[i])
            p2=p2*(x[j]-x[i])
    z+=y[j]*p1/p2
    if(r > e):
        fp *= (j+((e-xi[j])/dx))
        f = pow(dx,j)*y[0]/math.factorial(j+1)
        r = f*fp


print(('%s %f') % ("Error: ", r))
print(('%s %f') % ("Result: ", z))

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

