import java.util.Scanner;

public class SomaRecursiva {

    // Método recursivo para calcular a soma dos dígitos de um número
    public static int soma(int n) {
        if (n == 0) {
            return 0;
        } else {
            return (n % 10) + soma(n / 10);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) { // Lê apenas números inteiros
            int n = scanner.nextInt();

            System.out.println(soma(n));
        }

        scanner.close();
    }
}
