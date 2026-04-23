#include <stdio.h>

void tabela(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", i * j);
        }
        printf("\n");
    }
}

int main()
{
    int numero;

    scanf("%d", &numero);

    if (numero >= 1 && numero <= 9)
    {
        tabela(numero);
    }
    else
    {
        printf("Número fora do intervalo.\n");
    }

    return 0;
}
