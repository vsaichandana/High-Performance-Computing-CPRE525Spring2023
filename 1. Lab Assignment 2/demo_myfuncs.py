import numpy as np
import myfuncs as mf
import math

x = 2
print('==============================================')
print("Input number: ", x)
print('--------------------------------------')
smine = mf.my_exp(x)
snum = np.exp(x)
serr = smine - snum
print("Numpy Exp: ", np.exp(x))
print("My Exp: ", mf.my_exp(x))
print("Error between my exp(%f) and numpy exp(%f) is %.5E" % (x,x,abs(serr)))
print('--------------------------------------')
smine = mf.my_ln(x)
snum = np.log(x)
serr = smine - snum
print("Numpy Ln: ", np.log(x))
print("My Ln: ", mf.my_ln(x))
print("Error between my ln(%f) and numpy log(%f) is %.5E" % (x,x,abs(serr)))
print('==============================================')