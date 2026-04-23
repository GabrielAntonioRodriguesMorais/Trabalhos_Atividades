#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *preencheMatriz(int n, int m)
{
    int *matriz = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(matriz + i * m + j) = rand() % 10;
        }
    }
    return matriz;
}

void imprimirMatriz(int n, int m, int *matriz)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d ", *(matriz + i * m + j));
            i < m ? printf("|") : 0;
        }
        printf("\n");
    }
}

int maiorMatriz(int n, int m, int *matriz)
{
    int Maiornum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(matriz + i * m + j) > Maiornum)
            {
                Maiornum = *(matriz + i * m + j);
            }
        }
    }
    return Maiornum;
}

int *preencheMatriz2(int n, int m, int maior)
{
    int *matriz2 = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(matriz2 + i * m + j) = *(matriz2 + i * m + j) * maior;
        }
    }
    return matriz2;
}

int main()
{
    int n, m, maior;
    int *p, *p2;
    scanf("%d", &n);
    scanf("%d", &m);
    srand(time(NULL));

    p = preencheMatriz(n, m);
    imprimirMatriz(n, m, p);
    maior = maiorMatriz(n, m, p);
    // printf("%d", maior);
    p2 = preencheMatriz2(n, m, maior);
    imprimirMatriz(n, m, p2);
}