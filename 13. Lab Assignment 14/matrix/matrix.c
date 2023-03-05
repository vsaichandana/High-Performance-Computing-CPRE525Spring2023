#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "matrix.h"

matrix new_matrix(const int rows, const int cols)
{
  matrix mat;
  mat.rows = rows;
  mat.cols = cols;
  assert(rows > 0);
  assert(cols > 0);
  mat.val = (double *)malloc(sizeof(double) * rows * cols);

  for (int i = 0; i < (rows * cols); i++)
  {
    mat.val[i] = 0.0;
  }

  return mat;
}

void print_matrix_full(const matrix *mat, char *varname)
{
  assert(mat->rows > 0);
  assert(mat->cols > 0);
  printf("\n %.100s =\n", &varname[1]);
  for (int i = 1; i <= mat->rows; i++)
  {
    printf("  |  ");
    for (int j = 1; j <= mat->cols; j++)
    {
      printf("%10.3e", mgetp(mat, i, j));
      if (j < mat->cols)
      {
        printf(", ");
      }
      else
      {
        printf(" ");
      }
    }
    printf("|\n");
  }
  printf("\n");
}

matrix matrix_add(const matrix *A, const matrix *B)
{
  const int rows = A->rows;
  const int cols = A->cols;
  assert(rows == B->rows);
  assert(cols == B->cols);
  matrix C = new_matrix(rows, cols);

  for (int i = 1; i <= rows; i++)
    for (int j = 1; j <= cols; j++)
    {
      mget(C, i, j) = mgetp(A, i, j) + mgetp(B, i, j);
    }

  return C;
}

matrix matrix_transpose(const matrix *A)
{
  int row = A->rows;
  int col = A->cols;

  matrix b = new_matrix(col, row);

  for (int i = 1; i <= row; i++)
  {
    for (int j = 1; j <= col; j++)
    {
      mget(b, j, i) = mgetp(A, i, j);
    }
  }
  return b;
}

matrix matrix_sub(const matrix *A, const matrix *B)
{
  const int rows = A->rows;
  const int cols = A->cols;
  assert(rows == B->rows);
  assert(cols == B->cols);
  matrix C = new_matrix(rows, cols);

  for (int i = 1; i <= rows; i++)
    for (int j = 1; j <= cols; j++)
    {
      mget(C, i, j) = mgetp(A, i, j) - mgetp(B, i, j);
    }

  return C;
}

matrix matrix_mult(const matrix *A, const matrix *B)
{
  const int rowsA = A->rows;
  const int colsA = A->cols;
  const int rowsB = B->rows;
  const int colsB = B->cols;
  assert(colsA == rowsB);
  matrix C = new_matrix(rowsA, colsB);

  for (int i = 1; i <= rowsA; i++)
    for (int j = 1; j <= colsB; j++)
      for (int k = 1; k <= colsA; k++)
      {
        mget(C, i, j) += mgetp(A, i, k) * mgetp(B, k, j);
      }

  return C;
}

matrix matrix_dot_mult(const matrix *A, const matrix *B)
{
  const int rows = A->rows;
  const int cols = A->cols;
  assert(rows == B->rows);
  assert(cols == B->cols);
  matrix C = new_matrix(rows, cols);

  for (int i = 1; i <= rows; i++)
    for (int j = 1; j <= cols; j++)
    {
      mget(C, i, j) = mgetp(A, i, j) * mgetp(B, i, j);
    }

  return C;
}

void delete_matrix(matrix *mat)
{
  free(mat->val);
}

vector new_vector(const int size)
{
  vector vec;
  vec.size = size;
  assert(size > 0);
  vec.val = (double *)malloc(sizeof(double) * size);

  for (int i = 0; i < (size); i++)
  {
    vec.val[i] = 0.0;
  }

  return vec;
}

void print_vector_full(const vector *vec, char *varname)
{
  assert(vec->size > 0);
  printf("\n");
  printf(" %.100s =\n", &varname[1]);
  printf("  |  ");
  for (int i = 1; i <= vec->size; i++)
  {
    printf("%10.3e", vgetp(vec, i));
    if (i < vec->size)
    {
      printf(", ");
    }
  }
  printf(" |^T\n\n");
}

