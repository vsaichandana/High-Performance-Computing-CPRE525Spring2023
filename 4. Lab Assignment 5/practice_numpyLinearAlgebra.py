import numpy as np

# Define two arrays A and B
A = np.array([[1, 2], [3, 4]])
B = np.array([[5, 6], [7, 8]])

# Matrix multiplication
C = np.dot(A, B)
print('Matrix multiplication of A and B',C)

# Transpose of a matrix
C_transpose = C.T
print('Transpose of a matrix',C_transpose)

# Inverse of a matrix
C_inverse = np.linalg.inv(C)
print('Inverse of a matrix', C_inverse)

# Determinant of a matrix
C_det = np.linalg.det(C)
print('Determinant of a matrix', C_det)

# Eigenvalues and eigenvectors
eig_values, eig_vectors = np.linalg.eig(C)
print("Eigenvalues:", eig_values)

# Singular value decomposition
U, s, V = np.linalg.svd(C)
print("Singular value decomposition, U:", U)
print("s:", s)
print("V:", V)

# QR decomposition
Q, R = np.linalg.qr(C)
print("QR decomposition, Q:", Q)
print("QR decomposition, R", R)


## Solve linear equations

#1. Define coefficient matrix and right-hand side vector
A = np.array([[3, 1], [1, 2]])
b = np.array([9, 8])
print('input A: ',A)
print('input b: ', b)
# 2.Solve the linear equation Ax = b
x = np.linalg.solve(A, b)
print('Solving the linear equation Ax = b. x:',x)

# 2.Verify the solution by checking the dot product of A and x
result = np.dot(A, x)
print('Verification of the solution by computing the dot product of A and x', result)