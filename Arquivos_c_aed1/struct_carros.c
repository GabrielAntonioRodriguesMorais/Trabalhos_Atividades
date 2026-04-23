#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct carros
{
    char marca[50];
    int ano;
    float preco;
} carros;

carros cadastroCarros()
{
    carros c;
    fgets(c.marca, 50, stdin);
    c.marca[strcspn(c.marca, "\n")] = '\0';
    scanf("%d", &c.ano);
    scanf("%f", &c.preco);
    getchar();
    return c;
}

int main()
{
    int n;
    float precoMax;

    scanf("%d", &n);
    getchar();

    carros carros[n];

    for (int i = 0; i < n; i++)
    {
        carros[i] = cadastroCarros();
    }

    scanf("%f", &precoMax);
    printf("Carros com preco menor que %.2f:\n", precoMax);

    for (int i = 0; i < n; i++)
    {
        if (carros[i].preco < precoMax)
        {
            printf("Marca: %s, Ano: %d, Preco: %.2f\n", carros[i].marca, carros[i].ano, carros[i].preco);
        }
    }

    return 0;
}
