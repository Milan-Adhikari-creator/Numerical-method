#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x * x * x - x - 2;
}

int main()
{
    float x0, x1, x2, f0, f1, f2, error;
    int iteration = 1;

    printf("Enter first guess (x0): ");
    scanf("%f", &x0);

    printf("Enter second guess (x1): ");
    scanf("%f", &x1);

    printf("Enter tolerable error: ");
    scanf("%f", &error);

    f0 = f(x0);
    f1 = f(x1);

    // Check validity of initial guesses
    if (f0 * f1 > 0)
    {
        printf("Invalid initial guesses! Root is not bracketed.\n");
        return 0;
    }

    printf("\nIteration\tApproximate Root\n");

    do
    {
        // Regula Falsi Formula
        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%.6f\n", iteration, x2);

        if (fabs(f2) < error)
            break;

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }

        iteration++;

    } while (1);

    printf("\nApproximate Root = %.6f\n", x2);

    return 0;
}