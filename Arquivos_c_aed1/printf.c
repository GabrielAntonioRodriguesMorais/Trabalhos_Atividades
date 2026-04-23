#include <stdio.h>

int main() {
  int num1;
  float num2;
  scanf("%d", &num1);
  scanf("%f", &num2);
  //inteiro
  printf("Decimal: %05d\n", num1);
  printf("Hexadecimal: %x\n", num1);
  printf("Octal: %o\n", num1);
  printf("Char: %c\n", num1);
  //float
  printf("Com 6 casas decimais: %.6f\n", num2);
  printf("Com 2 casas decimais: %.2f\n", num2);
  printf("Notação científica (lower): %e\n", num2);
  printf("Notação científica (upper): %E\n", num2);
  
  return 0;
}