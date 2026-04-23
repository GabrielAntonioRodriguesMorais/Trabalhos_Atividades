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
            scanf("%d", &*(matriz + i * m + j));
        }
    }
    return matriz;
}

void somaBorda(int n, int m, int *matriz)
{
    int soma = 0;
    for (int j = 0; j < m; j++)
    {
        soma += *(matriz + 0 * m + j);
        soma += *(matriz + (n - 1) * m + j);
    }

    for (int i = 1; i < n - 1; i++)
    {
        soma += *(matriz + i * m + 0);
        soma += *(matriz + i * m + (m - 1));
    }
    printf("%d", soma);
}

int main()
{
    int n, m;
    int *mat;
    scanf("%d %d", &n, &m);

    mat = preencheMatriz(n, m);
    somaBorda(n, m, mat);
}