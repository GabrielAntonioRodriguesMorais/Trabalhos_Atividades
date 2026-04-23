#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int soma(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
        return (n % 10) + soma(n / 10);
}

int main()
{
    char string[100];
    int tam;
    int n;
    

    while (fgets(string, sizeof(string), stdin) != NULL) // loop para receber entradas de um pub.in
    {
        tam = strlen(string);

        if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
        {
            string[tam - 1] = '\0';
        }

        if (strcmp(string, "FIM") != 0) 
        {
        n = atoi(string);// converte a string de caracteres numerios para uma variavel int
        printf("%d", soma(n)); 
        printf("\n");
        }else{
            break;
        }
}
}