#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "trimatrix.h"

// function declaration
matrix QRdecomp(matrix * A);

void QRA(trimatrix *T, int maxIterations, double tolerance)
{
  int iteration = 0;
  double residual = 1.0;

  // get size
  const int matrixSize = T->rows;
  assert(matrixSize == T->cols);

  while (residual > tolerance && iteration < maxIterations)
  {
    // Copy tridiagonal matrix into a bigger matrix
    // This is needed for the QR step to perform
    matrix bigMatrix = new_matrix(matrixSize, matrixSize);
    for (int i = 1; i <= matrixSize; i++)
    {
      for (int j = 1; j <= matrixSize; j++)
      {
        if (abs(i - j) <= 1)
        {
          mget(bigMatrix, i, j) = tget(T, i, j);
        }
      }
    }

    // QR factorization on bigger matrix
    matrix Q = QRdecomp(&bigMatrix);

    // Multiply Q and A in reverse order
    // and store in a new tridiagonal matrix
    delete_trimatrix(T);
    *T = matrix_mult_to_trimatrix(&bigMatrix, &Q);

    // Compute residual and increment iteration count
    residual = pow(fabs(tget(T, 1, 2)), 2.0);
    for (int i = 2; i <= matrixSize; i++)
    {
      residual += pow(fabs(tget(T, i, i - 1)), 2.0);
      residual += pow(fabs(tget(T, i - 1, i)), 2.0);
    }
    residual = sqrt(residual);
    iteration++;

    // cleanup
    delete_matrix(&bigMatrix);
  }
}
