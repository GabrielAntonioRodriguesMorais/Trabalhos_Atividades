#include <stdio.h>

int main()
{
    int n, soma = 0, acc = 0;

    scanf("%d", &n);

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > 0)
        {
            soma += vet[i];
        }
        else
            acc++;
    }
    printf("%d %d", acc, soma);
}