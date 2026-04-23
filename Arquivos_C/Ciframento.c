#include <stdio.h>
#include <string.h>

void ciframento(char string[])
{
    int tam, i = 0;

    tam = strlen(string);

    char string2[tam];

    if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
    {
        string[tam - 1] = '\0';
    }

    while (i < tam)
    {
        string2[i] = string[i] + 3;
        i++;
    }

    string2[i] = '\0';

    printf("%s\n", string2);
}

int main()
{
    char string[100];

    while (fgets(string, sizeof(string), stdin) != NULL) // loop para receber entradas de um pub.in
    {
        ciframento(string);
    }
}