#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1)leitura de um vetor
// versao 1
void lerVetor1(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        vet[i] = rand() % 100;
    }
}
// versao 2
void lerVetor2(int vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        *(vet + i) = rand() % 100;
    }
}
// versao 3
void lerVetor3(int n, int *aux)
{
    for (int i = 0; i < n; i++)
    {
        *(aux + i) = rand() % 100;
    }
}

// 2) imprimir um vetor
// versao 1
void imprimirVetor1(int *vet, int n)
{
    printf("VETOR 1 : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}
// versao 2
void imprimirVetor2(int *vet, int n)
{
    printf("VETOR 2 : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(vet + i));
    }
}
// versao 3
void imprimirVetor3(int n, int *aux)
{
    printf("VETOR 3 : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(aux + i));
    }
}

// 3)intercalar 2 vetores
int *intercalarVetores(int vetor1[], int vetor2[], int n1, int n2)
{

    int *vetor3 = (int *)malloc((n1 + n2) * sizeof(int));

    int menorTamanho = n1 > n2 ? n2 : n1;
    int i, j = 0;

    for (i = 0; i < menorTamanho; i++)
    {
        vetor3[j] = vetor1[i];
        j++;
        vetor3[j] = vetor2[i];
        j++;
    }

    while (i < n1)
    {
        vetor3[j] = vetor1[i];
        j++;
        i++;
    }

    while (i < n2)
    {
        vetor3[j] = vetor2[i];
        j++;
        i++;
    }

    return vetor3;
}

int main()
{
    // I
    int n;
    int *aux, *p;

    scanf("%d", &n);

    int vet[n];
    srand(time(NULL));

    // II
    lerVetor1(vet, n);
    imprimirVetor1(vet, n);
    printf("\n");

    lerVetor2(vet, n);
    imprimirVetor2(vet, n);
    printf("\n");

    aux = vet;
    lerVetor3(n, aux);
    imprimirVetor3(n, aux);
    printf("\n");

    int n1, n2, n3 = 0;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int vetor1[n1], vetor2[n2];
    lerVetor1(vetor1, n1);
    lerVetor1(vetor2, n2);

    n3 = n1 + n2;

    imprimirVetor1(vetor1, n1);
    printf("\n");

    imprimirVetor2(vetor2, n2);
    printf("\n");

    p = intercalarVetores(vetor1, vetor2, n1, n2);

    imprimirVetor3(n3, p);
}