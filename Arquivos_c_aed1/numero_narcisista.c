#include <stdio.h>
#include <math.h>

int main()
{
    int n, centena, dezena, unidade, milhar, soma_final;

    do
    {
        scanf("%d", &n);
        milhar = n / 1000;
        centena = (n % 1000) / 100;
        dezena = (n % 100) / 10;
        unidade = (n % 100) % 10;

        if (n > 999 && n < 999999)
        {
            soma_final = (pow(milhar, 4) + pow(centena, 4) + pow(dezena, 4) + pow(unidade, 4));
        }
        else if (n > 99 && n < 999)
        {
            soma_final = (pow(centena, 3) + pow(dezena, 3) + pow(unidade, 3));
        }
        else if (n > 9 && n < 99)
        {
            soma_final = (pow(dezena, 2) + pow(unidade, 2));
        }
        else
        {
            printf("invalido");
        }
        if (soma_final == n)
        {
            printf("%d = %d e narcisista\n", soma_final, n);
        }
        else
        {
            printf("%d != %d, logo nao e narcisista\n", soma_final, n);
        }
    } while (n != 0);

    return 0;
}