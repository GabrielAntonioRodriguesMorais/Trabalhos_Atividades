#include <stdio.h>

void preencheArray(char array[], int n)
{
    int qnt_pares = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            array[i] = 'P';
            qnt_pares++;
        }
        else
            array[i] = 'I';
    }
    printf("%d pares\n", qnt_pares);
}
void imprimeArray(char array[], int n)
{
    printf("%d\n", n);
    if (n > 0)
    {
        imprimeArray(array, n - 1);
        printf("%d ", *(array + n - 1));
        return;
    }
}

void enderecosArray(char array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("indice %d: %p \n", i, &array[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char array[n];

    preencheArray(array, n);
    imprimeArray(array, n);
    printf("\n");
    enderecosArray(array, n);
}