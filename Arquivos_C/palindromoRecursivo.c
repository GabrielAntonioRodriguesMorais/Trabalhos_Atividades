#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindromo(char string[], int esq, int dir)
{
    if (esq >= dir)
    {
        return true;
    }
    else if (string[esq] != string[dir])
    {
        return false;
    }
    else
    {
        return (string, esq + 1, dir - 1);
    }
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
            tam--;
        }

        if (strcmp(string, "FIM") != 0)
        {
            char copia_sem_espacos[100]; // string que vai ser preenchida sem os espacos
            int j = 0;

            for (int x = 0; x < tam; x++) // loop para remover os espaços e copiar os caracteres
            {
                if (string[x] != ' ')
                {
                    copia_sem_espacos[j] = string[x];
                    j++;
                }
            }
            copia_sem_espacos[j] = '\0'; // adiciona fim de string

            if (palindromo(copia_sem_espacos, 0, j - 1))
            {
                printf("SIM\n");
            }
            else
            {
                printf("NAO\n");
            }
        }
        else
        {
            break;
        }
    }
}