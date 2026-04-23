#include <stdio.h>
#include <string.h>

void inversao(char string[])
{
    int i = 0, j = 0, tam;

    tam = strlen(string);

    if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
    {
        string[tam - 1] = '\0';
    }

    tam = strlen(string);

    j = tam - 1;

    char inversa[tam + 1];

    while (string[i] != '\0')
    {
        inversa[i] = string[j];
        j--;
        i++;
    }
    inversa[tam] = '\0';

    printf("%s\n", inversa);
}

int main()
{
    char string[100];

    while (fgets(string, sizeof(string), stdin) != NULL) // loop para receber entradas de um pub.in
    {
        inversao(string);
    }
}