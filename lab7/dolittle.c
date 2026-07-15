#include <stdio.h>
int main() {
    int n,i,j,k;
    float A[10][10],L[10][10]={0},U[10][10]={0};
    float B[10],Y[10],X[10],sum;
    printf("Enter order of matrix:");
    scanf("%d",&n);
    printf("Enter coefficient matrix A:\n");
    for(i =0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%f",&A[i][j]);
        }
    }
    printf("Enter constant vector B:\n");
    for(i=0;i<n;i++) {
        scanf("%f",&B[i]);
    }
    for(i=0;i<n;i++) {
        for(k=i;k<n;k++) {
            sum=0;
            for(j=0;j<i;j++)
                sum += L[i][j]*U[j][k];
            U[i][k] = A[i][k]-sum;
        }
        for(k=i;k<n;k++) {
            if(i==k)
                L[i][i]=1;
            else {
                sum=0;
                for(j=0;j<i;j++)
                    sum += L[k][j] * U[j][i];

                L[k][i] = (A[k][i]-sum) / U[i][i];
            }
        }
    }
    for(i=0;i<n;i++) {
        sum=0;
        for(j=0;j<i;j++)
            sum += L[i][j]*Y[j];

        Y[i] = B[i]-sum;
    }
    for(i=n-1;i>=0;i--) {
        sum=0;
        for(j=i+1;j<n; j++)
            sum += U[i][j]*X[j];

        X[i]=(Y[i]-sum)/U[i][i];
    }
    printf("\nL Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            printf("%8.3f", L[i][j]);
        printf("\n");
    }
    printf("\nU Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++)
            printf("%8.3f",U[i][j]);
        printf("\n");
    }
    printf("\nSolution Vector X:\n");
    for(i=0;i<n;i++)
        printf("x%d = %.4f\n",i+1,X[i]);
    return 0;
}