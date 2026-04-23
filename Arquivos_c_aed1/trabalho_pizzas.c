#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Ingredientes
{
    int id;
    char nome[30];
    float preco;
} Ingredientes;

void adicionar_ingrediente_CRUD(int *qnt)
{
    Ingredientes *ingrediente = (Ingredientes *)malloc(sizeof(Ingredientes));
    char continuar;
    FILE *arquivo = fopen("Ingredientes.txt", "a");

    do
    {

        printf("Digite o ID do Ingrediente: ");
        scanf("%d", &ingrediente[*qnt].id);
        getchar();

        printf("Digite o nome do Ingrediente: ");
        fgets(ingrediente[*qnt].nome, 30, stdin);
        ingrediente[*qnt].nome[strcspn(ingrediente[*qnt].nome, "\n")] = '\0';

        printf("Digite o preço do Ingrediente: ");
        scanf("%f", &ingrediente[*qnt].preco);
        getchar();

        fprintf(arquivo, "%d;%s;%.2f\n", ingrediente[*qnt].id, ingrediente[*qnt].nome, ingrediente[*qnt].preco);

        (*qnt)++;

        printf("Gostaria de adicionar mais um Ingrediente? ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
    free(ingrediente);
    fclose(arquivo);
}
void visualizar_ingrediente_CRUD()
{
    FILE *arquivo = fopen("Ingredientes.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
    }

    char linha[100];
    printf("\nIngredientes cadastrados no arquivo:\n");

    int existe_ingrediente = 0; // Flag para verificar se há ingredientes no arquivo
    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id = 0;
        char nome[30];
        float preco = 0.0;

        // Lê os dados da linha no formato esperado
        // printf("%s\n", linha);
        if (sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3)
        {
            printf("%d - %s R$%.2f\n", id, nome, preco);
            existe_ingrediente = 1; // Marca que encontrou pelo menos um ingrediente
        }
    }

    if (!existe_ingrediente)
    {
        printf("Nenhum ingrediente encontrado no arquivo!\n");
    }
    fclose(arquivo);
}

void atualizar_ingredientes(Ingredientes *ingrediente, int qnt)
{
    FILE *arquivo = fopen("Ingredientes.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar os ingredientes.\n");
        return;
    }

    for (int i = 0; i < qnt; i++)
    {
        fprintf(arquivo, "%d;%s;%.2f\n", ingrediente[i].id, ingrediente[i].nome, ingrediente[i].preco);
    }

    fclose(arquivo);
}