vector vector_add(const vector *x, const vector *y)
{
  const int size = x->size;
  assert(size == y->size);
  vector z = new_vector(size);

  for (int i = 1; i <= size; i++)
  {
    vget(z, i) = vgetp(x, i) + vgetp(y, i);
  }

  return z;
}

vector vector_sub(const vector *x, const vector *y)
{
  const int size = x->size;
  assert(size == y->size);
  vector z = new_vector(size);

  for (int i = 1; i <= size; i++)
  {
    vget(z, i) = vgetp(x, i) - vgetp(y, i);
  }

  return z;
}

double vector_dot_mult(const vector *x, const vector *y)
{
  const int size = x->size;
  assert(size == y->size);

  double z = 0.0;
  for (int i = 1; i <= size; i++)
  {
    z += vgetp(x, i) * vgetp(y, i);
  }

  return z;
}

void delete_vector(vector *vec)
{
  free(vec->val);
}

void print_scalar_full(const double *z, char *varname)
{
  printf("\n %.100s =\n", &varname[1]);
  printf("    %10.3e \n\n", *z);
}

vector matrix_vector_mult(const matrix *A, const vector *x)
{
  const int rows = A->rows;
  const int cols = A->cols;
  const int size = x->size;
  // print_matrix(&A);
  // print_vector(&x);
  // printf("inside matrix vector mult");
  // printf("\n\n========= %d************",size);
  assert(cols == size);
  vector Ax = new_vector(rows);

  for (int i = 1; i <= rows; i++)
  {
    double tmp = 0.0;
    for (int j = 1; j <= size; j++)
    {
      tmp += mgetp(A, i, j) * vgetp(x, j);
    }
    vget(Ax, i) = tmp;
  }

  return Ax;
}

vector solve(const matrix *A, const vector *b)
{
  const int rows = A->rows;
  const int cols = A->cols;
  const int size = b->size;
  assert(rows == cols);
  assert(rows == size);
  //   print_matrix(A);
  // print_vector(b);
  vector x = new_vector(rows);

  for (int i = 1; i <= (size - 1); i++) // LOOP OVER EACH COLUMN
  {
    // Select largest pivot in current column
    int p = i;
    double maxA = -100.0e0;
    for (int j = i; j <= size; j++)
    {
      double tmp = fabs(mgetp(A, j, i));
      if (tmp > maxA)
      {
        p = j;
        maxA = tmp;
      }
    }

    // See if matrix is singular
    if (maxA <= 1.0e-14)
    {
      printf(" Cannot invert system\n");
      exit(1);
    }

    // Pivot (aka interchange rows)
    if (p != i)
    {
      for (int j = 1; j <= size; j++)
      {
        double tmp1 = mgetp(A, i, j);
        mgetp(A, i, j) = mgetp(A, p, j);
        mgetp(A, p, j) = tmp1;
      }

      double tmp2 = vgetp(b, i);
      vgetp(b, i) = vgetp(b, p);
      vgetp(b, p) = tmp2;
    }

    // Eliminate below diagonal
    for (int j = (i + 1); j <= size; j++)
    {
      double dm = mgetp(A, j, i) / mgetp(A, i, i);
      for (int k = 1; k <= size; k++)
      {
        mgetp(A, j, k) = mgetp(A, j, k) - dm * mgetp(A, i, k);
      }
      vgetp(b, j) = vgetp(b, j) - dm * vgetp(b, i);
    }
  }

  // Backward substitution
  vget(x, size) = vgetp(b, size) / mgetp(A, size, size);
  for (int j = 1; j <= (size - 1); j++)
  {
    double sum = 0.0e0;

    for (int k = (size - j + 1); k <= size; k++)
    {
      sum = sum + mgetp(A, size - j, k) * vget(x, k);
    }

    vget(x, size - j) = (vgetp(b, size - j) - sum) / mgetp(A, size - j, size - j);
  }

  return x;
}

// double power_iteration(const matrix* A, const vector* v, double TOL, int MaxIterations)
// {  const int rows = A->rows; const int cols = A->cols;
//   const int size = v->size;
//   assert(rows==cols); assert(rows==size);

//   double lambda=0;

//  return lambda;
// }

void vector_copy(const vector *dest, const vector *src)
{
  for (int i = 0; i < dest->size; i++)
  {
    dest->val[i] = src->val[i];
  }
}

