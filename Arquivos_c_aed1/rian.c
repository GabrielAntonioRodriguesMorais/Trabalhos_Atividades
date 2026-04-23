#include <stdio.h>
#include <stdlib.h>

int menorDif(int a, int b, int c, int d)
{
    int dif1 = abs((a + b) - (c + d));
    int dif2 = abs((a + c) - (b + d));
    int dif3 = abs((a + d) - (c + b));
    int menor = dif1;

    if (dif2 < menor)
    {
        menor = dif2;
    }
    if (dif3 < menor)
    {
        menor = dif3;
    }
    return menor;
}

int main()
{
    int a, b, c, d, resultado;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    resultado = menorDif(a, b, c, d);

    printf("%d", resultado);

    return 0;
}