void editar_ingrediente_CRUD(int *qnt)
{
    char alteracao[10], novo_nome[30], nome[30], linha[100];
    int id_alteracao, posicao_alteracao = -1, id = 0;
    float novo_preco = 0.0, preco = 0.0;

    // Abre o arquivo apenas para leitura
    FILE *arquivo = fopen("Ingredientes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    // Aloca memória para os ingredientes
    Ingredientes *ingrediente = (Ingredientes *)malloc((*qnt) * sizeof(Ingredientes));
    if (ingrediente == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return;
    }

    visualizar_ingrediente_CRUD();

    printf("Digite o ID do ingrediente a ser alterado: ");
    scanf("%d", &id_alteracao);
    getchar();

    // Carrega os ingredientes do arquivo para a memória
    for (int i = 0; i < *qnt; i++)
    {
        if (fgets(linha, sizeof(linha), arquivo) != NULL &&
            sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3)
        {
            ingrediente[i].id = id;
            ingrediente[i].preco = preco;
            strcpy(ingrediente[i].nome, nome);
            if (ingrediente[i].id == id_alteracao)
            {
                posicao_alteracao = i;
            }
        }
    }
    fclose(arquivo);

    // Verifica se o ID foi encontrado
    if (posicao_alteracao < 0)
    {
        printf("Ingrediente com ID %d não encontrado.\n", id_alteracao);
        free(ingrediente);
        return;
    }

    // Realiza a alteração
    printf("O que gostaria de alterar (nome ou preco)? ");
    fgets(alteracao, sizeof(alteracao), stdin);
    alteracao[strcspn(alteracao, "\n")] = '\0';

    if (strcmp(alteracao, "nome") == 0)
    {
        printf("Qual o novo nome? ");
        fgets(novo_nome, sizeof(novo_nome), stdin);
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(ingrediente[posicao_alteracao].nome, novo_nome);
    }
    else if (strcmp(alteracao, "preco") == 0)
    {
        printf("Qual o novo preco? ");
        scanf("%f", &novo_preco);
        getchar();
        ingrediente[posicao_alteracao].preco = novo_preco;
    }

    // Atualiza o arquivo
    atualizar_ingredientes(ingrediente, *qnt);

    free(ingrediente);
    printf("Ingrediente atualizado com sucesso!\n");
}

void remover_ingrediente_CRUD(int *qnt)
{
    if (*qnt == 0)
    {
        printf("Nenhum ingrediente para remover.\n");
        return;
    }

    visualizar_ingrediente_CRUD();

    int id_para_remover, encontrado = 0;
    printf("Digite o ID do ingrediente que deseja remover: ");
    scanf("%d", &id_para_remover);
    getchar();

    // Aloca memória para carregar os ingredientes
    Ingredientes *ingrediente = (Ingredientes *)malloc((*qnt) * sizeof(Ingredientes));
    if (ingrediente == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    FILE *arquivo = fopen("Ingredientes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(ingrediente);
        return;
    }

    // Carrega os ingredientes do arquivo para a memória
    int i = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        sscanf(linha, "%d;%29[^;];%f", &ingrediente[i].id, ingrediente[i].nome, &ingrediente[i].preco);
        i++;
    }
    fclose(arquivo);

    // Abre o arquivo para reescrever apenas os ingredientes que não foram removidos
    arquivo = fopen("Ingredientes.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        free(ingrediente);
        return;
    }

    for (i = 0; i < *qnt; i++)
    {
        if (ingrediente[i].id == id_para_remover)
        {
            encontrado = 1; // Marca que encontrou o ingrediente para remover
        }
        else
        {
            fprintf(arquivo, "%d;%s;%.2f\n", ingrediente[i].id, ingrediente[i].nome, ingrediente[i].preco);
        }
    }

    fclose(arquivo);
    free(ingrediente);

    if (encontrado)
    {
        (*qnt)--; // Decrementa a quantidade de ingredientes
        printf("Ingrediente removido com sucesso!\n");
    }
    else
    {
        printf("Ingrediente com ID %d não encontrado.\n", id_para_remover);
    }
}

int carrega_quantidade_de_ingredientes()
{
    int contadorLinhas = 0;
    char linha[100];
    FILE *arquivo;

    arquivo = fopen("Ingredientes.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de carrega_quantidade_de_ingredientes");
        return 1;
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
    int quantidade = carrega_quantidade_de_ingredientes();
    int opcao;

    do
    {
        // Exibe o menu
        printf("*******************************|\n");
        printf("INGREDIENTE(s):                |\n");
        printf("*******************************|\n");
        printf(" 1 - Adicionar Ingrediente(s)  |\n");
        printf(" 2 - Visualizar Ingrediente(s) |\n");
        printf(" 3 - Editar Ingrediente(s)     |\n");
        printf(" 4 - Remover Ingrediente(s)    |\n");
        printf(" 0 - Sair                      |\n");
        printf("*******************************|\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            adicionar_ingrediente_CRUD(&quantidade); // Adicionar ingredientes
            break;

        case 2:
            visualizar_ingrediente_CRUD(); // Exibir ingredientes
            break;

        case 3:
            editar_ingrediente_CRUD(&quantidade);
            break;

        case 4:
            remover_ingrediente_CRUD(&quantidade);
            break;

        case 0:
            printf("Saindo do CRUD\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 0);
}