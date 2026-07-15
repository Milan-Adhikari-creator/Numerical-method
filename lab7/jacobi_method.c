#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, n, iter;
    float a[10][10], x[10], x_new[10], sum, error, tol;
    printf("Enter number of variables: ");
    scanf("%d", &n);
    printf("Enter augmented matrix coefficients:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter initial guesses:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter tolerance: ");
    scanf("%f", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &iter);
    for(int k = 1; k <= iter; k++)
    {
        for(i = 0; i < n; i++)
        {
            sum = 0;

            for(j = 0; j < n; j++)
            {
                if(i != j)
                    sum += a[i][j] * x[j];
            }

            x_new[i] = (a[i][n] - sum) / a[i][i];
        }
        error = 0;
        for(i = 0; i < n; i++)
        {
            if(fabs(x_new[i] - x[i]) > error)
                error = fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }
        printf("\nIteration %d:\n", k);
        for(i = 0; i < n; i++)
        {
            printf("x%d = %.6f\t", i + 1, x[i]);
        }
        if(error < tol)
        {
            printf("\n\nConverged after %d iterations.\n", k);
            break;
        }
    }
    printf("\n\nFinal Solution:\n");
    for(i = 0; i < n; i++)
    {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }
    return 0;
}