void vector_scale(const vector *v, double scalar)
{
  for (int i = 0; i < v->size; i++)
  {
    v->val[i] *= scalar;
  }
}

double vector_norm(const vector *v)
{
  double sum = 0.0;
  for (int i = 0; i < v->size; i++)
  {
    sum += v->val[i] * v->val[i];
  }
  return sqrt(sum);
}

double vector_dot(vector *v1, vector *v2)
{
  double sum = 0.0;
  for (int i = 0; i < v1->size; i++)
  {
    sum += v1->val[i] * v2->val[i];
  }
  return sum;
}

int vector_max(vector *v)
{
  int max_index = 0;
  for (int i = 1; i < v->size; i++)
  {
    if (v->val[i] > v->val[max_index])
    {
      max_index = i;
    }
  }
  return max_index;
}

double power_iteration_v1(const matrix *A, const vector *v, double TOL, int MaxIterations)
{
  const int rows = A->rows;
  const int cols = A->cols;
  const int size = v->size;
  assert(rows == cols);
  assert(rows == size);

  vector u = new_vector(rows);
  double lambda = 0.0, lambda_old = 0.0, error;

  // Normalize the initial vector
  double norm = vector_norm(v);
  vector_scale(v, 1.0 / norm);

  // Perform the power iteration
  for (int i = 0; i < MaxIterations; i++)
  {
    // Compute Av
    u = matrix_vector_mult(A, v);
    // Compute the largest component of Av
    lambda = vector_dot_mult(v, &u);

    // Normalize u
    norm = vector_norm(&u);
    vector_scale(&u, 1.0 / norm);

    // Compute the relative error in lambda
    if (i > 0)
    {
      error = fabs(lambda - lambda_old) / fabs(lambda);
      if (error < TOL)
      {
        printf("\n Maximum number of Iterations for solving eigen value for A by Power Iteration is %d\n", i);
        break;
      }
    }

    // Save the current eigenvalue
    lambda_old = lambda;

    // Copy v to u for the next iteration
    vector_copy(v, &u);
  }

  delete_vector(&u);

  return lambda;
}

double power_iteration(const matrix *A, const vector *v, double TOL, int MaxIterations)
{
  const int rows = A->rows;
  const int cols = A->cols;
  const int size = v->size;
  assert(rows == cols);
  assert(rows == size);

  vector w = new_vector(rows);
  double lambda = 0, lambda_old, error;

  // Update lamda(0) iteration
  vector Av = matrix_vector_mult(A, v);
  lambda_old = vector_dot_mult(v, &Av);
  // print_scalar(&lambda_old);

  // Create an A shift matrix, As
  matrix As = new_matrix(rows, cols);
  matrix_copy(A, &As);

  // Normalize the initial vector
  double norm = vector_norm(v);
  vector_scale(v, 1.0 / norm);

  // Perform the shifted inverse power iteration
  for (int i = 0; i < MaxIterations; i++)
  {
    // update A-lamda_old*I
    for (int i = 1; i <= rows; i++)
    {
      mgetNew(&As, i, i) = mgetNew(&As, i, i) - lambda_old;
    }

    // Solve (A - mu*I)u = v for u
    // w = solve(&As, v);
    // Update lamda(0) iteration
    vector w = matrix_vector_mult(A, v);

    // Normalize w and w=w/||w||
    norm = vector_norm(&w);
    vector_scale(&w, 1.0 / norm);
    // Copy u to v for the next iteration
    vector_copy(v, &w);

    // Update lamda(0) iteration
    vector Av = matrix_vector_mult(A, v);
    lambda = vector_dot_mult(v, &Av);

    // Compute the relative error in lambda
    if (i > 0)
    {
      error = fabs(lambda - lambda_old) / fabs(lambda);
      // printf("[PowerIteration] error [%i][%.5f-%.5f] %.5f\n",i,lambda,lambda_old,error);
      if (error < TOL)
      {
        printf("\n Maximum number of Iterations for solving eigen value for A by Rayleigh Quotient Iteration is %d\n", i);
        break;
      }
      else
      {
        lambda_old = lambda;
      }
    }
  }

  delete_matrix(&As);
  delete_vector(&w);

  return lambda;
}

