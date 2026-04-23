#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Produto
{
    int ID;
    char nome[100];
    float preco;
    int qnt;
} Produto;

Produto cadastrarProduto()
{
    Produto prod;
    scanf("%d", &prod.ID);
    fgets(prod.nome, sizeof(prod.nome), stdin);
    prod.nome[strcspn(prod.nome, "\n")] = '\0';
    scanf("%f", &prod.preco);
    scanf("%d", &prod.qnt);
    return prod;
}

void precoMedio(Produto p[], int n)
{
    float soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += p[i].preco;
    }
    printf("%.2f\n", soma / n);
}

void registrarVenda(char *pVenda, Produto *produtos, int n, int qntV)
{
    int encontrado = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(produtos[i].nome, pVenda) == 0)
        {
            encontrado = 1;
            if (produtos[i].qnt >= qntV)
            {
                produtos[i].qnt -= qntV;
                printf("Venda registrada com sucesso!\n");
            }
            else
            {
                printf("Produto fora de estoque!\n");
            }
            return;
        }
    }
    if (!encontrado)
    {
        printf("Produto inexistente!\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);
    getchar();

    Produto produtos[n];
    for (int i = 0; i < n; i++)
    {
        produtos[i] = cadastrarProduto();
    }

    precoMedio(produtos, n);

    char prodVendas[100];
    int qntV;
    getchar();
    fgets(prodVendas, 100, stdin);
    prodVendas[strcspn(prodVendas, "\n")] = '\0';
    scanf("%d", &qntV);
    registrarVenda(prodVendas, produtos, n, qntV);
}
