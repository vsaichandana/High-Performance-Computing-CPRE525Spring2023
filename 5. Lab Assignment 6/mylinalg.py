import numpy as np
import matplotlib.pyplot as plt
# from gauss_elimination_cpre525 import gauss_elimination

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
def polynomial_Amatrix_bcos(xpts, polynomialDegreeMax = 3):
        # length of the x points vector
        n= np.shape(xpts)[0]
        # Function for the b is equal to cos(x)
        b=np.cos(xpts)
        # Initializing the A matrix with ones an updating them with the P(x) = ax^3 + bx^2 + cx^1 + dx^0
        A=np.ones([n,polynomialDegreeMax+1])
        for index,_degree in enumerate(np.arange(polynomialDegreeMax+1)[::-1]):
                A[:,index]=xpts**_degree
        return A,b

if __name__ == "__main__":

        # Step 1: Input of x points as given in the class
        xpts=np.array([-0.1,-0.02,0.02,0.1])
        polynomialDegreeMax = 3

        # Step 2: Design of A matrix with the polynomial function and b vector with cos function
        A,b = polynomial_Amatrix_bcos(xpts, polynomialDegreeMax)

        # Step 3: Solving it by custom and numpy Gauss_Elimination methods and compare the result
        result_mine = gauss_elimination(A,b)
        result_numpy = np.linalg.solve(A, b)
        print("My gauss elimination result: ", result_mine)
        print("Numpy gauss elimination result: ", result_numpy)
        print("Error between my gauss elimination and numpy gauss elimination is ", result_mine-result_numpy)

        # Step 4 plot the b vs x & A vs x
        resolutionLinespace = 51
        x=np.linspace(xpts[0], xpts[-1], resolutionLinespace)
        f=np.cos(x)
        p=np.zeros(resolutionLinespace)
        for index,_degree in enumerate(np.arange(polynomialDegreeMax+1)[::-1]):
            p = p + x ** _degree * result_mine[index]
        ## plots (a) f vs x (b) p vs x
        plt.plot(x, f, "r", label="f vs x")
        plt.plot(x, p, "o", label="p vs x")
        plt.legend(loc="upper right")
        plt.grid(True)
        plt.show()
