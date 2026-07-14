#include <stdio.h>
#include <math.h>
#define SIZE 10
int main()
{
    float a[SIZE][SIZE+1],x[SIZE],ratio,temp;
    int i,j,k,n,maxRow;
    printf("Enter number of unknowns:");
    scanf("%d",&n);
    printf("Enter coefficients of augmented matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("a[%d][%d]=",i+1,j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    for(i=0;i<n-1;i++)
    {
        maxRow=i;
        for(j=i+1;j<n;j++)
        {
            if(fabs(a[j][i])>fabs(a[maxRow][i]))
                maxRow=j;
        }
        if(maxRow!=i)
        {
            for(k=0;k<=n;k++)
            {
                temp=a[i][k];
                a[i][k] = a[maxRow][k];
                a[maxRow][k] = temp;
            }
        }
        if(fabs(a[i][i]) <1e-6)
        {
            printf("Mathematical Error! Singular Matrix.\n");
            return 1;
        }
        for(j=i+1;j<n;j++)
        {
            ratio=a[j][i]/a[i][i];

            for(k=i;k<=n;k++)
            {
                a[j][k]=a[j][k]-ratio*a[i][k];
            }
        }
    }
    x[n-1]=a[n-1][n]/a[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
        x[i]=a[i][n];

        for(j=i+1;j<n;j++)
        {
            x[i]=x[i]-a[i][j]*x[j];
        }

        x[i]=x[i]/a[i][i];
    }
    printf("\nUpper Triangular Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%8.3f",a[i][j]);
        }
        printf("\n");
    }
    printf("\nSolution:\n");
    for(i=0;i<n;i++)
    {
        printf("x%d =%.4f\n",i+1,x[i]);
    }
    return 0;
}