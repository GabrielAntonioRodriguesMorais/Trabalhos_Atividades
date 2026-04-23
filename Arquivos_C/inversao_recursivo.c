#include <stdio.h>
#include <string.h>

void inversao(char *string)
{
    if (*string == '\0')
    {
        return;
    }
    inversao(string + 1);
    printf("%c", *string);
}

int main()
{
    char string[100];
    int tam;

    while (fgets(string, sizeof(string), stdin) != NULL) // loop para receber entradas de um pub.in
    {
        tam = strlen(string);

        if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
        {
            string[tam - 1] = '\0';
        }

        if (strcmp(string, "FIM") != 0)
        {
            inversao(string);
            printf("\n");
        }
        else
        {
            break;
        }
    }
}