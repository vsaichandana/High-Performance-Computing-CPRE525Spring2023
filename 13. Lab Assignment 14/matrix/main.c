#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#include <time.h>

int main()
{
  // Matrices
  int sizeRows = 3;
  int sizeCols = 3;
  matrix L = new_matrix(sizeRows, sizeCols);
  double rand_num;
  srand(time(NULL));                    // Seed the random number generator
  rand_num = (double)rand() / RAND_MAX; // Generate a random number between 0 and 1

  for (int i = 1; i <= sizeRows; i++)
    for (int j = 1; j <= sizeCols; j++)
    {
      double diagonalComponet = 1.0 * (i == j)+i;
      double lowerTraingleComponet = 2 * (i > j);
      double upperTraingleComponet = 0* (j > i);
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
  vector v = new_vector(sizeRows);
  for (int i = 0; i < sizeRows; i++)
  {
    // v.val[i] = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
    v.val[i] = 1; // Generate a random value between 0 and 1

  }
  print_vector(&v);

  // Solve Ax = b (Linear solve via Gaussian elimination)
  // vector x = solve(&A, &v);
  // print_vector(&x);

  // Solve larest eigen value by power_iteration
  double TOL = 1e-2;
  int MaxIterations = 200;
  double lambda;

  lambda = power_iteration(&A, &v, TOL, MaxIterations);
  printf("\n [power_iteration] The largest eigen value (Lambda) for A is %.2f\n\n", lambda);



  for (int i = 0; i < sizeRows; i++)
  {
    // v.val[i] = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
    v.val[i] = 1; // Generate a random value between 0 and 1

  }
  // print_vector(&v);
  double mu=100;
  double result;
  result = shiftedInverse_power_iteration(&A, &v, mu, TOL, MaxIterations);
  printf("\n [shiftedInverse_power_iteration] The eigen value (Lambda) close to mu (100) for A is %.10f\n\n", result);


  // for (int i = 0; i < sizeRows; i++)
  // {
  //   // v.val[i] = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
  //   v.val[i] = 1; // Generate a random value between 0 and 1

  // }
  // print_vector(&v);
  result = RayleighQuotient_iteration(&A, &v, TOL, MaxIterations);
  printf("\n [RayleighQuotient_iteration] The eigen value (Lambda) for A is %.10f\n\n", result);


  // Cleanup
  delete_matrix(&L);
  delete_matrix(&L_Transpose);
  delete_matrix(&A);
  delete_vector(&v);
  // delete_vector(&x);
}
