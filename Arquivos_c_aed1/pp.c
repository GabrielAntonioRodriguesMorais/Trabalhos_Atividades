#include <stdio.h>
#include <math.h>

int main()
{
    const int TAM = 10;
    int vet[10] = {1, 2, 3};
    int *ptr = vet;
    for (int i = 0; i < TAM; i++)
    {
        *(ptr++) = pow(i + 1, 2);
    }
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", vet[i]);
    }
    for (int i = 0; i < TAM; i++)
    {
        printf("%4d ", *(--ptr));
    }
}