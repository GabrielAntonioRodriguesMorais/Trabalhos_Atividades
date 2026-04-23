#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TAMANHO_PIZZA_PEQUENA 40.00
#define TAMANHO_PIZZA_MEDIA 50.00
#define TAMANHO_PIZZA_GRANDE 60.00

#define MAX_INGREDIENTE 12
#define MAX_LENGTH_NAME_PIZZA 20

typedef struct Ingredientes
{
    int id;
    char nome[30];
    float preco;
} Ingredientes;

typedef struct Pizza
{
    int Id;
    char Nome[30];
    char Tamanho; // P,M,G
    float Preco;
    Ingredientes Ingredientes[12]; // Array com os pizzas padrão da pizza
} Pizza;

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

void adicionar_pizza_CRUD(int *qnt_pizza)
{
    Pizza *pizza = (Pizza *)malloc(sizeof(Pizza));
    char continuar;

    do
    {
        printf("Digite o ID da Pizza: ");
        scanf("%d", &pizza->Id);
        getchar();

        printf("Digite o Nome da Pizza: ");
        fgets(pizza->Nome, 30, stdin);
        pizza->Nome[strcspn(pizza->Nome, "\n")] = '\0';

        printf("Digite o Tamanho da Pizza (P, M ou G): ");
        scanf(" %c", &pizza->Tamanho);
        pizza->Tamanho = toupper(pizza->Tamanho);
        getchar();

        if (pizza->Tamanho == 'P')
            pizza->Preco = TAMANHO_PIZZA_PEQUENA;
        if (pizza->Tamanho == 'M')
            pizza->Preco = TAMANHO_PIZZA_MEDIA;
        if (pizza->Tamanho == 'G')
            pizza->Preco = TAMANHO_PIZZA_GRANDE;

        // Abrir o arquivo de ingredientes
        FILE *arquivo_ingredientes = fopen("Ingredientes.txt", "r");

        if (arquivo_ingredientes == NULL)
        {
            printf("Erro ao abrir o arquivo de ingredientes. Certifique-se de que 'Ingredientes.txt' existe.\n");
            break;
        }

        printf("\nEscolha os ingredientes para a pizza:\n");

        // Mostrar ingredientes disponíveis
        char linha[100];
        int existe_ingrediente = 0;

        while (fgets(linha, sizeof(linha), arquivo_ingredientes))
        {
            int id = 0;
            char nome[30];
            float preco = 0.0;

            if (sscanf(linha, "%d;%29[^;];%f", &id, nome, &preco) == 3)
            {
                printf("%d - %s (R$ %.2f)\n", id, nome, preco);
                existe_ingrediente = 1;
            }
        }

        if (!existe_ingrediente)
        {
            printf("Nenhum ingrediente encontrado no arquivo!\n");
            fclose(arquivo_ingredientes);
            break;
        }
        fclose(arquivo_ingredientes);

        // Seleção de ingredientes
        int qnt_ingredientes = 0;
        while (qnt_ingredientes < 12)
        {
            int id_ingrediente;
            printf("Digite o ID do ingrediente (0 para finalizar): ");
            scanf("%d", &id_ingrediente);
            getchar();

            if (id_ingrediente == 0)
                break;

            // Reabrir o arquivo de ingredientes para buscar pelo ID
            arquivo_ingredientes = fopen("Ingredientes.txt", "r");
            if (arquivo_ingredientes == NULL)
            {
                printf("Erro ao abrir o arquivo de ingredientes.\n");
                break;
            }

            int encontrado = 0;
            while (fgets(linha, sizeof(linha), arquivo_ingredientes))
            {
                Ingredientes temp_ingrediente;
                if (sscanf(linha, "%d;%29[^;];%f", &temp_ingrediente.id, temp_ingrediente.nome, &temp_ingrediente.preco) == 3)
                {
                    if (temp_ingrediente.id == id_ingrediente)
                    {
                        pizza->Ingredientes[qnt_ingredientes] = temp_ingrediente;
                        qnt_ingredientes++;
                        encontrado = 1;
                        break;
                    }
                }
            }
            fclose(arquivo_ingredientes);

            if (!encontrado)
            {
                printf("Ingrediente com ID %d nao encontrado.\n", id_ingrediente);
            }
        }

        FILE *arquivo_pizzas = fopen("Pizzas.txt", "a");

        if (arquivo_pizzas == NULL)
        {
            printf("Erro ao abrir o arquivo de pizzas.\n");
            free(pizza);
            return;
        }
        // Salvar a pizza no arquivo de pizzas
        fprintf(arquivo_pizzas, "%d;%s;%c;%.2f;", pizza->Id, pizza->Nome, pizza->Tamanho, pizza->Preco);

        for (int i = 0; i < qnt_ingredientes; i++)
        {
            fprintf(arquivo_pizzas, "%d", pizza->Ingredientes[i].id);
            if (i < qnt_ingredientes - 1)
                fprintf(arquivo_pizzas, ",");
        }
        fprintf(arquivo_pizzas, ";\n");

        (*qnt_pizza)++;

        printf("Gostaria de adicionar mais uma Pizza? (S/N): ");
        scanf(" %c", &continuar);
        getchar();

        fclose(arquivo_pizzas);
    } while (continuar == 'S' || continuar == 's');

    free(pizza);
}

