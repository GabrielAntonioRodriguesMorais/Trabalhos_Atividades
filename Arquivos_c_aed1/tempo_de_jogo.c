#include <stdio.h>

int main(void)
{
    int inicio, fim, duracao;

    scanf("%d %d", &inicio, &fim);

    if (inicio < fim)
    {
        duracao = fim - inicio;
    }
    else if (inicio > fim)
    {
        duracao = (24 - inicio) + fim;
    }
    else if (inicio == fim)
    {
        duracao = 24;
    }

    printf("O JOGO DUROU %d HORA(S)", duracao);

    return 0;
}