#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minmaxMatriz(int n, int m, int matriz[][m])
{
    int menor = 100, indice_menor, minmax, x, indice_minmax;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
                indice_menor = i;
            }
        }
    }
    for (x = 0; x < m; x++)
    {
        if (minmax < matriz[indice_menor][x])
        {
            minmax = matriz[indice_menor][x];
            indice_minmax = x;
        }
    }
    printf("%d e o min max da matriz na posicao: matriz[%d][%d]", minmax, indice_menor + 1, indice_minmax + 1);
}

void imprimeMatriz(int n, int m, int matriz[][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    int matriz[n][m];
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = (rand() % 30) + 1;
        }
    }

    imprimeMatriz(n, m, matriz);

    minmaxMatriz(n, m, matriz);
}