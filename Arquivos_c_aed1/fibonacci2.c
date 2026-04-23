#include <stdio.h>

int fib(int n_esimo)
{
    if (n_esimo == 1 || n_esimo == 2)
    {
        return 1;
    }
    else
        return fib(n_esimo - 1) + fib(n_esimo - 2);
}

int main()
{
    int n, saida;

    while (n != 0)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            saida = fib(i);

            printf("%d ", saida);
        }
        printf("\n");
    }
}