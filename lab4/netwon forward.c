#include <stdio.h>
int main()
{
    int n,i,j;
    float x[20],y[20][20];
    float value,u,sum,term;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of x and y:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f %f", &x[i], &y[i][0]);
    }
    for(j=1;j<n;j++)
    {
        for(i=0;i<n-j;i++)
        {
            y[i][j]=y[i+1][j-1]-y[i][j-1];
        }
    }
    printf("\nForward Difference Table:\n");
    for(i=0;i<n;i++)
    {
        printf("%f",x[i]);
        for(j=0;j<n-i;j++)
        {
            printf("\t%f",y[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the value of x for interpolation: ");
    scanf("%f",&value);
    u = (value-x[0])/(x[1]-x[0]);
    sum = y[0][0];
    term = 1.0;
    for(i=1;i<n;i++)
    {
        term=term*(u-(i-1))/i;
        sum=sum+term*y[0][i];
    }
    printf("\nInterpolated value at x = %.3f is %.6f\n",value,sum);
    return 0;
}