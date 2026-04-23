#include <stdio.h>

void media(int n, float notas[])
{
    float soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += notas[i];
    }
    printf("%.1f ", soma / n);
}

void maiorNota(int n, float notas[])
{
    float maiorNota;
    maiorNota = notas[0];
    for (int i = 0; i < n; i++)
    {
        if (maiorNota < notas[i])
        {
            maiorNota = notas[i];
        }
    }
    printf("%.1f ", maiorNota);
}

void menorNota(int n, float notas[])
{
    float menorNota;
    menorNota = notas[0];
    for (int i = 0; i < n; i++)
    {
        if (menorNota > notas[i])
        {
            menorNota = notas[i];
        }
    }
    printf("%.1f ", menorNota);
}

int main()
{
    int n;

    scanf("%d", &n);

    float notas[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &notas[i]);
    }

    maiorNota(n, notas);
    menorNota(n, notas);
    media(n, notas);
}