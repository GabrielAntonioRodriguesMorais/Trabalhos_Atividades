#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool X1(char string[], int tam) {
    int contador = 0;

    for(int i = 0; i < tam - 1; i++) {
        if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u') {
            contador++;
        }
    }
    if (contador == tam - 1) {
        return true;
    } else {
        return false;
    }
}

bool X2(char string[], int tam) {
    int contador = 0;

    for(int i = 0; i < tam - 1; i++) {
        if (tolower(string[i]) != 'a' && tolower(string[i]) != 'e' && tolower(string[i]) != 'i' && tolower(string[i]) != 'o' && tolower(string[i]) != 'u') {
            contador++;
        }
    }
    if (contador == tam - 1) {
        return true;
    } else {
        return false;
    }
}


bool X3(char string[], int tam) {
    int i = 0, contador = 0;

    while (string[i] != '\0') {
        if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || 
            tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || 
            tolower(string[i]) == 'u') {
            contador++;
        }
        i++;
    }
    
    if (contador == tam) {
        return true;
    } else {
        return false;
    }
}

bool X4(char string[], int tam) {
    int i = 0, contador = 0;

    while (string[i] != '\0') {
        if (tolower(string[i]) != 'a' && tolower(string[i]) != 'e' && 
            tolower(string[i]) != 'i' && tolower(string[i]) != 'o' && 
            tolower(string[i]) != 'u') {
            contador++;
        }
        i++;
    }

    if (contador == tam) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    char string[100];
    int tam;
    

    while (fgets(string, sizeof(string), stdin) != NULL) // loop para receber entradas de um pub.in
    {
        tam = strlen(string);

        if (string[tam - 1] == '\n') // remove o '\n' do final da string e coloca um '\0'
        {
            string[tam - 1] = '\0';
        }

        if (strcmp(string, "FIM") != 0) 
        {
        if(X1(string, tam)){
            printf("SIM ");
        }else{
            printf("NAO ");
        }
        if(X2(string, tam)){
            printf("SIM ");
        }else{
            printf("NAO ");
        }if(X3(string, tam)){
            printf("SIM ");
        }else{
            printf("NAO ");
        }if(X4(string, tam)){
            printf("SIM ");
        }else{
            printf("NAO ");
        }
            printf("\n");
        }else{
            break;
        }
}
}