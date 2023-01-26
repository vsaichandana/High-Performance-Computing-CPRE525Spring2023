"""
Author: Saichandana V
Purpose: Lab Assignment 2 & Lab Assignment 4
Created: 01/19/2023
Updated: 01/26/2023
This python script includes the two functions (a) exponential algorithm using taylor series with e=2.7182818284590451, and (b) natural logarithm function using Newtons method  and the exponential function generated in the (a).
"""
import math

e = 2.7182818284590451
iterations = 20


# Prepared my_sqrt for Lab Assignment 4 @ 01/26/2023
def my_sqrt(x: float) -> float:
    '''
    :param x: float
    :return: it compute square root of the floating number using Newton's method
    This function takes a non-negative float number as input and returns the square root of it. It raises a ValueError if the input is a negative number.
    '''
    if x < 0:
        raise ValueError("Input must be a non-negative number")
    elif x == 0:
        return 0
    else:
        approx = x
        while abs(approx*approx - x) > 1e-12:
            approx = (approx + x/approx) / 2
        return approx


# Prepared my_factorial for Lab Assignment 4 @ 01/26/2023
def my_factorial(n: int) -> int:
    '''
    :param n: real number
    :return:
    '''
    if not isinstance(n, int):
        raise TypeError("[Error] Input must be an integer")
    elif n < 0:
        raise ValueError("[Error] Input must be a non-negative integer")
    elif n == 0:
        return 1
    else:
        return n * my_factorial(n-1)

def my_exp(x, n=iterations):
    '''
    :param x: a real number
    :param n: number of iterations
    :return: it returns exponential of the real number
    '''
    # 1. Using math_factorial
    # result = sum((x ** i) / math.factorial(i) for i in range(n))

    # 2. Using my_factorial
    result = sum((x ** i) / my_factorial(i) for i in range(n))
    return result

def my_ln(x, n=iterations):
    S = x
    for i in range(n):
        S = (S - 1 + x * my_exp(-S))
    return S
