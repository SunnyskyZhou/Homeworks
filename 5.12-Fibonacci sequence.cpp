#include<stdio.h>
#define n 100

int main()
{
    int data[n];
    int i;
    data[0] = 0;
    data[1] = 1;
    for(int i=2;i<40;i++)
        data[i]=data[i-1]+data[i-2];
    for(i=0;i<40;i++)
    {
        printf("%10d\t",data[i]);

    }
}
