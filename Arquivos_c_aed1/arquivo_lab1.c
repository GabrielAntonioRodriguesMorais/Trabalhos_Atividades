#include <stdio.h>

int main(){
    FILE *arquivo;
    arquivo = fopen("numeros.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 1; i <= 10; i++){
        fprintf(arquivo, "%d\n", i);
    }

    fclose(arquivo);



return 0;
}
