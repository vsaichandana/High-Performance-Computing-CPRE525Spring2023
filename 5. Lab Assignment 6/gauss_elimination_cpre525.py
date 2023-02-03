"""
Gauss elimination (no partial pivoting)
solve linear system Ax = b
with a given example
A size 3 by 3 matrix
b size 3 by 1 vector
compared with numpy solve results
"""
import numpy as np

def gauss_elimination(A, b):
    '''
    This is the Gauss_Elimination function (c) CPRE 525 instructor.
    I modified the provided code into function format for modularity and reuse
    :param A: Matrix mxn
    :param b: column vector, where Ax = b
    :return: x as a vector
    '''
    num_rows,num_cols = np.shape(A)

    #main loop
    # print('Gaussian Elimination === ')
    for col in range(num_cols-1):
        # print('Gauss elemination along col=',col,':')
        for row in range(col+1,num_rows):
            m = (A[row][col]/A[col][col])
            A[row][col:] = A[row][col:] - m*A[col][col:]
            b[row] = b[row] - m*b[col]
        # print(A)
        # print(b)
    #back substituion
    # print('Back substitution === ')
    # x= np.zeros(3)
    x = np.zeros(num_cols) #num_cols of A is equal to the size of x result vector
    x[num_rows-1] = b[num_rows-1]/A[num_rows-1][num_cols-1]
    for row in range(num_rows-2,-1,-1):
        x[row] = (b[row] - np.dot(A[row][row+1:],x[row+1:]))/A[row][row]
    # print(x)

    return x

if __name__ == "__main__":

    # input A and b
    #A = np.array([[3.0,1,-1],[1.0,-1,1],[2.0,1,1]])
    #b = np.array([1.0,-3,0])
    A = np.array([[-2,0,1],[-1.0,7,1],[5,-1,1]])
    b = np.array([-4.0,-50,-26])
    print('A and b are:')
    print(A)
    print(b)

    x = gauss_elimination(A,b)
    print('result of gauss_elimination(A,b): ',x)

    #compare with numpy solve
    from numpy import linalg as la
    AA = np.copy(A)
    bb = np.copy(b)
    xx = la.solve(AA,bb)
    print(xx)
    print('Error compuared with numpy solve is ', la.norm(x-xx))