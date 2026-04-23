#include <stdio.h>

int main()
{
    double comprimento, h1, h2, h3, h4, h5, cabo;

    scanf("%lf", &comprimento);

    if (comprimento >= 2.00 && comprimento <= 4.00)
    {
        comprimento = comprimento * 1000;
        h1 = (comprimento * 0.05);
        h2 = h1 * 0.8;
        h3 = h1 * 0.6;
        h4 = h1 * 0.4;
        h5 = h1 * 0.2;
        cabo = ((h1 + h2 + h3 + h4 + h5) * 2) * 4;
        printf("%.2lf", cabo);
    }
    else
        printf("Comprimento invalido!");
}