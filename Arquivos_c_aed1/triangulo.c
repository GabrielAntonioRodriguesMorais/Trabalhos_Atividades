#include <stdio.h>

int main()
{

    int lado1, lado2, lado3;

    scanf("%d %d %d", &lado1, &lado2, &lado3);

    if ((lado1 + lado2) > lado3 && (lado1 + lado3) > lado2 && (lado2 + lado3) > lado1)
    {
        if ((lado1 == lado2) && (lado1 == lado3))
        {
            printf("Triangulo equilatero");
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
        {
            printf("Triangulo isoceles");
        }
        else
        {
            printf("Triangulo escaleno");
        }
    }
    else
    {
        printf("Triangulo invalido");
    }

    return 0;
}