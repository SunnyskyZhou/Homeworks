#include<stdio.h>

int main()
{
    int a[10][10];
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)   a[i][j]=0; //��ʼ������
    for(i=0;i<10;i++)
    {
        a[i][i]=1;
        a[i][0]=1;
    }
    for(i=2;i<10;i++)
        for(j=1;j<i;j++)  //���������ڸ���
        a[i][j]=a[i-1][j-1]+a[i-1][j];
    for(i=0;i<10;i++)  //���������
    for(j=0;j<10;j++)
    {
        if(a[i][j]!=0)  printf("%5d",a[i][j]);
        else if(a[i][j]==0)
        {
            printf("\n");
            break;
        }
    }
}
