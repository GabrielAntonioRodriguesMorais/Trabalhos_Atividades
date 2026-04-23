#include <stdio.h>
#include <string.h>

int contaPalavras(char string[])
{
    int espacos = 0, i = 0;

    while(string[i] != '\0'){
        if(string[i] == ' '){
            espacos++;
        }
        i++;
    }
    return espacos + 1; 
}

int main()
{
    char string[100];
    int tam, qnt;

    while (fgets(string, sizeof(string), stdin) != NULL) // loop para receber entradas de um pub.in
    {
        tam = strlen(string);

        if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
        {
            string[tam - 1] = '\0';
        }

        if (strcmp(string, "FIM") != 0)
        {
            printf("%d\n", contaPalavras(string));
        }
        else
        {
            break;
        }
    }
}