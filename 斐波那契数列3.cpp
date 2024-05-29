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
    printf("请输入一个整数： ");
    scanf("%d", &n);
    printf("斐波那契数列第%d项为： %d", n, fib(n));
    return 0;
}
