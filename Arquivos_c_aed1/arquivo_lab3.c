#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int contador1 = 0, contadorLetra = 0;
    char letra, caractere;
    FILE *arquivo;

    scanf("%c", &letra);

    arquivo = fopen("exercicio2.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    while((caractere = fgetc(arquivo)) != EOF){
        contador1++;
        if(toupper(caractere) == toupper(letra)){
            contadorLetra++;
        }
    }

    fclose(arquivo);

    printf("Existem %d caracteres e o caracter %c aparece %d vezes", contador1, letra, contadorLetra);
}
