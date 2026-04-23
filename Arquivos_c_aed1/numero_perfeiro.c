#include <stdio.h>

int main()
{
    int n, num, soma = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        for (int j = 1; j <= num; j++)
        {

            if (num % j == 0 && j != num)
            {
                soma += j;
            }
        }

        if (soma == num)
        {
            printf("%d eh perfeito\n", num);
            soma = 0;
        }
        else
        {
            printf("%d nao eh perfeito\n", num);
            soma = 0;
        }
    }

    return 0;
}
