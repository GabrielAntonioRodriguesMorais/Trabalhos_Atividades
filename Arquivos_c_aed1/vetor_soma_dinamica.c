#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, soma = 0;

    scanf("%d %d", &n1, &n2);

    int vet1[n1], vet2[n2];

    int *vet3 = (int *)malloc((n1 + n2) * sizeof(int));

    if (n1 != n2)
    {
        vet3 = (int *)realloc(vet3, n1 * sizeof(int));
    }

    for (int i = 0; i < n1; i++)
    {
        vet1[i] = i + 1;
    }

    for (int i = 0; i < n2; i++)
    {
        vet2[i] = (i + 1) * 5;
    }

    int n3 = n1 + n2;

    for (int i = 0; i < n3; i++)
    {
        soma = vet1[i] + vet2[i];
        vet3[i] = soma;
        if()
    }
    printf("Vetor 1: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", vet1[i]);
    }
    printf("\n");
    printf("Vetor 2: ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", vet2[i]);
    }
    printf("\n");
    printf("Vetor com a soma: ");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", vet3[i]);
    }
    free(vet3);
}