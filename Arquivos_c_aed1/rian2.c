#include <stdio.h>

void binario(int n)
{
    if (n > 1)
    {
        n = n / 2;
        binario(n);
    }
    printf("%d", n % 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    binario(n);
}

// 12/2
// 0 6/2
//  0 3/2
//   1 1/2
//    1
//   1 primeiro
//  1  segundo
// 0   terceiro
// 0    quarto