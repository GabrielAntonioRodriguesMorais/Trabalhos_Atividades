#include <stdio.h>

int *preencheVetor(int m)
{
    int vet = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        scanf("%d", vet + i);
    }
    return vet;
}

int *preencheCopia(int m, int *vet)
{
    int *copia = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        *(copia + i) = *(vet + i);
    }
    return copia;
}

int preencheContador(int m)
{
    int *contador = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        *(contador + i) = 0;
    }
    return contador;
}

void verificaRepeticao(int n, int m, int vet, int copia, int contador)
{
}

void imprimeArray(int m, int array)
{
    for (int i = 0; i < m; i++)
    {
        printf("%d", (array + i));
    }
    printf("\n");
}

int main()
{
    int n, m;
    int *copia, *contador;
    int i = n;

    do
    {
        scanf("%d", &n);
        scanf("%d", &m);

        *contador = preencheContador(m);
        int *vet = preencheVetor(m);
        *copia = preencheCopia(m, vet);

        while (i > 0)
        {
        }

    } while (n != 0 && m != 0);
}
