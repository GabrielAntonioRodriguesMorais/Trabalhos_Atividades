#include <stdio.h>

int main()
{
    int M, A, B, C;

    scanf("%d", &M);
    scanf("%d", &A);
    scanf("%d", &B);

    if (M >= 40 && M <= 110 && 1 <= A && A < M && 1 <= B && B < M && A != B)
    {
        C = M - (A + B);
        printf("%d", C);
    }
    else
        printf("idade invalida");

    return 0;
}
