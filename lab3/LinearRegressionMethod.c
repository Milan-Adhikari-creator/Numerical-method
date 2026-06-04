//LinearRegression

#include <stdio.h>

#define S 50

int main() {
    int n, i;
    float x[S], y[S];
    float sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0;
    float a, b;

    printf("How many data points? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }

    for(i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumXY += x[i] * y[i];
    }

    b = (n * sumXY - sumX * sumY) /
        (n * sumX2 - sumX * sumX);

    a = (sumY - b * sumX) / n;

    printf("\nIntercept (a) = %.2f", a);
    printf("\nSlope (b) = %.2f", b);
    printf("\nBest fit equation: y = %.2f + %.2fx\n", a, b);

    return 0;
}