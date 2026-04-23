#include <stdio.h>
#include <string.h>
#include <ctype.h>

void palindroma(char string[])
{
    char copia[100] = "";
    int i, tam, iguais = 0, j = 0, diferentes = 0;

    tam = strlen(string);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            for (i = 0; i < strlen(string); i++)
            {
                if (string[i] != '!' && string[i] != '?' && string[i] != ' ' && string[i] != '.')
                {
                    copia[j++] = string[i];
                }
                copia[j] = '\0';
                tam = strlen(copia);
                tam--;
                for (i = 0; i < strlen(copia); i++)
                {
                    if (copia[i] != copia[tam])
                    {
                        diferentes++;
                        tam--;
                    }
                    if (diferentes = 0)
                    {
                        printf("SIM\n");
                    }
                    else
                    {
                        printf("NAO\n");
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < strlen(string); i++)
            {
                copia[i] = string[tam - 1];
                tam--;
            }
            copia[i] = '\0';
            tam = strlen(string);

            for (i = 0; i < tam; i++)
            {
                if (copia[i] == string[i])
                {
                    iguais++;
                }
            }

            if (tam == iguais)
            {
                printf("SIM\n");
            }
            else
                printf("NAO");
        }
    }
    int main()
    {
        char string[100] = "";
        while (1)
        {
            fgets(string, sizeof(string), stdin);
            string[strcspn(string, "\n")] = '\0';

            if (strcmp(string, "FIM") == 0)
            {
                break;
            }

            palindroma(string);
        }
    }
