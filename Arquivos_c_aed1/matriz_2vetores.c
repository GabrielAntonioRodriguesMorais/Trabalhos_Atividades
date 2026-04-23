#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *Vetor(int tamanho)
{
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        *(vetor + i) = (rand() % 20) + 1;
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

int *preencheMatriz1(int n, int m)
{
    int *mat1 = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(mat1 + i * m + j) = (rand() % 20) + 1;
        }
    }
    return mat1;
}

int maiorVetor(int tamanho, int *vetor)
{
    int maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (*(vetor + i) > maior)
        {
            maior = *(vetor + i);
        }
    }
    return maior;
}

int menorVetor(int tamanho, int *vetor)
{
    int menor = 21;
    for (int i = 0; i < tamanho; i++)
    {
        if (*(vetor + i) < menor)
        {
            menor = *(vetor + i);
        }
    }
    return menor;
}

int *preencheMatriz2(int n, int m, int produto, int *mat)
{
    int *mat2 = (int *)malloc((n * m) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            *(mat2 + i * m + j) = *(mat + i * m + j) + produto;
        }
    }
    return mat2;
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

void somaParesMatriz(int n, int m, int *mat2)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(mat2 + i * m + j) % 2 == 0)
            {
                soma += *(mat2 + i * m + j);
            }
        }
        printf("Soma dos pares da linha %d da Matriz 2 = %d\n", i + 1, soma);
        soma = 0;
    }
}

void quantidadeMatriz2(int n, int m, int *matriz2)
{
    int cont = 0;
    for (int j = 0; j < m; j++) // Percorre cada coluna
    {
        for (int i = 0; i < n; i++) // Percorre cada linha da coluna
        {
            if (*(matriz2 + i * m + j) >= 1 && *(matriz2 + i * m + j) <= 10)
            {
                cont++;
            }
        }
        printf("%d numeros entre 1 e 5 na coluna %d\n", cont, j + 1);
        cont = 0;
    }
}

int main()
{
    int n, m, produto;
    int *vet1, *vet2, *mat1, *mat2;
    scanf("%d", &n);
    scanf("%d", &m);
    srand(time(NULL));

    printf("Vetor 1:\n");
    vet1 = Vetor(n);
    imprimeVetor(n, vet1);
    printf("Maior Elemento: %d\n", maiorVetor(n, vet1));
    printf("\n");

    printf("Vetor 2:\n");
    vet2 = Vetor(m);
    imprimeVetor(m, vet2);
    printf("Menor Elemento: %d\n", menorVetor(m, vet2));
    printf("\n");

    printf("Matriz 1:\n");
    mat1 = preencheMatriz1(n, m);
    imprimeMatriz(n, m, mat1);
    printf("\n");

    produto = maiorVetor(n, vet1) * menorVetor(m, vet2);

    printf("Matriz 2:\n");
    mat2 = preencheMatriz2(n, m, produto, mat1);
    imprimeMatriz(n, m, mat2);

    printf("\n");
    somaParesMatriz(n, m, mat2);

    printf("\n");
    quantidadeMatriz2(n, m, mat1);
}