void visualizar_pizza_CRUD()
{
    FILE *arquivo = fopen("Pizzas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[200];
    printf("\nCardapio de Pizzas:\n");

    while (fgets(linha, sizeof(linha), arquivo))
    {
        int id;
        char nome[30], tamanho;
        float preco;
        char ingredientes_ids[100];

        // Lê os dados da pizza, incluindo os IDs dos ingredientes
        if (sscanf(linha, "%d;%29[^;];%c;%f;%99[^\n]", &id, nome, &tamanho, &preco, ingredientes_ids) == 5)
        {
            printf("%d - %s (%c) R$%.2f\n", id, nome, tamanho, preco);
            printf("  Ingredientes: ");

            // Exibe os ingredientes
            char *token = strtok(ingredientes_ids, ",");
            while (token)
            {
                int id_ingrediente = atoi(token);

                // Carrega o ingrediente do arquivo de ingredientes
                FILE *arquivo_ingredientes = fopen("Ingredientes.txt", "r");
                if (arquivo_ingredientes == NULL)
                {
                    printf("\nErro ao abrir o arquivo de ingredientes.\n");
                    break;
                }

                char linha_ingrediente[100];
                while (fgets(linha_ingrediente, sizeof(linha_ingrediente), arquivo_ingredientes))
                {
                    Ingredientes temp_ingrediente;
                    if (sscanf(linha_ingrediente, "%d;%29[^;];%f", &temp_ingrediente.id, temp_ingrediente.nome, &temp_ingrediente.preco) == 3)
                    {
                        if (temp_ingrediente.id == id_ingrediente)
                        {
                            printf("%s (R$%.2f), ", temp_ingrediente.nome, temp_ingrediente.preco);
                            break;
                        }
                    }
                }
                fclose(arquivo_ingredientes);

                token = strtok(NULL, ",");
            }
            printf("\n");
        }
    }

    fclose(arquivo);
}

void atualizar_pizza_CRUD(Pizza *pizzas, int qnt)
{
    // Abre o arquivo em modo de escrita para sobrescrever o conteúdo
    FILE *arquivo = fopen("Pizzas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para atualizar as pizzas.\n");
        return;
    }

    // Percorre todas as pizzas para escrever no arquivo
    for (int i = 0; i < qnt; i++)
    {
        // Escreve os dados principais da pizza no arquivo
        fprintf(arquivo, "%d;%s;%c;%.2f;",
                pizzas[i].Id,
                pizzas[i].Nome,
                pizzas[i].Tamanho,
                pizzas[i].Preco);

        // Escreve os IDs dos ingredientes associados à pizza
        int primeiro = 1;
        for (int j = 0; j < 12; j++) // 12 é o número máximo de ingredientes
        {
            if (pizzas[i].Ingredientes[j].id != 0) // Apenas IDs válidos
            {
                if (!primeiro)
                    fprintf(arquivo, ","); // Adiciona vírgula entre IDs
                fprintf(arquivo, "%d", pizzas[i].Ingredientes[j].id);
                primeiro = 0;
            }
        }

        // Finaliza a linha da pizza
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Pizzas atualizadas no arquivo com sucesso!\n");
}

void editar_pizza_CRUD(int *qnt)
{
    char novo_nome[30], novo_tamanho;
    int id_alteracao_pizza, posicao_alteracao_pizza = -1, opcao, id_novo_ing;
    char linha[200];

    FILE *arquivo = fopen("Pizzas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Pizza *pizza_aux = (Pizza *)malloc((*qnt) * sizeof(Pizza));
    if (pizza_aux == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return;
    }

    // Carregar as pizzas do arquivo
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d;%29[^;];%c;%f", &pizza_aux[i].Id, pizza_aux[i].Nome, &pizza_aux[i].Tamanho, &pizza_aux[i].Preco) == 4)
        {
            // Extrair os ingredientes
            char *ingredientes_part = strchr(linha, ';') + 1;
            ingredientes_part = strchr(ingredientes_part, ';') + 1;
            ingredientes_part = strchr(ingredientes_part, ';') + 1;

            int t = 0;
            char *token = strtok(ingredientes_part, ",");
            while (token != NULL && t < 12)
            { // Limitar a 12 ingredientes
                pizza_aux[i].Ingredientes[t].id = atoi(token);
                // Aqui seria necessário buscar o nome e preço do ingrediente usando o ID em um arquivo ou lista de ingredientes
                sprintf(pizza_aux[i].Ingredientes[t].nome, "Ingrediente %d", pizza_aux[i].Ingredientes[t].id); // Mock
                pizza_aux[i].Ingredientes[t].preco = 0.5;                                                      // Mock
                token = strtok(NULL, ",");
                t++;
            }
        }
        i++;
    }
    fclose(arquivo);

    // Exibir pizzas para o usuário escolher qual editar
    visualizar_pizza_CRUD();

    printf("Digite o ID da Pizza a ser alterada: ");
    scanf("%d", &id_alteracao_pizza);
    getchar();

    // Procurar a pizza a ser alterada
    for (i = 0; i < *qnt; i++)
    {
        if (pizza_aux[i].Id == id_alteracao_pizza)
        {
            posicao_alteracao_pizza = i;
            break;
        }
    }

    if (posicao_alteracao_pizza == -1)
    {
        printf("Pizza com ID %d não encontrada.\n", id_alteracao_pizza);
        free(pizza_aux);
        return;
    }

    do
    {
        printf("*******************************|\n");
        printf("O que gostaria de alterar ?    |\n");
        printf("*******************************|\n");
        printf(" 1 - Nome da Pizza             |\n");
        printf(" 2 - Tamanho da Pizza          |\n");
        printf(" 3 - Ingredientes da Pizza     |\n");
        printf(" 0 - Sair                      |\n");
        printf("*******************************|\n");

        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Qual o novo nome? ");
            fgets(novo_nome, sizeof(novo_nome), stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0'; // Remover o '\n'
            strcpy(pizza_aux[posicao_alteracao_pizza].Nome, novo_nome);
            printf("Nome alterado com sucesso!\n");
            break;

        case 2:
            printf("Qual o novo Tamanho (P, M ou G)? ");
            scanf(" %c", &novo_tamanho);
            pizza_aux[posicao_alteracao_pizza].Tamanho = toupper(novo_tamanho);

            if (pizza_aux[posicao_alteracao_pizza].Tamanho == 'P')
                pizza_aux[posicao_alteracao_pizza].Preco = TAMANHO_PIZZA_PEQUENA;
            else if (pizza_aux[posicao_alteracao_pizza].Tamanho == 'M')
                pizza_aux[posicao_alteracao_pizza].Preco = TAMANHO_PIZZA_MEDIA;
            else if (pizza_aux[posicao_alteracao_pizza].Tamanho == 'G')
                pizza_aux[posicao_alteracao_pizza].Preco = TAMANHO_PIZZA_GRANDE;
            else
                printf("Tamanho invalido!\n");
            printf("Tamanho alterado com sucesso!\n");
            break;

        case 3:
            printf("Ingredientes atuais:\n");
            for (int j = 0; j < 12 && pizzas[posicao_pizza].ingrediente[j].id != 0; j++) {
                printf("%d - %s (R$ %.2f)\n", pizzas[posicao_pizza].ingredientes[j].id,
                       pizzas[posicao_pizza].ingredientes[j].nome,
                       pizzas[posicao_pizza].ingredientes[j].preco);
            }

            int id_novo_ingrediente;
            printf("Digite o ID do novo ingrediente: ");
            scanf("%d", &id_novo_ingrediente);

            Ingredientes novo_ingrediente;
            if (buscar_ingrediente_por_id(id_novo_ingrediente, &novo_ingrediente)) {
                pizza[posicao_pizza].ingredientes[0] = novo_ingrediente; // Atualiza o primeiro ingrediente
                printf("Ingrediente atualizado com sucesso!\n");
            } else {
                printf("Ingrediente com ID %d não encontrado!\n", id_novo_ingrediente);
            }
            break;

        case 0:
            printf("Saindo da edição...\n");
            break;

        default:
            printf("OPÇÃO INVALIDA! DIGITE OUTRA.\n");
            break;
        }
    } while (opcao != 0);

    // Reescrever as pizzas no arquivo
    arquivo = fopen("Pizzas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar as alterações.\n");
        free(pizza_aux);
        return;
    }

    // Gravar todas as pizzas no arquivo, incluindo as alterações
    for (i = 0; i < *qnt; i++)
    {
        fprintf(arquivo, "%d;%s;%c;%.2f;", pizza_aux[i].Id, pizza_aux[i].Nome, pizza_aux[i].Tamanho, pizza_aux[i].Preco);
        for (int j = 0; j < 12 && pizza_aux[i].Ingredientes[j].id != 0; j++)
        {
            fprintf(arquivo, "%d", pizza_aux[i].Ingredientes[j].id);
            if (j < 11 && pizza_aux[i].Ingredientes[j + 1].id != 0)
            {
                fprintf(arquivo, ",");
            }
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    free(pizza_aux);

    printf("Alterações salvas com sucesso!\n");
}

void remover_pizza_CRUD()
{
    FILE *arquivo = fopen("Pizzas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de pizzas.\n");
        return;
    }

    char linha[200];
    int id_remover, id_pizza;
    char nome[30], tamanho;
    float preco;
    Pizza *pizzas = (Pizza *)malloc(sizeof(Pizza) * 100); // Armazenar até 100 pizzas
    int qnt_pizzas = 0;

    printf("Digite o ID da pizza que deseja remover: ");
    scanf("%d", &id_remover);

    // Carregar as pizzas existentes no arquivo
    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (sscanf(linha, "%d;%29[^;];%c;%f", &id_pizza, nome, &tamanho, &preco) == 4)
        {
            pizzas[qnt_pizzas].Id = id_pizza;
            strcpy(pizzas[qnt_pizzas].Nome, nome);
            pizzas[qnt_pizzas].Tamanho = tamanho;
            pizzas[qnt_pizzas].Preco = preco;
            qnt_pizzas++;
        }
    }

    fclose(arquivo);

    // Verificar se a pizza existe
    int encontrado = 0;
    int i;
    for (i = 0; i < qnt_pizzas; i++)
    {
        if (pizzas[i].Id == id_remover)
        {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
    {
        // Reabrir o arquivo para sobrescrever
        arquivo = fopen("Pizzas.txt", "w");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo para remoção.\n");
            free(pizzas);
            return;
        }

        // Escrever todas as pizzas, exceto a removida
        for (int j = 0; j < qnt_pizzas; j++)
        {
            if (pizzas[j].Id != id_remover)
            {
                fprintf(arquivo, "%d;%s;%c;%.2f\n", pizzas[j].Id, pizzas[j].Nome, pizzas[j].Tamanho, pizzas[j].Preco);
            }
        }

        printf("Pizza com ID %d removida com sucesso!\n", id_remover);
        fclose(arquivo);
    }
    else
    {
        printf("Pizza com ID %d não encontrada.\n", id_remover);
    }

    free(pizzas);
}

int carrega_quantidade_de_pizzas()
{
    int contadorLinhas = 0;
    char linha[100];
    FILE *arquivo;

    arquivo = fopen("Pizzas.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de carrega_quantidade_de_pizzas");
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
    int quantidade = carrega_quantidade_de_pizzas();
    int opcao;

    do
    {
        // Exibe o menu
        printf("*******************************|\n");
        printf("PIZZA(s):                |\n");
        printf("*******************************|\n");
        printf(" 1 - Adicionar Pizza(s)  |\n");
        printf(" 2 - Visualizar Pizza(s) |\n");
        printf(" 3 - Editar Pizza(s)     |\n");
        printf(" 4 - Remover Pizza(s)    |\n");
        printf(" 0 - Sair                      |\n");
        printf("*******************************|\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionar_pizza_CRUD(&quantidade); // Adicionar pizza
            break;

        case 2:
            visualizar_pizza_CRUD(); // Exibir pizza
            break;

        case 3:
            editar_pizza_CRUD(&quantidade);
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