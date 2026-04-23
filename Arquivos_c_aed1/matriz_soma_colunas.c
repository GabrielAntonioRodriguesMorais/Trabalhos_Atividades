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

int *vetorSoma(int n, int m, int *mat)
{
    int soma = 0;
    int *vet = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            soma += *(mat + j * m + i);
        }
        *(vet + i) = soma;
        soma = 0;
    }
    return vet;
}

int main()
{
    int n, m;
    int *mat, *vet;
    scanf("%d %d", &n, &m);

    mat = preencheMatriz(n, m);
    vet = vetorSoma(n, m, mat);

    for (int i = 0; i < m; i++)
    {
        printf("%d ", *(vet + i));
    }
}