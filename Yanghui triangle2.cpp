#include<stdio.h>

#define N  8

int main()
{
    int i=0,j=0;
    int a[N][N]={0};
    for(i=0;i<N;i++)
        a[i][0]=a[i][i]=1;
    for(i=2;i<N;i++)
        for(j=1;j<i;j++)
        a[i][j]=a[i-1][j-1]+a[i-1][j];

        for(i=0;i<N;i++)
        {
            for(j=0;j<=i;j++)
                printf("%5d",a[i][j]);
            printf("\n");
        }
}
