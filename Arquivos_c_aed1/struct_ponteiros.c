#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pacientes
{
    int id;
    int doencas[100];
    int totalDoencas;
    char nome[30];
    char genero;
} Pacientes;

Pacientes *cadastroPaciente(int *i)
{
    Pacientes *p = (Pacientes *)malloc(sizeof(Pacientes));

    FILE *arquivo = fopen("Pacientes.txt", "a");

    printf("Id[%d]: \n", *(i + 1));
    scanf("%d", &p->id);
    getchar(); // Consumir o newline

    printf("Nome[%d]: \n", *(i + 1));
    fgets(p->nome, 30, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Genero[%d]: \n", *(i + 1));
    scanf("%c", &p->genero);
    getchar(); // Consumir o newline

    p->totalDoencas = 0;

    fprintf(arquivo, "%d:%s(%c)\n", p->id, p->nome, p->genero);
    fclose(arquivo);

    return p;
}

void registrarDoenca(Pacientes *p, int codDoenca)
{
    if (p->totalDoencas < 100)
    {
        p->doencas[p->totalDoencas] = codDoenca;
        p->totalDoencas++;
    }
    else
    {
        printf("Paciente atingiu o limite de doenças registradas.\n");
    }
}

void imprimirPessoa()
{
    FILE *arquivo = fopen("Pacientes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo 'Pacientes.txt'.\n");
        return;
    }

    int id;
    char nome[30], genero;

    while (fscanf(arquivo, "%d:%29[^:(](%c)\n", &id, nome, &genero) == 3)
    {
        printf("Pessoa[%d]: %s (%c)\n", id, nome, genero);
    }

    fclose(arquivo);
}

int frequenciaDoenca(Pacientes p[], int *n, int codDoenca)
{
    int totalDoenca = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p[i].totalDoencas; j++)
        {
            if (p[i].doencas[j] == codDoenca)
            {
                totalDoenca++;
            }
        }
    }
    return totalDoenca;
}

int carrega_quantidade_de_Pacientes()
{
    int contadorLinhas = 0;
    char linha[100];
    FILE *arquivo = fopen("Pacientes.txt", "r");

    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo Pacientes.txt.\n");
        return 0;
    }

    while (fgets(linha, 100, arquivo) != NULL)
    {
        contadorLinhas++;
    }

    fclose(arquivo);
    return contadorLinhas;
}

int main()
{
    int n;

    n = carrega_quantidade_de_Pacientes();

    Pacientes *paciente[n];
    for (int i = 0; i < n; i++)
    {
        paciente[i] = cadastroPaciente(&i);
    }

    imprimirPessoa();

    for (int i = 0; i < n; i++)
    {
        free(paciente[i]);
    }

    return 0;
}
