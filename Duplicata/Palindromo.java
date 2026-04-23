import java.util.Scanner;

public class Palindromo {

    public static boolean palindromo(String string) {
        int tam, iguais = 0;

        tam = string.length();

        // Remove o '\n' caso haja na entrada
        if (string.charAt(tam - 1) == '\n') {
            tam--; // Apenas ajusta o tamanho da string, sem precisar usar substring
        }

        // Cria uma nova string sem espaços
        String copiaSemEspacos = "";
        for (int i = 0; i < tam; i++) {
            if (string.charAt(i) != ' ') {
                copiaSemEspacos += string.charAt(i); // Concatena os caracteres
            }
        }

        int tam2 = copiaSemEspacos.length();
        String stringInvertida = "";

        // Cria a string invertida
        for (int i = tam2 - 1; i >= 0; i--) {
            stringInvertida += copiaSemEspacos.charAt(i);
        }

        // Compara as duas strings ignorando maiúsculas e minúsculas
        for (int i = 0; i < tam2; i++) {
            char c1 = copiaSemEspacos.charAt(i);
            char c2 = stringInvertida.charAt(i);

            // Compara de forma case-insensitive (transforma manualmente para maiúsculas)
            if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z')) {
                c1 -= 'a' - 'A'; // Converte c1 para maiúsculo
            } else if ((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'a' && c2 <= 'z')) {
                c2 -= 'a' - 'A'; // Converte c2 para maiúsculo
            }

            if (c1 == c2) {
                iguais++;
            }
        }

        return iguais == tam2; // Retorna true se todas as letras forem iguais
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String entrada;

        do {
            entrada = scanner.nextLine();

            // Remove o \n manualmente
            if (entrada.length() > 0 && entrada.charAt(entrada.length() - 1) == '\n') {
                entrada = entrada.substring(0, entrada.length() - 1); // Ajuste para manter a regra
            }

            if (palindromo(entrada)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

        } while (!entrada.equals("FIM")); // Verifica se a entrada é "FIM"

        scanner.close();
    }
}
