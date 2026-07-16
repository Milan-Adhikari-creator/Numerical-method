#include <stdio.h>
float f(float x, float y)
{
    return x + y;
}
int main()
{
    float x0, y0, h, xn, x, y;

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
        y = y + h * f(x, y);
        x = x + h;
        printf("%.2f\t\t%.6f\n", x, y);
    }
    return 0;
}
