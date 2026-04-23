#include <stdio.h>

int main()
{
    int n = 0, m = 0, soma;

    scanf("%d %d", &n, &m);

    soma = n + m;

    int A[n], B[m], C[soma];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = A[i];
    }
    for (int i = 0; i < m; i++)
    {
        C[n + i] = B[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    for (int i = 0; i < soma; i++)
    {
        printf("%d ", C[i]);
    }
}