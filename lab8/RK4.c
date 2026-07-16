#include <stdio.h>
#define f(x,y) ((y*y - x*x) / (y*y + x*x))
int main()
{
    float x0, y0, xn, h, yn;
    float k1, k2, k3, k4, k;
    int i, n;
    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);
    h = (xn - x0) / n;
    yn = y0;
    printf("\n x\t\t y\n");
    printf("%.4f\t\t%.6f\n", x0, yn);
    for(i = 0; i < n; i++)
    {
        k1 = h * f(x0, yn);
        k2 = h * f(x0 + h/2, yn + k1/2);
        k3 = h * f(x0 + h/2, yn + k2/2);
        k4 = h * f(x0 + h, yn + k3);
        k = (k1 + 2*k2 + 2*k3 + k4) / 6;
        yn = yn + k;
        x0 = x0 + h;
        printf("%.4f\t\t%.6f\n", x0, yn);
    }
 
    return 0;
}        