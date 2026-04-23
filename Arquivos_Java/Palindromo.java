package Arquivos_Java;

import java.util.Scanner;

public class Palindromo {

    public static boolean palindromo(String string) {
        int tam = string.length();

        char[] copiaSemEspacos = new char[tam];// string que recebera a prinipal sem os espacos
        int tamanhoReal = 0;

        for (int i = 0; i < tam; i++) {
            if (string.charAt(i) != ' ') {
                copiaSemEspacos[tamanhoReal] = string.charAt(i);// copia desconsiderando espacos
                tamanhoReal++;
            }
        }

        for (int i = 0; i < tamanhoReal / 2; i++) {// verifica se e palindromo carater por carater
            char c1 = copiaSemEspacos[i];
            char c2 = copiaSemEspacos[tamanhoReal - 1 - i];

            if (c1 != c2) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String entrada;
        do {
            entrada = scanner.nextLine();

            if (palindromo(entrada)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

        } while (!entrada.equals("FIM"));

        scanner.close();
    }
}
