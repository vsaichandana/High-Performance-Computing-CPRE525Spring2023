#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SamplePoly_Chebyshev(const int N, const int NumPts, const double b[], const double x[], double y[]);
void SamplePoly_Legendre(const int N, const int NumPts, const double b[], const double x[], double y[]);
void WritePoly(const int NumPts, const double x[], double y[]);

int main()
{
    const int Nmax = 5;
    int N;

    // read-in polynomial degree
    printf("\n Input polynomial degree (0-%i): ", Nmax);
    scanf("%i", &N);
    if (N < 0 || N > Nmax)
    {
        printf(" Invalid value N = %i.\n", N);
        printf(" N must satisfy: 0 <= N <= %i\n\n", Nmax);
        exit(1);
    }
    printf("\n");
    // read-in coefficients
    double b[Nmax + 1];
    for (int i = 0; i <= N; i++)
    {
        printf(" Set b[%i]: ", i);
        scanf("%lf", &b[i]);
    }
    printf("\n");

    // set x-coordinates
    const int NumPts = 21;
    double x[NumPts];
    for (int i = 0; i < NumPts; i++)
    {
        x[i] = -1.0 + i * (2.0 / (1.0 * (NumPts - 1)));
    }
    // Calculate polynomial at x-coordinates
    double y[NumPts];
    SamplePoly_Chebyshev(N, NumPts, b, x, y);
    // Write to file
    WritePoly(NumPts, x, y);
    // Call python script to plot
    system("python3 PlotPoly.py");

    return 0;
}

void SamplePoly_Chebyshev(const int N, const int NumPts, const double b[], const double x[], double y[])
{
    for (int i = 0; i < NumPts; i++)
    {
        const double a = x[i];
        double phi;
        y[i] = b[0];
        for (int k = 1; k <= N; k++)
        {
            switch (k)
            {
            case 1:
                phi = a;
                break;
            case 2:
                phi = (2.0 * pow(a, 2) - 1.0);
                break;
            case 3:
                phi = (4.0 * pow(a, 3) - 3.0 * a);
                break;
            case 4:
                phi = (8 * pow(a, 4) - 8 * pow(a, 2) + 1);
                break;
            case 5:
                phi = (16 * pow(a, 5) - 20 * pow(a, 3) + 5*a);
                break;
            default:
                printf("\n Error \n.");
                exit(1);
            }
            y[i] += b[k] * phi;
        }
    }
}

void SamplePoly_Legendre(const int N, const int NumPts, const double b[], const double x[], double y[])
{
    for (int i = 0; i < NumPts; i++)
    {
        const double a = x[i];
        double phi;
        y[i] = b[0];
        for (int k = 1; k <= N; k++)
        {
            switch (k)
            {
            case 1:
                phi = sqrt(3.0) * a;
                break;
            case 2:
                phi = 0.5 * sqrt(5.0) * (3.0 * pow(a, 2) - 1.0);
                break;
            case 3:
                phi = 0.5 * sqrt(7.0) * (5.0 * pow(a, 3) - 3.0 * a);
                break;
            case 4:
                phi = 0.125 * (105 * pow(a, 4) - 90 * pow(a, 2) + 9);
                break;
            default:
                printf("\n Error \n.");
                exit(1);
            }
            y[i] += b[k] * phi;
        }
    }
}

void WritePoly(const int NumPts, const double x[], double y[])
{
    FILE *fptr = fopen("polydata.txt", "w");
    for (int i = 0; i < NumPts; i++)
    {
        fprintf(fptr, "%lf %lf\n", x[i], y[i]);
    }
    fclose(fptr);
}
