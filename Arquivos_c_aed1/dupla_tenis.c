#include <stdio.h>

void crescente(int a, int b, int c, int d)
{
  int temp;

  if (a > b)
  {
    temp = a;
    a = b;
    b = temp;
  }
  if (a > c)
  {
    temp = a;
    a = c;
    c = temp;
  }
  if (b > c)
  {
    temp = b;
    b = c;
    c = temp;
  }
  if (a > d)
  {
    temp = a;
    a = d;
    d = temp;
  }
  if (b > d)
  {
    temp = b;
    b = d;
    d = temp;
  }
  if (c > d)
  {
    temp = c;
    c = d;
    d = temp;
  }
  printf("Ordem crescente : %d %d %d %d\n", a, b, c, d);
}

void decrescente(int a, int b, int c, int d)
{
  int temp;
}

int main()
{
  int a, b, c, d, soma1, soma2, dif;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  crescente(a, b, c, d);

  soma1 = a + d;

  soma2 = b + c;

  dif = soma1 - soma2;

  printf("%d", dif);

  return 0;
}
