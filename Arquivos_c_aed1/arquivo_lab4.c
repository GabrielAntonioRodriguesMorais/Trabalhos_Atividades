#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int contadorLinhas = 0;
    char linha[100];
    FILE *arquivo;

    arquivo = fopen("exercicio2.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    while(fgets(linha, 100, arquivo) != NULL){
        contadorLinhas++;
        printf("%s\n", linha);
    }

    fclose(arquivo);

    printf("Existem %d linhas no seu arquivo!", contadorLinhas);
}
