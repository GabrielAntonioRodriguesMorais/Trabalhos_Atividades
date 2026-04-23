#include <stdio.h>
#include <string.h>

int main(){
    char texto[100];
    FILE *arquivo;

    fgets(texto, 100, stdin);
    texto[(strcspn(texto, "\n"))] = '\0';

    arquivo = fopen("exercicio2.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(arquivo, "%s\n", texto);

    fclose(arquivo);



return 0;
}
