#include <stdio.h>

int main()
{
    int vet[10];

    for (int i = 1; i < 11; i++)
    {
        vet[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        if (vet[i])
            ;
    }
}