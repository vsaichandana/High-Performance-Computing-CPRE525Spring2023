import numpy as np
import myfuncs as mf
import math

x = 2
print('==============================================')
print("Input number: ", x)

print('\n--------[Results for my_sqrt]----------------')
smine = mf.my_sqrt(x)
snum = np.math.sqrt(x)
serr = smine - snum
print("My sqrt: ", smine)
print("Numpy sqrt: ", snum)
print("Error between my sqrt(%f) and numpy sqrt(%f) is %.5E" % (x,x,abs(serr)))


print('\n--------[Results for my_factorial]----------------')
smine = mf.my_factorial(x)
snum = np.math.factorial(x)
serr = smine - snum
print("My factorial: ", smine)
print("Numpy factorial: ", snum)
print("Error between my factorial(%f) and numpy factorial(%f) is %.5E" % (x,x,abs(serr)))

print('\n--------[Results for my_exp]----------------')
smine = mf.my_exp(x)
snum = np.exp(x)
serr = smine - snum
print("My Exp: ", smine)
print("Numpy Exp: ", snum)
print("Error between my exp(%f) and numpy exp(%f) is %.5E" % (x,x,abs(serr)))

print('\n--------[Results for my_ln]----------------')
smine = mf.my_ln(x)
snum = np.log(x)
serr = smine - snum
print("My Ln: ", smine)
print("Numpy Ln: ", snum)
print("Error between my ln(%f) and numpy log(%f) is %.5E" % (x,x,abs(serr)))
print('==============================================')