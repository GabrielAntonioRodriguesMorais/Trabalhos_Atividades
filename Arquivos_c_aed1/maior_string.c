#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maiorString(int n)
{
    char maior1[50] = "";
    char maior2[50] = "";
    char temp[50];
    for (int i = 0; i < n; i++)
    {
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';
        if (strlen(temp) > strlen(maior1))
        {
            strcpy(maior1, temp);
        }
        if (strcmp(temp, maior2) > 0)
        {
            strcpy(maior2, temp);
        }
    }
    printf("Saida:\n");
    printf("%s", maior1);
    printf("\n");
    printf("%s", maior2);
}

int main()
{
    int n;

    scanf("%d", &n);
    getchar();

    maiorString(n);
}