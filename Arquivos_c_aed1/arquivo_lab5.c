#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Alunos
{
    char nome[50];
    int nota;
} Alunos;

void mediaNotas(int n, Alunos aluno[])
{
    float media = 0.0;
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += aluno[i].nota;
    }
    media = soma / n;
    printf("Media das notas da turma: %.2f\n", media);
}

void maiorNota(int n, Alunos aluno[])
{
    char nomeM[50];
    int maiorN = 0;
    for (int i = 0; i < n; i++)
    {
        if (maiorN < aluno[i].nota)
        {
            maiorN = aluno[i].nota;
            strcpy(nomeM, aluno[i].nome);
        }
    }
    printf("%s tirou a maior nota (%d)\n", nomeM, maiorN);
}
void menorNota(int n, Alunos aluno[])
{
    char nomeM[50];
    int menorN = 100;
    for (int i = 0; i < n; i++)
    {
        if (menorN > aluno[i].nota)
        {
            menorN = aluno[i].nota;
            strcpy(nomeM, aluno[i].nome);
        }
    }
    printf("%s tirou a menor nota (%d)\n", nomeM, menorN);
}

int main()
{
    FILE *Provas;
    char linha[100], *token;
    int linhas = 0;

    Provas = fopen("Provas.txt", "r");

    if (Provas == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    while (fgets(linha, sizeof(linha), Provas) != NULL)
    {
        linhas++;
    }
    rewind(Provas);

    Alunos aluno[linhas];
    int i = 0;

    while (fgets(linha, sizeof(linha), Provas) != NULL)
    {
        linha[strcspn(linha, "\n")] = '\0';
        token = strtok(linha, ";");
        if (token != NULL)
        {
            strncpy(aluno[i].nome, token, 49);
            aluno[i].nome[49] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            aluno[i].nota = atoi(token);
        }
        i++;
    }

    mediaNotas(linhas, aluno);
    maiorNota(linhas, aluno);
    menorNota(linhas, aluno);

    fclose(Provas);

    return 0;
}
