#include <stdio.h>

int main()
{
    int n;
    double soma, div = 0.00;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        // printf("%d\n", (n - i + 1));
        div = i / (n - i + 1.0);
        printf("%.2lf\n", div);
        soma += div;
    }
    printf("%.2lf", soma);
}