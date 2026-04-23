#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("Ingredientes.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir Ingredientes.txt");
        return 1;
    }
    printf("Arquivo aberto com sucesso!\n");
    fclose(arquivo);
    return 0;
}