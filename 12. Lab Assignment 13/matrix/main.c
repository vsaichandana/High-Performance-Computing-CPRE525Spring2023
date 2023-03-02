#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#include <time.h>

int main()
{
  // Matrices
  matrix L = new_matrix(5, 5);
  double rand_num;
  srand(time(NULL));                    // Seed the random number generator
  rand_num = (double)rand() / RAND_MAX; // Generate a random number between 0 and 1

  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++)
    {
      double diagonalComponet = -1.0 * (i == j);
      double lowerTraingleComponet = rand_num * (i > j);
      double upperTraingleComponet = 0 * (j > i);
      mget(L, i, j) = diagonalComponet + lowerTraingleComponet + upperTraingleComponet;
    }

  // Print matrices
  print_matrix(&L);

  // // Compute L_Transpose
  matrix L_Transpose = matrix_transpose(&L);
  print_matrix(&L_Transpose);

  // Compute A = LL_Transpose
  matrix A = matrix_mult(&L, &L_Transpose);
  print_matrix(&A);

  // Generate random vector b [0, 1]
  vector b = new_vector(5);
  for (int i = 0; i < 5; i++)
  {
    b.val[i] = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
  }
  print_vector(&b);

  // Solve Ax = b (Linear solve via Gaussian elimination)
  vector x = solve(&A, &b);
  print_vector(&x);

  // Cleanup
  delete_matrix(&L);
  delete_matrix(&L_Transpose);
  delete_matrix(&A);
  delete_vector(&b);
  delete_vector(&x);
}
