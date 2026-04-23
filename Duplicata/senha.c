#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool ValidarSenha(char string[]){

}

int main()
{
    char string[1000];

    do
    {
        fgets(string, sizeof(string), stdin);

        if (strcmp(string, "FIM") != 0) // Verifica a condição de parada
        {
            if (palindromo(string))
            {
                printf("SIM\n");
            }
            else
            {
                printf("NAO\n");
            }
        }
    } while (strcmp(string, "FIM") != 0);
}