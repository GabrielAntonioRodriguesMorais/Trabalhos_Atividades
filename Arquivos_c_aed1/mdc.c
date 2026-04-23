#include <stdio.h>

int mdc(int a, int b)
{
    int aux, resto;
    if (b > a)
    {
        aux = a;
        a = b;
        b = aux;
    }
    while (b != 0)
    {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main()
{
    int n1, n2, saida;

    scanf("%d", &n1);
    scanf("%d", &n2);

    saida = mdc(n1, n2);

    printf("o mdc entre %d e %d e %d", n1, n2, saida);
}