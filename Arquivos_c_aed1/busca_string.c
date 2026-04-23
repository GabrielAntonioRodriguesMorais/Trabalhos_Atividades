#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contemPalavra(char *str, char *alvo)
{
    char tempStr[100];
    char tempAlvo[100];

    // Converte ambas as strings para minúsculas
    for (int i = 0; str[i]; i++)
    {
        tempStr[i] = tolower(str[i]);
    }
    tempStr[strlen(str)] = '\0';

    for (int i = 0; alvo[i]; i++)
    {
        tempAlvo[i] = tolower(alvo[i]);
    }
    tempAlvo[strlen(alvo)] = '\0';

    // Verifica se a palavra alvo é uma palavra inteira na string
    char *token = strtok(tempStr, " ,.-?!;:\n"); // Divide a string em palavras
    while (token != NULL)
    {
        if (strcmp(token, tempAlvo) == 0)
        {
            return 1; // A palavra-alvo foi encontrada
        }
        token = strtok(NULL, " ,.-?!;:\n"); // Continua com a próxima palavra
    }
    return 0; // Palavra não encontrada
}

int main()
{
    int N;
    char alvo[100];
    char str[100];
    int count = 0;

    scanf("%d", &N);
    getchar(); // Para consumir o caractere '\n' deixado pelo scanf

    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0'; // Remove o '\n' do final da palavra alvo

    for (int i = 0; i < N; i++)
    {
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; // Remove o '\n' do final da string

        // Verifica se a palavra-alvo é uma palavra inteira na string
        if (contemPalavra(str, alvo))
        {
            count++;
        }
    }

    // Imprime o número de ocorrências
    printf("%d\n", count);

    return 0;
}
