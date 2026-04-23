#include <stdio.h>

int main()
{
    int num1, num2, soma1 = 0, soma2 = 0;

    scanf("%d", &num1);
    scanf("%d", &num2);
    for (int i = 1; i <= num1; i++)
    {
        if (num1 % i == 0 && i != num1)
        {
            soma1 += i;
        }
    }
    for (int j = 1; j <= num2; j++)
    {
        if (num2 % j == 0 && j != num2)
        {
            soma2 += j;
        }
    }
    if (soma1 == num2 || soma2 == num1)
    {
        printf("%d e %d sao amigaveis\n", num1, num2);
        soma1 = 0;
        soma2 = 0;
    }
    else
    {
        printf("%d e %d nao sao amigaveis\n", num1, num2);
        soma1 = 0;
        soma2 = 0;
    }

    return 0;
}
