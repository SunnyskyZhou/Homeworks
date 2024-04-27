#include<stdio.h>
int main()
{
	int i=1;
	float e=1,n=1;
	while(1/n>=1e-7)
	{
	n=n*i;
	e=e+1/n;
	i++;
	}
	printf("e=%f\n",e);
}