void matrix_copy(const matrix *A, matrix *B)
{
  assert(A->rows == B->rows);
  assert(A->cols == B->cols);
  const int rows = A->rows;
  const int cols = A->cols;
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= cols; j++)
    {
      mgetNew(B, i, j) = mgetNew(A, i, j);
    }
  }
}

double shiftedInverse_power_iteration(const matrix *A, const vector *v, double mu, double TOL, int MaxIterations)
{
  const int rows = A->rows;
  const int cols = A->cols;
  const int size = v->size;
  assert(rows == cols);
  assert(rows == size);

  vector w = new_vector(rows);
  double lambda = 0, lambda_old, error;

  // Update lamda(0) iteration
  vector Av = matrix_vector_mult(A, v);
  lambda_old = vector_dot_mult(v, &Av);
  // print_scalar(&lambda_old);

  // Compute shifted matrix A - mu*I
  matrix As = new_matrix(rows, cols);
  matrix_copy(A, &As);
  for (int j = 1; j <= rows; j++)
  {
    mgetNew(&As, j, j) = mgetNew(&As, j, j) - mu;
  }

  // Normalize the initial vector
  double norm = vector_norm(v);
  vector_scale(v, 1.0 / norm);

  // Perform the shifted inverse power iteration
  for (int i = 0; i < MaxIterations; i++)
  {
    // Solve (A - mu*I)u = v for u
    w = solve(&As, v);

    // Normalize w and w=w/||w||
    norm = vector_norm(&w);
    vector_scale(&w, 1.0 / norm);
    // Copy u to v for the next iteration
    vector_copy(v, &w);

    // Update lamda(0) iteration
    vector Av = matrix_vector_mult(A, v);
    lambda = vector_dot_mult(v, &Av);

    // Compute the relative error in lambda
    if (i > 0)
    {
      error = fabs(lambda - lambda_old); // / fabs(lambda);
      // printf("[ShiftedInverse] error [%i][%.5f-%.5f] %.5f\n",i,lambda,lambda_old,error);
      if (error < TOL)
      {
        printf("\n Maximum number of Iterations for solving eigen value for A by Shifted Inverse Power Iteration is %d\n", i);
        break;
      }
      else
      {
        lambda_old = lambda;
      }
    }
  }

  delete_matrix(&As);
  delete_vector(&w);

  return lambda;
}

double RayleighQuotient_iteration(const matrix *A, const vector *v, double TOL, int MaxIterations)
{
  const int rows = A->rows;
  const int cols = A->cols;
  const int size = v->size;
  assert(rows == cols);
  assert(rows == size);

  vector w = new_vector(rows);
  double lambda = 0, lambda_old, error;

  // Update lamda(0) iteration
  vector Av = matrix_vector_mult(A, v);
  lambda_old = vector_dot_mult(v, &Av);
  // print_scalar(&lambda_old);

  // Create an A shift matrix, As
  matrix As = new_matrix(rows, cols);
  matrix_copy(A, &As);

  // Normalize the initial vector
  double norm = vector_norm(v);
  vector_scale(v, 1.0 / norm);

  // Perform the shifted inverse power iteration
  for (int i = 0; i < MaxIterations; i++)
  {
    // update A-lambda_old*I
    for (int j = 1; j <= rows; j++)
    {
      mgetNew(&As, j, j) = mgetNew(&As, j, j) - lambda_old;
    }

    // Solve (A - lambdaold*I)u = v for u
    w = solve(&As, v);

    // Normalize w and w=w/||w||
    norm = vector_norm(&w);
    vector_scale(&w, 1.0 / norm);
    // Copy w to v for the next iteration
    vector_copy(v, &w);

    // Update lamda(0) iteration
    vector Av = matrix_vector_mult(A, v);
    lambda = vector_dot_mult(v, &Av);

    // Compute the relative error in lambda
    if (i > 0)
    {
      error = fabs(lambda - lambda_old); // / fabs(lambda);
      // printf("[RQ] error [%i][%.5f-%.5f] %.5f\n",i,lambda,lambda_old,error);
      if (error < TOL)
      {
        printf("\n Maximum number of Iterations for solving eigen value for A by Rayleigh Quotient Iteration is %d\n", i);
        break;
      }
      else
      {
        lambda_old = lambda;
      }
    }
  }

  delete_matrix(&As);
  delete_vector(&w);

  return lambda;
}
