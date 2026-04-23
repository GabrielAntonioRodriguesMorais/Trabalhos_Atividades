#include <stdio.h>
#include <math.h>

int main()
{
    float peso, altura, imc;

    do
    {
        scanf("%f", &peso);
        scanf("%f", &altura);

        imc = peso / (pow(altura, 2));

        if (imc < 16.9)
        {
            printf("%.2f: muito abaixo do peso\n", imc);
        }
        else if (imc > 17 && imc < 18.4)
        {
            printf("%.2f: Abaixo do peso\n", imc);
        }
        else if (imc > 18.5 && imc < 24.9)
        {
            printf("%.2f: Peso normal\n", imc);
        }
        else if (imc > 25 && imc < 29.9)
        {
            printf("%.2f: Acima do peso\n", imc);
        }
        else
        {
            printf("%.2f: obeso\n", imc);
        }
    } while (0 < peso);
}