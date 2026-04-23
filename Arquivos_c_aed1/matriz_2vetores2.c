#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *preencheMatriz1(int n, int m)
{
    int *mat = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(mat + i * m + j) = (rand() % 50) + 1;
        }
    }
    return mat;
}

void imprimeMatriz(int n, int m, int *mat)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d ", *(mat + i * m + j));
        }
        printf("\n");
    }
}

int *maiorLinha(int n, int m, int *matriz)
{
    int maior = 0;
    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(matriz + i * m + j) > maior)
            {
                maior = *(matriz + i * m + j);
            }
        }
        *(vetor + i) = maior;
        maior = 0;
    }
    return vetor;
}

int *menorColuna(int n, int m, int *matriz)
{
    int menor = 21;
    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(matriz + i * m + j) > menor)
            {
                menor = *(matriz + i * m + j);
            }
        }
        *(vetor + i) = menor;
        menor = 21;
    }
    return vetor;
}

void imprimeVetor(int n, int *vetor)
{
    for (int i = 0; i < n; i++)

    {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}

int main()
{
    int n, m;
    int *vet1, *vet2, *mat;
    scanf("%d", &n);
    scanf("%d", &m);
    srand(time(NULL));

    printf("Matriz :\n");
    mat = preencheMatriz1(n, m);
    imprimeMatriz(n, m, mat);
    printf("\n");

    printf("Vetor 1:\n");
    vet1 = maiorLinha(n, m, mat);
    imprimeVetor(n, vet1);
    printf("\n");

    printf("Vetor 2:\n");
    vet2 = menorColuna(n, m, mat);
    imprimeVetor(n, vet2);
    printf("\n");
}