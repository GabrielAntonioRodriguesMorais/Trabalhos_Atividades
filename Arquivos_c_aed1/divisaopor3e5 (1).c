#include <stdio.h>

int main() {
  int n1, n2, n3;

  scanf("%d %d %d", &n1, &n2, &n3);

  if (n1 % 3 == 0 && n1 % 5 == 0) {
    printf("Divisível por ambos\n");
  } else if (n1 % 3 == 0) {
    printf("Divisível por 3\n");
  } else if (n1 % 5 == 0) {
    printf("Divisível por 5\n");
  } else {
    printf("Não é divisível por 3 nem por 5\n");
  }

  if (n2 % 3 == 0 && n2 % 5 == 0) {
    printf("Divisível por ambos\n");
  } else if (n2 % 3 == 0) {
    printf("Divisível por 3\n");
  } else if (n2 % 5 == 0) {
    printf("Divisível por 5\n");
  } else {
    printf("Não é divisível por 3 nem por 5\n");
  }

  if (n3 % 3 == 0 && n3 % 5 == 0) {
    printf("Divisível por ambos\n");
  } else if (n3 % 3 == 0) {
    printf("Divisível por 3\n");
  } else if (n3 % 5 == 0) {
    printf("Divisível por 5\n");
  } else {
    printf("Não é divisível por 3 nem por 5\n");
  }

  return 0;
}