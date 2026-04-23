#include <stdio.h>

int main()
{
    int vet[10], n;

    scanf("%d", &n);

    for (int i = 0; i < 10; i++)
    {
        vet[i] = n;
        n *= 2;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("N[%d] = %d\n", i, vet[i]);
    }
}