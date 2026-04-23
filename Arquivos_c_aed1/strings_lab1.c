#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int contaCaracteres(char *string, char letra)
{
    int cont = 0, i = 0;
    while (string[i] != '\0')
    {
        if (toupper(string[i]) == toupper(letra))
        {
            cont++;
        }
        i++;
    }
    return cont;
}

int contaCaracteresRecursiva(char *string, char letra)
{
    if (*string == '\0')
    {
        return 0;
    }
    int cont = (tolower(*string) == tolower(letra)) ? 1 : 0;

    return cont + contaCaracteresRecursiva(string + 1, letra);
}

int main()
{
    char string[50], letra;
    int saida;

    fgets(string, sizeof(string), stdin);

    scanf("%c", &letra);

    saida = contaCaracteres(string, letra);
    printf("Se repete %d\n", saida);
    saida = contaCaracteresRecursiva(string, letra);
    printf("Se repete %d\n", saida);
}