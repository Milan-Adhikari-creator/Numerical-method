#include <stdio.h>
int main() 
{
    float x[100], y[100], xp, yp = 0, p;
    int i, j, n;

    printf("Enter number of data: ");
    scanf("%d", &n);

    printf("Enter data:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);

        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }

    printf("Enter interpolation point: ");
    scanf("%f", &xp);

    for(i = 0; i < n; i++) {
        p = 1;

        for(j = 0; j < n; j++) {
            if(i != j) {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp += p * y[i];
    }

    printf("\nInterpolated value at %.3f is %.3f\n", xp, yp);

    return 0;
}