#include <stdio.h>

int inverter(int n)
{
    int quociente;
    if (n % 10 != 0)
    {
        quociente = n % 10;
        printf("%d", quociente);
        inverter(n / 10);
    }
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    inverter(n);
}