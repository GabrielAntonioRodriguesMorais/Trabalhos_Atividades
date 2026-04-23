#include <stdio.h>

int main()
{
    int a, b, c, *p;
    a = 10;
    b = 20;
    c = 30;
    p = &a;

    while (c < 50)
    {
        *p = 50;
        printf("a = %d b = %d c = %d\n", a, b, c);
        printf("a = %p b = %p c = %p p = %p\n", &a, &b, &c, p);
        p++;
    }
}