#include <stdio.h>

int main()
{
    int n, temp, resto;

    scanf("%d", &n);

    for (int i = n; n > 0; i--)
    {
        temp = n / 2;
        resto = n % 2;
        n = temp;
        printf("%d", resto);
        }
}