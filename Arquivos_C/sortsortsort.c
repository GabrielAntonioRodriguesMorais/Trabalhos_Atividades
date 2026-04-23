#include <stdio.h>
#include <math.h>

void imprimeVetor(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int n, m;

    do
    {
        scanf("%d %d", &n, &m);
        int vet[n], restos[n], vet2[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vet[i]);
        }

        for (int i = 0; i < n; i++)
        {
            restos[i] = vet[i] % m;
        }

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (restos[i] == 0)
            {
                vet2[j] = vet[i];
                j++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vet2[i] % 2 == 0)
            {
                swap(vet2[i], vet2[i + 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (restos[i] == 1)
            {
                vet2[j] = vet[i];
                j++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vet2[i] % 2 == 0)
            {
                swap(vet2[i], vet2[i + 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (restos[i] == 2)
            {
                vet2[j] = vet[i];
                j++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vet2[i] % 2 == 0)
            {
                swap(vet2[i], vet2[i + 1]);
            }
        }

        imprimeVetor(n, vet);
        printf("\n");
        imprimeVetor(n, restos);
        printf("\n");
        imprimeVetor(n, vet2);
        printf("\n");

    } while (n != 0 || m != 0);
}