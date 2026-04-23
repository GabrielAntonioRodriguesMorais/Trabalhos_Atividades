package Arquivos_Java;

import java.util.Scanner;

public class Anagrama {

    public static boolean verificaFim(String string) {
        char[] stringFIM = { 'F', 'I', 'M' };

        if (string.length() != 3) {
            return false;
        }

        for (int i = 0; i < 3; i++) {
            if (string.charAt(i) != stringFIM[i]) {
                return false;
            }
        }

        return true;
    }

    public static Boolean VerificaAnagrama(String string) {
        char[] string1 = new char[20];
        char[] string2 = new char[20];
        int tam1 = 0;
        int tam2 = 0;

        int tam = 0;
        char c = string.charAt(tam);
        while (c != ' ' && tam != string.length()) {
            c = string.charAt(tam);
            if (c == ' ') {
                tam += 2;
            }
            string1[tam] = c;// esta recebendo o primeiro espaco, fazer tam1 - 1 no loop
            tam++;
            tam1++;
        }

        tam1 = tam1 - 1;

        c = string.charAt(tam);
        while (c != ' ' && tam != string.length()) {
            c = string.charAt(tam);
            if (c == ' ') {
                tam += 2;
            }
            string2[tam] = c;
            tam++;
            tam2++;
        }
        System.out.print("string1: ");
        for (int i = 0; i < tam1; i++) {
            System.out.print(string1[i]);
        }
        System.out.println();

        System.out.print("string2: ");
        for (int i = 0; i < tam2; i++) {
            System.out.print(string2[i]);
        }
        System.out.println();

        System.out.println(tam1);
        System.out.println(tam2);

        if (tam1 != tam2) {
            return false;
        }

        int igualdades = 0;

        for (int i = 0; i < tam1; i++) {
            for (int j = 0; j < tam2; j++) {
                System.out.println("Comparando: " + string1[i] + " e " + string2[j]);
                System.out.println(string2);
                if (string1[i] == string2[j]) {
                    igualdades++;
                }
            }
        }

        if (igualdades == tam1) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String string, minusculo;
        do {
            string = scanner.nextLine();
            minusculo = string.toLowerCase();

            if (VerificaAnagrama(minusculo)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

        } while (!verificaFim(string));

        scanner.close();
    }

}
