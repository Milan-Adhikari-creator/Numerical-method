#include <stdio.h>
#include <math.h>

#define g(x) ((cos(x) + 1) / 3)

int main()
{
    float x0, x1, e;
    int step = 1, N;

    printf("\nEnter initial guess:\n");
    scanf("%f", &x0);

    printf("Enter tolerable error:\n");
    scanf("%f", &e);

    printf("Enter maximum iteration:\n");
    scanf("%d", &N);

    printf("\nStep\t x0\t\t x1\t\t Error\n");

    do
    {
        x1 = g(x0);

        printf("%d\t %f\t %f\t %f\n", step, x0, x1, fabs(x1 - x0));

        if (fabs(x1 - x0) < e)
        {
            printf("\nRoot is %f\n", x1);
            return 0;
        }

        x0 = x1;
        step++;

        if (step > N)
        {
            printf("\nNot convergent.\n");
            return 0;
        }

    } while (1);

    return 0;
}