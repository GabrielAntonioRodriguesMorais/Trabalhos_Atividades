#include <stdio.h>

int binarioParaDecimal(int binario)
{
    if (binario == 0)
        return 0;
    return (binario % 10) + 2 * binarioParaDecimal(binario / 10);
}

int main()
{
    int binario, decimal;

    scanf("%d", &binario);

    decimal = binarioParaDecimal(binario);
    printf("%d", decimal);

    return 0;
}
