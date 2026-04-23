#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vet1[10], vet2[10], temp[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        vet1[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++)
    {
        vet2[i] = rand() % 100;
    }

    printf("Antes da troca :\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet1[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet2[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        temp[i] = vet2[9 - i];
    }
    for (int i = 0; i < 10; i++)
    {
        vet2[9 - i] = vet1[i];
    }
    for (int i = 0; i < 10; i++)
    {
        vet1[i] = temp[i];
    }

    printf("\n");

    printf("Depois da troca :\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet1[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vet2[i]);
    }

    return 0;
}