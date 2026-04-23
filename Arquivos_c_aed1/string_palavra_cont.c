#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maiusculo(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int main()
{
    char frase[100], palavra[50];
    int n, cont = 0;

    scanf("%d", &n);
    getchar();

    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';
    maiusculo(palavra);

    for (int i = 0; i < n; i++)
    {
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0';
        maiusculo(frase);
        char *ptr = strtok(frase, " ,.-?!;:\n");
        while (ptr != NULL)
        {
            if (strcmp(palavra, ptr) == 0)
            {
                cont++;
                break;
            }
            ptr = strtok(NULL, " ,.-?!;:\n");
        }
    }

    printf("%d", cont);
}