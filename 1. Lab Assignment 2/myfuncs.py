"""
Author: Saichandana V
Purpose: Lab Assignment 2
Submitted: 01/19/2023
This python script includes the two functions (a) exponential algorithm using taylor series with e=2.7182818284590451, and (b) natural logarithm function using Newtons method  and the exponential function generated in the (a).
"""
import math

e = 2.7182818284590451
iterations = 20

def my_exp(x, n=iterations):
    return sum((x ** i) / math.factorial(i) for i in range(n))

def my_ln(x, n=iterations):
    S = x
    for i in range(n):
        S = (S - 1 + x * my_exp(-S))
    return S
