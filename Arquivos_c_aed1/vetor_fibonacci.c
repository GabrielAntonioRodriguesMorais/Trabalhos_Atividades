#include <stdio.h>

int main()
{
    unsigned long long int a = 0, b = 1, c;
    int vet[60], t, n;

    vet[0] = a;
    vet[1] = b;

    for (int i = 2; i < 60; i++)
    {
        c = a + b;
        vet[i] = c;
        a = b;
        b = c;
    }

    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("Fib(%d) = %d\n", n, vet[n]);
    }
}