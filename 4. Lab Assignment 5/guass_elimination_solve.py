"""
Author: Saichandana V
Purpose: Lab Assignment 5
Created: 01/31/2023
This python script for Gaussian elimination

"""

import numpy as np

# create A matrix and b vector using numpy
A = np.array([[-2, 0, 1], [-1, 7, 1], [5, -1, 1]])
b = np.array([-4, -50, -26])

# solve the linear system using numpy's linear algebra library
x_numpy = np.linalg.solve(A, b)

# print the solution using numpy
print("The solution x_numpy is:")
print("x1 =", x_numpy[0])
print("x2 =", x_numpy[1])
print("x3 =", x_numpy[2])


# define the Gauss Elimination function
def gauss_elimination(A, b):
    n = len(A)
    # iterate over each row of A
    for i in range(n):
        # find the pivot row
        pivot = i
        for j in range(i + 1, n):
            if abs(A[j][i]) > abs(A[pivot][i]):
                pivot = j

        # swap pivot row with current row
        A[i], A[pivot] = A[pivot], A[i]
        b[i], b[pivot] = b[pivot], b[i]
        # perform the elimination step for each row below the pivot row
        for j in range(i + 1, n):
            m = A[j][i] / A[i][i]
            A[j][i] = 0
            for k in range(i + 1, n):
                A[j][k] -= m * A[i][k]
            b[j] -= m * b[i]
    # perform the back substitution step
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - sum(A[i][j] * x[j] for j in range(i + 1, n))) / A[i][i]
    # return the solution
    return x


# create A and b matrices for Gauss Elimination function
A = [[-2, 0, 1], [-1, 7, 1], [5, -1, 1]]
b = [-4, -50, -26]

# solve the linear system using the Gauss Elimination function
x_mine = gauss_elimination(A, b)

# print the solution obtained from Gauss Elimination function
print("\n The solution [x_mine] is:")
print("x1 =", x_mine[0])
print("x2 =", x_mine[1])
print("x3 =", x_mine[2])

# print the difference between the solutions obtained from numpy and Gauss Elimination function
print("\nThe solution x_mine-x_numpy is:")
print("x1 =", x_mine[0] - x_numpy[0])
print("x2 =", x_mine[1] - x_numpy[1])
print("x3 =", x_mine[2] - x_numpy[2])
