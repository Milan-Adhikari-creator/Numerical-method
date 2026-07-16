#include <stdio.h>
float f(float x, float y)
{
    return x + y;
}

int main()
{
    float x0, y0, h, xn;
    float x, y;
    float k1, k2;

    printf("Enter initial value x0: ");
    scanf("%f", &x0);

    printf("Enter initial value y0: ");
    scanf("%f", &y0);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter final value xn: ");
    scanf("%f", &xn);

    x = x0;
    y = y0;

    printf("\n x\t\t y\n");
    printf("%.2f\t\t%.6f\n", x, y);

    while (x < xn)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h, y + k1);

        y = y + (k1 + k2) / 2.0;
        x = x + h;

        printf("%.2f\t\t%.6f\n", x, y);
    }

    return 0;
}
