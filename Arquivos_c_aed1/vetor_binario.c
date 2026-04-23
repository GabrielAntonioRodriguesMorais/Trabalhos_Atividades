#include <stdio.h>
#include <math.h>

int main()
{
    int n, decimal = 0, conversao = 0;

    scanf("%d", &n);

    int binario[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &binario[i]);
    }

    for (int i = 0; i < n; i++)
    {
        conversao = binario[i] * (pow(2, n - 1 - i));
        decimal += conversao;
    }
    printf("%d", decimal);
}