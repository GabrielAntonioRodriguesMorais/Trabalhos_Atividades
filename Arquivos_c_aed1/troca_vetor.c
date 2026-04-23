#include <stdio.h>

int main()
{
    int vet[20], temp;

    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &vet[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        temp = vet[i];
        vet[i] = vet[19 - i];
        vet[19 - i] = temp;
    }
    for (int i = 0; i < 20; i++)
    {
        printf("N[%d] = %d\n", i, vet[i]);
    }
}