#include <stdio.h>

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n;
    printf("������һ�������� ");
    scanf("%d", &n);
    printf("쳲��������е�%d��Ϊ�� %d", n, fib(n));
    return 0;
}
