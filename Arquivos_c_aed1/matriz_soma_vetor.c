#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *preencheMatriz1(int n, int m)
{
    int *mat1 = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(mat1 + i * m + j) = rand() % 20;
        }
    }
    return mat1;
}

void imprimeMatriz1(int n, int m, int *mat1)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d ", *(mat1 + i * m + j));
        }
        printf("\n");
    }
}

int *vetorSoma(int n, int m, int *mat1)
{
    int soma = 0;
    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            soma += *(mat1 + i * m + j);
        }
        *(vetor + i) = soma;
        soma = 0;
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

int *preencheMatriz2(int n, int m, int *vetor, int *mat1)
{
    int *mat2 = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(mat2 + i * m + j) = *(mat1 + i * m + j) + *(vetor + i);
        }
    }
    return mat2;
}

int main()
{
    int n, m;
    int *vetor, *mat1, *mat2;
    scanf("%d", &n);
    scanf("%d", &m);
    srand(time(NULL));

    printf("Matriz Primaria:\n");
    mat1 = preencheMatriz1(n, m);
    imprimeMatriz1(n, m, mat1);
    printf("\n");
    printf("Vetor Soma:\n");
    vetor = vetorSoma(n, m, mat1);
    imprimeVetor(n, vetor);
    printf("\n");
    printf("Matriz Somas:\n");
    mat2 = preencheMatriz2(n, m, vetor, mat1);
    imprimeMatriz1(n, m, mat2);
}