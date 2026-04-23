#include <stdio.h>

double calcularFatorial(int n)
{
    double fatorial = 1;
    for (int i = 1; i <= n; i++)
    {
        fatorial *= i;
    }
    return fatorial;
}

double calcularSoma(int N)
{
    double soma = 1.0;
    for (int i = 1; i <= N; i++)
    {
        soma += 1.0 / calcularFatorial(i);
    }
    return soma;
}

int main()
{
    int N;
    scanf("%d", &N);

    double resultado = calcularSoma(N);
    printf("%.2f\n", resultado);

    return 0;
}
