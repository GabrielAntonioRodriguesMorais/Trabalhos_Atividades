#include <stdio.h>

int main()
{
    int n, maiorN, posicao = 0;

    scanf("%d", &n);

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    maiorN = vet[0];

    for (int i = 1; i < n; i++)
    {
        if (maiorN <= vet[i])
        {
            maiorN = vet[i];
            posicao = i;
        }
    }
    printf("%d %d", maiorN, posicao);
}