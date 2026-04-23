#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Show
{
    char show_id[5];
    char type[50];
    char title[50];
    char director[500];
    char cast[100];
    char country[100];
    char date_added[50];
    int release_year;
    char rating[50];
    char duration[8];
    char listed_in[100];
} Show;

char *LinhaID(char ID_entrada[])
{
    static char linha_encontrada[1000];
    char linha[1000];

    FILE *arquivo = fopen("disneyplus.csv", "r");
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char linha_copia[1000];
        strcpy(linha_copia, linha);

        char *token = strtok(linha_copia, ",");
        if (token != NULL && strcmp(token, ID_entrada) == 0)
        {
            linha[strcspn(linha, "\n")] = '\0';
            strcpy(linha_encontrada, linha);
            break;
        }
    }

    fclose(arquivo);

    if (strlen(linha_encontrada) > 0)
    {
        return linha_encontrada;
    }
    else
    {
        return NULL;
    }
}

Show LerShow(char linha[])
{
    Show s;

    // inicializa os atributos para casos de nao existencia no arquivo, quando nao houver release_year no arq por exemplo,...
    //...ja estara preenchido com o recomendado no enunciado
    strcpy(s.show_id, "NaN");
    strcpy(s.type, "NaN");
    strcpy(s.title, "NaN");
    strcpy(s.director, "NaN");
    strcpy(s.cast, "NaN");
    strcpy(s.country, "NaN");
    strcpy(s.date_added, "March 1, 1900");
    s.release_year = 0;
    strcpy(s.rating, "NaN");
    strcpy(s.duration, "NaN");
    strcpy(s.listed_in, "NaN");

    char *token;
    int campo = 0;
    char linha_copia[1000];
    strcpy(linha_copia, linha);

    token = strtok(linha_copia, ",");
    while (token != NULL)
    {
        if (strlen(token) == 0)
            token = "NaN";

        switch (campo) // utilizei switch pois fica o if ficaria enorme
        {
        case 0:
            strcpy(s.show_id, token);
            break;
        case 1:
            strcpy(s.type, token);
            break;
        case 2:
            strcpy(s.title, token);
            break;
        case 3:
            strcpy(s.director, token);
            break;
        case 4:
            strcpy(s.cast, token);
            break;
        case 5:
            strcpy(s.country, token);
            break;
        case 6:
            strcpy(s.date_added, strcmp(token, "NaN") == 0 ? "March 1, 1900" : token);
            break;
        case 7:
            s.release_year = atoi(token);
            break;
        case 8:
            strcpy(s.rating, token);
            break;
        case 9:
            strcpy(s.duration, token);
            break;
        case 10:
            strcpy(s.listed_in, token);
            break;
        }

        token = strtok(NULL, ",");
        campo++;
    }

    return s;
}

void ImprimirShow(Show s)
{
    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s]\n",
           s.show_id, s.type, s.title, s.director, s.cast, s.country, s.date_added, s.release_year, s.rating, s.duration, s.listed_in);
}

int main()
{
    char ID_entrada[10];

    while (fgets(ID_entrada, sizeof(ID_entrada), stdin) != NULL)
    {
        int tam = strlen(ID_entrada);
        if (ID_entrada[tam - 1] == '\n')
        {
            ID_entrada[tam - 1] = '\0';
        }

        if (strcmp(ID_entrada, "FIM") == 0)
        {
            break;
        }

        char *resultado = LinhaID(ID_entrada);
        if (resultado != NULL)
        {
            Show s = LerShow(resultado);
            ImprimirShow(s);
        }
    }

    return 0;
}