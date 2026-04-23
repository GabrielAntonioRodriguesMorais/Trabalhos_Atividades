#include <stdio.h>

int pot(int base, int expoente)
{
    if (expoente == 1)
    {
        return base;
    }
    else
    {
        return base * pot(base, expoente - 1);
    }
}

int main()
{
    int a, b, result;

    scanf("%d", &a);
    scanf("%d", &b);
    result = pot(a, b);
    printf("%d\n", result);

    return 0;
}