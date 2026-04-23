#include <stdio.h>

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, saida;

    scanf("%d", &n);

    saida = fib(n);

    printf("%d", saida);
}