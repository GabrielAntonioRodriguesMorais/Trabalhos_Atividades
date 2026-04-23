#include <stdio.h>
#include <string.h>

void ciframento(char *string)
{
    if (*string == '\0')
    {
        return;
    }
    printf("%c", *string + 3);
    ciframento(string + 1);
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
        ciframento(string);
        printf("\n");
    }
}