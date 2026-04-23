#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int contaVogais(char *string)
{
    int cont = 0, i = 0;
    while (string[i] != '\0')
    {
        if (toupper(string[i]) == toupper('a') || toupper(string[i]) == toupper('e') || toupper(string[i]) == toupper('i') || toupper(string[i]) == toupper('o') || toupper(string[i]) == toupper('u'))
        {
            cont++;
        }
        i++;
    }
    return cont;
}

int contaConsoantes(char *string)
{
    int contConsoantes = 0, i = 0, contV = 0;
    while (string[i] != '\0')
    {
        if (toupper(string[i]) == toupper('a') || toupper(string[i]) == toupper('e') || toupper(string[i]) == toupper('i') || toupper(string[i]) == toupper('o') || toupper(string[i]) == toupper('u'))
        {
            contV++;
        }
        else
        {
            contConsoantes++;
        }
        i++;
    }
    return contConsoantes;
}

int main()
{
    char string[50];
    int vogais, consoantes;

    fgets(string, sizeof(string), stdin);

    vogais = contaVogais(string);
    consoantes = contaConsoantes(string);
    printf("Possui %d Vogais e %d Consoantes", vogais, consoantes);
}