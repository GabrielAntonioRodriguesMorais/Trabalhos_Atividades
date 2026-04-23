#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void contaEspacos(char *string)
{
    int cont = 0, i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == ' ')
        {
            cont++;
        }
    }
    printf("%d espacos na frase", cont);
}

int main()
{
    char string[50];

    fgets(string, sizeof(string), stdin);

    contaEspacos(string);
}