#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool palindromo(char string[])
{
    int j = 0, tam, iguais = 0;

    tam = strlen(string);

    if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
    {
        string[tam - 1] = '\0';
    }

    char copia_sem_espacos[tam];

    for (int i = 0; i < (tam - 1); i++) // loop que faz a copia_sem_espacos da string de entrada para uma outra sem os espacos
    {
        if (string[i] != ' ')
        {
            copia_sem_espacos[j] = string[i];
            j++;
        }
    }
    copia_sem_espacos[j] = '\0'; // finaliza a string com um \0 ao final

    int tam2 = strlen(copia_sem_espacos);
    j = tam2 - 1;
    char string_invertida[tam2 + 1];

    for (int i = 0; i < tam2; i++) // loop para copiar a string sem os espacos par outra string de forma que inverta a posicao dos caracteres
    {
        string_invertida[i] = copia_sem_espacos[j];
        j--;
    }
    string_invertida[tam2] = '\0';

    for (int i = 0; i < tam2; i++) // loop para verificar se a string se mantem igual mesmo apos inverte-la
    {
        if (toupper(string_invertida[i]) == toupper(copia_sem_espacos[i])) // torna todos os caracteres da string maiusculos, assim nao havera diferenca no momento de verificacao
        {
            iguais++;
        }
    }

    if (iguais == tam2) // com uma variavel auxiliar que conta quantos caracteres sao iguais, verifiquei se as duas strings possuem a mesma quantia de caracteres
    {
        return true; // se sim e um palindromo e retorna true
    }
    else
    {
        return false; // se nao, nao e um palindromo, e retorna false
    }
}

int main()
{
    char string[100];

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