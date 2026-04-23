#include <stdio.h>

int main()
{
    int num;

    for (int i = 1; i > 0; i++)
    {
        scanf("%d", &num);
        if (num != 0)
        {
            if (num % 2 == 0)
            {
                printf("Par\n");
            }
            else
            {
                printf("Impar\n");
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}