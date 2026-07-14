#include <stdio.h>
#include <math.h>
#define MAX 10
int main()
{
    float a[MAX][MAX + 1], x[MAX], finalX[MAX];
    float factor, temp, max;
    int n, i, j, k, p, q;
    int colIndex[MAX];
    printf("Enter number of variables: ");
    scanf("%d", &n);
    printf("Enter augmented matrix coefficients:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        colIndex[i] = i;
    }
    for (k = 0; k < n - 1; k++)
    {
        max = fabs(a[k][k]);
        p = k;
        q = k;
        for (i = k; i < n; i++)
        {
            for (j = k; j < n; j++)
            {
                if (fabs(a[i][j]) > max)
                {
                    max = fabs(a[i][j]);
                    p = i;
                    q = j;
                }
            }
        }
        if (p != k)
        {
            for (j = 0; j <= n; j++)
            {
                temp = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = temp;
            }
        }
        if (q != k)
        {
            for (i = 0; i < n; i++)
            {
                temp = a[i][k];
                a[i][k] = a[i][q];
                a[i][q] = temp;
            }
            int t = colIndex[k];
            colIndex[k] = colIndex[q];
            colIndex[q] = t;
        }
        if (fabs(a[k][k]) < 1e-7)
        {
            printf("Matrix is singular or nearly singular.\n");
            return 1;
        }
        for (i = k + 1; i < n; i++)
        {
            factor = a[i][k] / a[k][k];

            for (j = k; j <= n; j++)
            {
                a[i][j] -= factor * a[k][j];
            }
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];

        for (j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }

        x[i] /= a[i][i];
    }
    for (i = 0; i < n; i++)
    {
        finalX[colIndex[i]] = x[i];
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %.4f\n", i + 1, finalX[i]);
    }
    return 0;
}