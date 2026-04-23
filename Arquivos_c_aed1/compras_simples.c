#include <stdio.h>

int main(void)
{
  double total, valor1, valor2;
  int peca1, peca2, cod1, qnt1, cod2, qnt2;

  scanf("%d %d %lf", &cod1, &qnt1, &valor1);
  scanf("%d %d %lf", &cod2, &qnt2, &valor2);

  total = (valor1 * qnt1) + (valor2 * qnt2);

  printf("VALOR A PAGAR: R$ %.2lf", total);

  return 0;
}