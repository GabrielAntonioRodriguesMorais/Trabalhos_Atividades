#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    scanf("%d", &n);

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        vet[i] = rand() % 100;
    }
    printf("VETOR :");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", vet[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > 50)
        {
            printf("VETOR[%d] = %d, LOGO MAIOR QUE 50\n", i, vet[i]);
        }
    }
}