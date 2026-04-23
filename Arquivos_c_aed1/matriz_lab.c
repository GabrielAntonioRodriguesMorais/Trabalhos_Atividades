#include <stdio.h>
#include <stdlib.h>

void preencheMatriz(int n, int m, int matriz[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = i + j;
        }
    }
}

void imprimeMatriz(int n, int m, int matriz[n][m])
{
    printf("Matriz 1:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int somaDiagonal(int n, int m, int matriz[n][m])
{
    int soma = 0;
    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j < m - i - 1)
                {
                    soma += matriz[i][j];
                }
            }
        }
    }
    else
    {
        return 0;
    }

    return soma;
}
void preencheMatriz2(int n, int m, int *matriz)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(matriz + i * m + j) = i + j;
        }
    }
}

void imprimeMatriz2(int n, int m, int *matriz)
{
    printf("Matriz 2:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(matriz + i * m + j));
        }
        printf("\n");
    }
}
int *preencheMatriz3(int n, int m)
{
    int *matriz = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(matriz + i * m + j) = i + j;
        }
    }
    return matriz;
}

void imprimeMatriz3(int n, int m, int *matriz)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(matriz + i * m + j));
        }
        printf("\n");
    }
}

int main()
{
    int n, m, saida;
    int *p;

    scanf("%d", &n);
    scanf("%d", &m);

    int matriz[n][m];

    preencheMatriz(n, m, matriz);
    imprimeMatriz(n, m, matriz);
    saida = somaDiagonal(n, m, matriz);

    printf("\n");

    printf("soma = %d", saida);

    printf("\n");

    preencheMatriz2(n, m, matriz);
    imprimeMatriz2(n, m, matriz);

    printf("\n");

    p = preencheMatriz3(n, m);
    imprimeMatriz3(n, m, p);
}
