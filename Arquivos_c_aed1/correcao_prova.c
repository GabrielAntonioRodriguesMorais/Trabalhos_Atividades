#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastroRespostas(int n, int m, char respostas[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &respostas[i][j]);
        }
    }
}

void cadastroGabarito(int m, char gabarito[])
{
    for (int i = 0; i < m; i++)
    {
        scanf(" %c", &gabarito[i]);
    }
}

int *calcularPontuacao(int n, int m, char respostas[][m], char gabarito[])
{
    int cont = 0;
    int *pontuacao = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (respostas[i][j] == gabarito[j])
            {
                cont++;
            }
        }
        *(pontuacao + i) = cont;
        cont = 0;
    }
    return pontuacao;
}

int main()
{
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    char respostas[n][m], gabarito[m];

    cadastroRespostas(n, m, respostas);
    cadastroGabarito(m, gabarito);

    int *p = calcularPontuacao(n, m, respostas, gabarito);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
}
