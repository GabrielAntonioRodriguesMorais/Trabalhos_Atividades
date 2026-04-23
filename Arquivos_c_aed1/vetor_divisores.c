#include <stdio.h>
#include <math.h>

int main()
{
    int numeros[10], divisao[5], acc = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numeros[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &divisao[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Numero %d :\n", numeros[i]);
        for (int j = 0; j < 5; j++)
        {
            if (numeros[i] % divisao[j] == 0)
            {
                printf("Divisivel por %d na posicao %d\n", divisao[j], j);
                acc++;
            }
        }
        if (acc == 0)
        {
            printf("Nao possui divisores no segundo vetor");
        }
        printf("\n");
    }
}