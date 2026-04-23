#include <stdio.h>
#include <string.h>

int soma(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
        return (n % 10) + soma(n / 10);
}

int main()
{
    int n;

    while (scanf("%d", &n) != EOF) // loop para receber entradas de um pub.in
    {
        printf("%d\n", soma(n));
    }
}