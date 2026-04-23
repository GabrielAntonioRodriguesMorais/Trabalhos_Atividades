import java.util.Scanner;

public class Ciframento {

    public static void ciframento(String string) {
        int tam = string.length();

        String resultado = "";

        for (int i = 0; i < tam; i++) {
            char c = string.charAt(i);
            resultado += (char) (c + 3);
        }

        // Exibe a string cifrada
        System.out.println(resultado);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String entrada = scanner.nextLine();
            ciframento(entrada);
        }

        scanner.close();
    }
}
