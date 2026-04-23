#include <stdio.h>
#include <math.h>

int main()
{
    int x, y;
    do
    {
        scanf("%d", &x);

        if (x > -3)
        {
            y = pow(x, 3);
        }
        else if (x == -3)
        {
            y = -10;
        }
        else if (x <= -7)
        {
            y = (5 * x) + 20;
        }
        printf("y = %d\n", y);
    } while (x != 0);

    return 0;
}