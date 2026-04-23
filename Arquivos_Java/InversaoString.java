import java.util.Scanner;

public class InversaoString {

    public static void inversao(String string) {
        int tam = string.length();
        char[] inversa = new char[tam];

        for (int i = 0; i < tam; i++) {
            inversa[i] = string.charAt(tam - 1 - i);
        }

        System.out.println(new String(inversa)); // Converte o array de caracteres para string e imprime
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            String string = scanner.nextLine();

            if (string.equals("FIM")) {
                break;
            }

            inversao(string);
        }

        scanner.close();
    }
}
